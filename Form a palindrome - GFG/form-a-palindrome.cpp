// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string S) {
        string s2 = S;
        reverse(s2.begin(), s2.end());
        return S.length() - lcs(S, s2);
    }
private:
    int lcs(string s1, string s2) {
        int n = s1.length();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n][n];
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends