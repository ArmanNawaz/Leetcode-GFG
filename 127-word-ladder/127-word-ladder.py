class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        
        wordSet = set(wordList)
        
        if endWord not in wordSet:
            return 0
        
        if beginWord in wordSet:
            wordSet.remove(beginWord)
        
        queue = deque()
        queue.append(beginWord)
        count = 0
        
        while queue:
            count += 1
            levelSize = len(queue)
            
            for i in range(levelSize):
                currWord = queue.popleft()
                
                for j in range(len(currWord)):
                    for char in ascii_lowercase:
                        temp = currWord[: j] + char + currWord[j+1: ]
                        if temp in wordSet:
                            queue.append(temp)
                            if temp == endWord:
                                return count + 1
                            wordSet.remove(temp)
        return 0
                    
        