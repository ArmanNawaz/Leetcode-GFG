// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        int m = A.length();
        int n = B.length();
        
        int x = m;
        int c = 0;
        string s = "";
        
        while(m <= n) {
            s = s + A;
            m = m + x;
            ++c;
        }
        if(s.find(B) < s.length())
            return c;
        s = s + A;
        ++c;
        if(s.find(B) < s.length())
            return c;
        else 
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends