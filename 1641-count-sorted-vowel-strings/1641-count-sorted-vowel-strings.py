class Solution:
    def recurse(self, n, idx):
        # Base case
        
        # if n characters are included or no more character are left
        if idx >= 5 or n == 0:
            if n == 0:
                self.count += 1
            return
        
        # Include current character and move with next set of string - "aeiou"
        # idx is not incremented as we can include the same character again
        self.recurse(n - 1, idx)
        
        # Leave the current character and move for next
        self.recurse(n, idx + 1)
        
    def countVowelStrings(self, n: int) -> int:
        self.count = 0
        
        self.recurse(n, 0)
        
        return self.count