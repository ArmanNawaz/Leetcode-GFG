class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        return solve(arr, target);
    }
private:
    int solve(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        long long int mod = 1e9 + 7;
        
        for(int i = 0; i < arr.size() - 2; ++i) {
            int j = i + 1;
            int k = arr.size() - 1;
            
            while(j < k) {
                
                int sum = arr[i] + arr[j] + arr[k];
                
                if(sum < target)
                    ++j;
                
                else if(sum > target)
                    --k;
                
                else{
                    int count1 = 1;
                    int count2 = 1;
                    
                    while(j < k and arr[j] == arr[j + 1]) {
                        ++count1;
                        ++j;
                    }
                    while(j < k and arr[k] == arr[k - 1]) {
                        ++count2;
                        --k;
                    }
                    
                    if(j == k) {
                        ans = ans + (count1 * (count1 - 1) / 2) % mod;
                        ans = ans % mod;
                    }
                    else {
                        ans = ans + (count1 * count2) % mod;
                        ans = ans % mod;
                    }
                    ++j;
                    --k;
                }
            }
        }
        return ans;
    }
};