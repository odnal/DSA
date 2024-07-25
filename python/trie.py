# trie implementation: prefix tree - (insert/search functions)

class TrieNode():
    def __init__(self):
        self.links = [None] * 26
        self.flag = False

class PrefixTree:

    def __init__(self):
        self.root = TrieNode() 

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            val = ord(c) - ord('a')
            if node.links[val] == None:
                node.links[val] = TrieNode()
            node = node.links[val]
        node.flag = True
        
    def search(self, word: str) -> bool:
        node = self.root
        #print(node.links)
        for c in word:
            val = ord(c) - ord('a')
            if node.links[val] == None:
                return False
            node = node.links[val]
        return node.flag

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for c in prefix:
            val = ord(c) - ord('a')
            if node.links[val] == None:
                return False
            node = node.links[val]
        return True


if __name__ == "__main__":

    prefixTree = PrefixTree()
    prefixTree.insert("dog")
    print(prefixTree.search("dog"))    # return true
    print(prefixTree.search("do"))    # return false
    print(prefixTree.startsWith("do")) # return true
    prefixTree.insert("do")
    print(prefixTree.search("do"))     # return true
