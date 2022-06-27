class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return moore(nums);
        // return hashMap(nums);
        // return sorting(nums);
        // return bruteForce(nums);
    }
private:
    // O(n ^ 2) Time and O(1) extra space
    int bruteForce(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            int freq = 1;
            for(int j = i + 1; j < n; ++j) {
                if(nums[i] == nums[j])
                    freq++;
            }
            if(freq > n / 2)
                return nums[i];
        }
        return 0;        
    }
    
    
    // O(nlogn) Time and O(1) extra space
    int sorting(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        return nums[n / 2];
    }
    
    
    // O(n) Time and O(n) extra space
    int hashMap(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashMap;
        
        for(int x: nums) {
            hashMap[x]++;
            if(hashMap[x] > n / 2)
                return x;
        }
        return 0;
    }
    
    
    // O(n) Time and O(1) extra space
    int moore(vector<int>& nums) {
        int n = nums.size();
        int vote = 1;
        int candidate = nums[0];
        
        for(int i = 1; i < n; ++i) {
            if(candidate == nums[i])
                ++vote;
            else
                --vote;
            
            if(vote == 0 && i < n)
                candidate = nums[i + 1];
        }
        return candidate;
    }
};