// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution {
    vector<int> bruteforce(vector<vector<int>>& arr, int n) {
        vector<int> ans;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ans.push_back(arr[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> mergeTwo(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<int> merged(n1 + n2);
        
        int i = 0, j = 0, k = 0;
        while(i < n1 && j < n2) {
            if(arr1[i] <= arr2[j])
                merged[k++] = arr1[i++];
            else
                merged[k++] = arr2[j++];
        }
        
        while(i < n1)
            merged[k++] = arr1[i++];
        while(j < n2) 
            merged[k++] = arr2[j++];
        
        
        return merged;
    }
    
    vector<int> merge(vector<vector<int>>& arr, int k) {
        if(k == 1)
            return arr[0];
        
        vector<int> tmp;
        for(int i = 0; i < k; ++i) {
            tmp = mergeTwo(arr[i], tmp);
        }
        return tmp;
    }
    
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        return merge(arr, K);
        // return bruteforce(arr, K);
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends