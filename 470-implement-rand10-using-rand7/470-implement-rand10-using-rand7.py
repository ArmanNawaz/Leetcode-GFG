# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
#         n = 7 * (rand7() - 1) + (rand7() - 1)
        
#         if n < 40:
#             return (n % 10) + 1
        
#         return rand10()

        while True:
            n = 7 * (rand7() - 1) + (rand7() - 1)

            if n < 40:
                return (n % 10) + 1
        