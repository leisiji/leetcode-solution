#include <string>
#include <iostream>
using namespace std;

class Trie {
private:
	Trie *nodes[26];
	bool isEnd;
public:
	/** Initialize your data structure here. */
	Trie() : isEnd(false) {
		for (int i = 0; i < sizeof(nodes) / sizeof(nodes[0]); ++i) {
			nodes[i] = nullptr;
		}
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		auto tmp = nodes;
		int index;
		Trie *last = nullptr;

		for (auto i : word) {
			index = i - 'a';
			if (tmp[index] == nullptr) {
				tmp[index] = new Trie();
			}
			last = tmp[index];
			tmp = tmp[index]->nodes;
		}

		if (last != nullptr) {
			last->isEnd = true;
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		auto tmp = nodes;
		int index = 0;
		Trie *last = nullptr;

		if (word.size() == 0) {
			return false;
		}

		for (auto i : word) {
			int index = i - 'a';
			if (tmp[index] == nullptr) {
				return false;
			}
			last = tmp[index];
			tmp = tmp[index]->nodes;
		}

		return last->isEnd;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		auto tmp = nodes;

		if (prefix.size() == 0) {
			return false;
		}

		for (auto i : prefix) {
			int index = i - 'a';
			if (tmp[index] == nullptr) {
				return false;
			}
			tmp = tmp[index]->nodes;
		}

		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main(int argc, char *argv[])
{
	Trie t;
	t.insert("a");
	t.insert("aa");
	t.insert("ab");
	t.insert("abc");
	t.insert("bb");
	t.insert("dsadasdsadasdasdasdasd");
	cout << t.search("aa") << endl;
	cout << t.search("dsadasdsadasdasdasdasd") << endl;
	return 0;
}
