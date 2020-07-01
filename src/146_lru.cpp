#include <memory>
#include <list>
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
	int capacity_;
	typedef list<pair<int,int>> Node;
	Node lru_; // 存放 key, value
	unordered_map<int, Node::iterator> map_; // 存放 key 以及节点地址
public:
	LRUCache(int capacity) : map_(capacity), capacity_(capacity) {}

	int get(int key) {
		auto i = map_.find(key);
		if (i != map_.end())
		{
			auto e = i->second;;
			int value = e->second;
			if (lru_.begin() != e)
			{
				lru_.splice(lru_.begin(), lru_, e, next(e));
				map_[key] = lru_.begin();
			}
			return value;
		}

		return -1;
	}

	void put(int key, int value) {
		if (capacity_ <= 0) {
			return;
		}

		auto i = map_.find(key);
		if (i != map_.end()) {
			auto e = i->second;
			if (e != lru_.begin())
			{
				lru_.splice(lru_.begin(), lru_, e, next(e));
			}
			lru_.begin()->second = value;
		}
		else {
			if (map_.size() >= capacity_) {
				int lastKey = lru_.back().first;
				lru_.pop_back();
				map_.erase(lastKey);
			}
			lru_.push_front(make_pair(key, value));
		}

		map_[key] = lru_.begin();
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(int argc, char *argv[])
{
	LRUCache *cache = new LRUCache(3);

	cache->put(2, 1);
	cache->put(2, 2);

	cout << cache->get(1) << endl;       // 返回  1
	cache->put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache->get(2) << endl;       // 返回 -1 (未找到)
	cache->put(4, 4);    // 该操作会使得密钥 1 作废
	cache->put(2, 10);
	cout << cache->get(2) << endl;       // 返回 -1 (未找到)
	cout << cache->get(2) << endl;       // 返回 -1 (未找到)
	cache->put(3, 4);    // 该操作会使得密钥 1 作废
	cout << cache->get(2) << endl;       // 返回 -1 (未找到)
	cout << cache->get(3) << endl;       // 返回 -1 (未找到)
	cache->put(10, 4);    // 该操作会使得密钥 1 作废
	cout << cache->get(3) << endl;       // 返回 -1 (未找到)

	delete cache;

	return 0;
}
