// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n) {
    vector<int> ans;
    set<int> st;
    
    st.insert(-1);
    st.insert(arr[0]);
    ans.push_back(-1);
    
    
    for(int i = 1; i < n; ++i) {
        st.insert(arr[i]);
        
        auto x = st.find(arr[i]);
        x--;
        
        ans.push_back(*x);
    }
    return ans;
}