#include <iostream>

using namespace std;

struct TrieNode {
    TrieNode *links[26] = {NULL};
    bool flag = false;
};

class PrefixTree {
    private:
        TrieNode *root;
    public:
        PrefixTree() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode *node = root;
            for (int i = 0; i < word.size(); i++) {
                char val = word[i] - 'a';
                if (!node->links[val]) {
                    node->links[val] = new TrieNode();
                }
                node = node->links[val];
            }
            node->flag = true;
        }

        bool search(string word) {
            TrieNode *node = root;
            for (int i = 0; i < word.size(); i++) {
                char val = word[i] - 'a';
                if (!node->links[val]) {
                    return false;
                }
                node = node->links[val];
            }
            return node->flag;
        }

        bool startsWith(string prefix) {
            TrieNode *node = root;
            for (int i = 0; i < prefix.size(); i++) {
                char val = prefix[i] - 'a';
                if (!node->links[val]) {
                    return false;
                }
                node = node->links[val];
            }
            return true;
        }
};


int main()
{
    PrefixTree prefixTree;
    prefixTree.insert("dog");
    cout << prefixTree.search("dog") << endl;    // return true
    cout << prefixTree.search("do") << endl;     // return false
    cout << prefixTree.startsWith("do") << endl;; // return true
    prefixTree.insert("do");
    cout << prefixTree.search("do") << endl;     // return true

    return 0;
}
