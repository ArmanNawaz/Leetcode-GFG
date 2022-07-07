// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum) {
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
private:
    bool solve(vector<int> nums, int target, int ind, vector<vector<int>>& dp) {
        
        if(ind >= nums.size() || target <= 0) {
            if(target == 0)
                return true;
            return false;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool pick = solve(nums, target - nums[ind], ind + 1, dp);
        bool notPick = solve(nums, target, ind + 1, dp);
        return dp[ind][target] = pick || notPick;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends