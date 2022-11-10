/* Rbtree with unique_ptr */
#include <stdio.h>

#include <cerrno>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <utility>
#include <optional>

template <class K, class V>
class Rbtree
{
public:
    using walk_cb = std::function<void(const K &, const V &, bool left, bool red)>;

private:
    class Rbnode
    {
    public:
        Rbnode *left, *right, *parent;
        K key;
        V value;
        bool red;

        Rbnode() : left(nullptr), right(nullptr), parent(nullptr) {}
        Rbnode(K &&k, V &&v)
            : left(nullptr),
              right(nullptr),
              parent(nullptr),
              key(std::forward<K>(k)),
              value(std::forward<V>(v)),
              red(true)
        {
        }
        Rbnode(const K &k, const V &v)
            : left(nullptr),
              right(nullptr),
              parent(nullptr),
              key(k),
              value(v),
              red(true)
        {
        }
    };

    Rbnode *mRoot;

    void left_rotate(Rbnode *node);
    void right_rotate(Rbnode *node);
    void change_child(Rbnode *node, Rbnode *ochild, Rbnode *nchild);
    void rebalance(Rbnode *node);

    void walk_node(const walk_cb &cb, Rbnode *node, bool left, bool red)
    {
        if (node != nullptr) {
            cb(node->key, node->value, left, node->red);
            walk_node(cb, node->left, true, node->red);
            walk_node(cb, node->right, false, node->red);
        }
    }

    void walk_node_destruct(Rbnode *node)
    {
        if (node != nullptr) {
            walk_node_destruct(node->left);
            walk_node_destruct(node->right);
            delete node;
        }
    }

public:
    Rbtree() : mRoot(nullptr) {}
    ~Rbtree() { walk_node_destruct(mRoot); }
    void insert(K &&k, V &&v);
    void insert(const K &k, const V &v);
    std::optional<V&> search(const K &);

    void walk(const walk_cb &cb) { walk_node(cb, mRoot, false, mRoot->red); }
};

template <class K, class V>
void Rbtree<K, V>::change_child(Rbnode *node, Rbnode *ochild, Rbnode *nchild)
{
    Rbnode *left = node->left;
    if (left == ochild) {
        node->left = nchild;
    } else {
        node->right = nchild;
    }
}

template <class K, class V>
std::optional<V&> Rbtree<K, V>::search(const K &k)
{
    Rbnode *p = mRoot;
    while (p) {
        if (p->key > k) {
            p = p->left;
        } else if (p->key < k) {
            p = p->right;
        } else if (p->key == k) {
            return std::optional(&p->value);
        }
    }
    return std::nullopt;
}

template <class K, class V>
void Rbtree<K, V>::left_rotate(Rbnode *node)
{
    Rbnode *rchild = node->right;

    if (rchild == nullptr) {
        std::cout << "rchild is null: " << node->key << std::endl;
        exit(1);
    }

    Rbnode *parent = node->parent;
    if (parent != nullptr) {
        change_child(parent, node, rchild);
    } else {
        mRoot = rchild;
        mRoot->parent = nullptr;
    }

    Rbnode *tmp = rchild->left;
    if (tmp != nullptr) {
        tmp->parent = node;
    }
    rchild->left = node;
    node->right = tmp;
}

template <class K, class V>
void Rbtree<K, V>::right_rotate(Rbnode *node)
{
    Rbnode *lchild = node->left;

    if (lchild == nullptr) {
        std::cout << "lchild is null: " << node->key << std::endl;
        exit(1);
    }

    Rbnode *parent = node->parent;
    if (parent != nullptr) {
        change_child(parent, node, lchild);
    } else {
        mRoot = lchild;
        mRoot->parent = nullptr;
    }

    Rbnode *tmp = lchild->right;
    if (tmp != nullptr) {
        tmp->parent = node;
    }
    lchild->right = node;
    node->left = tmp;
}

template <class K, class V>
void Rbtree<K, V>::insert(const K &k, const V &v)
{
    Rbnode *node, **p = &mRoot;
    while (*p) {
        node = *p;
        if (node->key > k) {
            p = &node->left;
        } else if (node->key < k) {
            p = &node->right;
        } else if (node->key == k) {
            node->value = std::move(v);
            return;
        }
    }
    Rbnode *new_node = new Rbnode(k, v);
    new_node->parent = node;
    *p = new_node;

    rebalance(new_node);
}

template <class K, class V>
void Rbtree<K, V>::insert(K &&k, V &&v)
{
    Rbnode *node, **p = &mRoot;
    while (*p) {
        node = *p;
        if (node->key > k) {
            p = &node->left;
        } else if (node->key < k) {
            p = &node->right;
        } else if (node->key == k) {
            node->value = std::move(v);
            return;
        }
    }
    Rbnode *new_node = new Rbnode(std::forward<K>(k), std::forward<V>(v));
    new_node->parent = node;
    *p = new_node;

    rebalance(new_node);
}

template <class K, class V>
void Rbtree<K, V>::rebalance(Rbnode *new_node)
{
    Rbnode *node = new_node;
    while (true) {
        Rbnode *parent = node->parent;
        if (nullptr == parent) {
            node->parent = nullptr;
            node->red = false;
            break;
        }

        if (!parent->red) {
            break;
        }

        // if parent is red, it must have gparent
        Rbnode *gparent = parent->parent;

        Rbnode *tmp = gparent->left;
        if (tmp == parent) {  // L
            Rbnode *uncle = gparent->right;
            if (nullptr != uncle && uncle->red) {
                parent->red = false;
                uncle->red = false;
                gparent->red = true;
                node = gparent;
                continue;
            }

            // LR: left rotate parent
            if (node == parent->right) {
                left_rotate(parent);
            }

            // LL：right rotate gparent, swap G's and P's color
            parent->red = false;
            gparent->red = true;
            right_rotate(gparent);
            break;

        } else {  // R
            Rbnode *uncle = tmp;
            if (nullptr != uncle && uncle->red) {
                parent->red = false;
                uncle->red = false;
                gparent->red = true;
                node = gparent;
                continue;
            }

            // RL: right rotate parent
            if (node == parent->left) {
                right_rotate(parent);
            }

            // RR: left rotate gparent, swap G's and P's color
            parent->red = false;
            gparent->red = true;
            left_rotate(gparent);
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    Rbtree<int, int> tree;
    int arr[][2] = {
        {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {100, 2}, {30, 2}, {50, 2},
    };
    for (auto i : arr) {
        int a = i[0], b = i[1];
        tree.insert(a, b);
    }

    bool root = true;
    tree.walk([&](const int &k, const int &v, bool left, bool red) -> void {
        const char *name = root ? "root" : (left ? "left" : "right");
        printf("key: %d, value: %d, %s, %s\n", k, v, name, red ? "red" : "black");
        root = false;
    });
    return 0;
}
