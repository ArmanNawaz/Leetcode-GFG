// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        return solve(S1, S2);
    }
private:
    int solve(string s1, string s2) {
        unordered_map<char, int> hashMap;
        
        for(int i = 0; i < s1.length(); ++i) {
            hashMap[s1[i]] = i;
        }
        
        int ans = 0;
        int currIdx = 0;
        
        for(char ch: s2) {
            ans += abs(currIdx - hashMap[ch]);
            currIdx = hashMap[ch];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends