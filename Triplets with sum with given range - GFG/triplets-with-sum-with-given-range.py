#User function Template for python3

class Solution:
    def solve(self, arr, target):
        count = 0
        n = len(arr)
        for i in range(n):
            j = i + 1
            k = n - 1
            
            while j < k:
                _sum = arr[i] + arr[j] + arr[k]
                if _sum <= target:
                    count += k - j
                    j += 1
                else:
                    k -= 1
        return count
        
    
    def countTriplets(self, Arr, N, L, R):
        Arr.sort()
        x = self.solve(Arr, R)
        y = self.solve(Arr, L - 1)
        return x - y

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        N = int(input())
        Arr = input().split()
        for itr in range(N):
            Arr[itr] = int(Arr[itr])
        L,R = input().split()
        L=int(L)
        R=int(R)
        ob = Solution()
        print(ob.countTriplets(Arr, N, L, R))
# } Driver Code Ends