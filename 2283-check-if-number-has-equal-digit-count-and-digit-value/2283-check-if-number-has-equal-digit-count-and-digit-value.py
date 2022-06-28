class Solution:
    def digitCount(self, num: str) -> bool:
        hashMap = dict()
        
        for n in num:
            hashMap[int(n)] = hashMap.get(int(n), 0) + 1
        
        for i in range(len(num)):
            if hashMap.get(i, 0) != int(num[i]):
                return False
        return True