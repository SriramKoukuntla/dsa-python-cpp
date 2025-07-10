#https://leetcode.com/problems/design-add-and-search-words-data-structure/
from collections import deque
class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        current = self.root
        for char in word:
            if char not in current.children:
                current.children[char] = TrieNode()
            current = current.children[char]
        current.word = True

    def search(self, word: str) -> bool:
        current = self.root
        return self.dfs(current, word)            

    def dfs(self, current, word):
        current = current
        for i in range(len(word)):
            char = word[i]
            if char == ".":
                for char in current.children:
                    if (self.dfs(current.children[char], word[i+1:len(word)])):
                        return True
                return False
            else:
                if char not in current.children:
                    return False
                current = current.children[char]
        return current.word




# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)