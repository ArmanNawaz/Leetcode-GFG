class Solution:
    def solve(self, digits, idx, hashMap, partialAns, ans):
   # base case
        if idx >= len(digits):
            # Append the current partial ans to ans
            # here len(partialAns) == len(digits)
            ans.append(''.join(partialAns))
            return
        
        # iterate through each character of the digit
        for char in hashMap[digits[idx]]:
            partialAns.append(char)  # use the current character
            self.solve(digits, idx + 1, hashMap, partialAns, ans)  # move to the next digit

            partialAns.pop()    # Backtracking step

    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        hashMap = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs',
                  '8': 'tuv', '9': 'wxyz'}

        # to store partial answer until we found complete answer
        partialAns = []
        ans = []
        self.solve(digits, 0, hashMap, partialAns, ans)
        return ans
  