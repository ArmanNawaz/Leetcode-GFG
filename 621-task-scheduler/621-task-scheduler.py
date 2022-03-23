class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        hashMap = dict()
        
        for task in tasks:
            hashMap[task] = hashMap.get(task, 0) + 1
        
        sortedItems = sorted(hashMap.values())
        
        maxFreq = sortedItems[-1]
        idleTime = (maxFreq - 1) * n
        
        for i in range(len(sortedItems)-2, -1, -1):
            idleTime -= min(sortedItems[i], maxFreq - 1)
            
        idleTime = max(0, idleTime)
        
        return len(tasks) + idleTime
        