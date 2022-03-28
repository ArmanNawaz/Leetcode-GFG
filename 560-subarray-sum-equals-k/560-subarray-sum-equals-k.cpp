class Solution {
public:
    // O(n) time and O(n) extra space
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int psum = 0;
        unordered_map<int, int> visited;
        visited[0] = 1;
        for(int i = 0; i < n; i++){
            psum += nums[i];
            count += visited[psum - k];
            visited[psum]++;
        }
        return count;
        
        
    }
};