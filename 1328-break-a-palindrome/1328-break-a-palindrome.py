class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        
        if n == 1: return ""
        
        flag = False
        toList = list(palindrome)
        
        for i in range(n):
            if palindrome[i] != 'a' and i != n // 2:
                toList[i] = 'a'
                flag = True
                break
        
        if flag == False:
            toList[n - 1] = 'b'
        
        return ''.join(toList)