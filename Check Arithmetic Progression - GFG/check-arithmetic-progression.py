#User function Template for python3


class Solution:
    
    def checkIsAP(self, arr, n):
        first_min, second_min = float('inf'), float('inf')
        
        for num in arr:
            if num < first_min:
                second_min = first_min
                first_min = num
            else:
                second_min = min(second_min, num)
        
        cd = second_min - first_min
        
        for num in arr:
            num -= first_min
            
            if cd != 0:
                if num % cd != 0:
                    return False
            else:
                if num != 0:
                    return False
        
        
        return True
        
        
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3


#Initial Template for Python 3


t=int(input())
for _ in range(0,t):
    n=int(input())
    # l=list(map(int,input().split()))
    # n=l[0]
    # x=l[1]
    # y=l[2]
    a = list(map(int,input().split()))
    ob = Solution()
    ans=ob.checkIsAP(a,n)
    if(ans==True):
        print("YES")
    else:
        print("NO")
# } Driver Code Ends