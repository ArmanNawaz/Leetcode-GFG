//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    bool checkIsAP(int arr[], int n) {
        sort(arr, arr + n);
        
        int cd = arr[1] - arr[0];
        
        for(int i = 2; i < n; ++i) {
            if(arr[i] - arr[i - 1] != cd) return false;
        }
        
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
         (ob.checkIsAP(arr, n))? (cout << "YES" << endl) :
                       (cout << "NO" << endl);   
    }
 
  return 0;
}

// } Driver Code Ends