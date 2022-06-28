class Solution:
    #User function Template for python3
    
    # arr[]: Input Array
    # N : Size of the Array arr[]
    #Function to count inversions in the array.
    
        
    def merge(self, arr, low, mid, high):
        n1 = mid - low + 1
        n2 = high - mid
        
        l = [0] * n1
        r = [0] * n2
        
        for i in range(n1):
            l[i] = arr[low + i]
            
        for i in range(n2):
            r[i] = arr[mid + i + 1]
            
        
        i, j, k = 0, 0, low
        
        while i < n1 and j < n2:
            if l[i] <= r[j]:
                arr[k] = l[i]
                i += 1
            else:
                arr[k] = r[j]
                j += 1
                self.inversion_count += n1 - i
            k += 1
        while i < n1:
            arr[k] = l[i]
            i += 1
            k += 1
            
        while j < n2:
            arr[k] = r[j]
            j += 1
            k += 1
           
        
    def mergeSort(self, arr, low, high):
        if low < high:
            mid = low + (high - low) // 2
            
            self.mergeSort(arr, low, mid)
            self.mergeSort(arr, mid + 1, high)
            self.merge(arr, low, mid, high)
    
    def inversionCount(self, arr, n):
        self.inversion_count = 0
        self.mergeSort(arr, 0, n - 1)
        return self.inversion_count

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for tt in range(t):
        n = int(input())
        a = list(map(int, input().strip().split()))
        obj = Solution()
        print(obj.inversionCount(a,n))
# } Driver Code Ends