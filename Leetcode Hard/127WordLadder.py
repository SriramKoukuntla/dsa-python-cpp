#https://leetcode.com/problems/word-ladder/description/
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        dictionary = defaultdict(list)
        for word in wordList:
            for i in range(len(word)):
                dictionary[word[:i] + "*" + word[i+1:]].append(word)
        
        queue = deque([(beginWord, 1)])
        seen = set()
        while (queue):
            word, dist = queue.popleft()
            if word == endWord: return dist
            if word in seen: continue
            seen.add(word)
            for i in range(len(word)):
                for WORD in dictionary[word[:i] + "*" + word[i+1:]]:
                    queue.append((WORD, dist+1))
        return 0




        #BFS, but without super efficient optimization 
        # if endWord not in wordList: return 0

        # wordList = set(wordList)
        # queue = deque([(beginWord, 1)])
        # while queue:
        #     word, dist = queue.popleft()
        #     if word == endWord: return dist
        #     temp = []
        #     for word1 in wordList:
        #         counter = 0
        #         for j in range(len(beginWord)):
        #             if counter == 2: continue
        #             if word[j] != word1[j]: counter += 1
        #         if counter == 1: 
        #             queue.append(((word1), dist+1))
        #             temp.append(word1)
        #     while temp: wordList.remove(temp.pop())                
        # return 0