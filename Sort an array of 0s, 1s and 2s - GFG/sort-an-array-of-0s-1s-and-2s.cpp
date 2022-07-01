// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n) {
        int at1 = 0, at0 = 0, at2 = n - 1;
        
        while(at1 <= at2) {
            if(a[at1] == 0) {
                swap(a[at1++], a[at0++]);
            }
            else if(a[at1] == 2)
                swap(a[at1], a[at2--]);
            else
                at1++;
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends