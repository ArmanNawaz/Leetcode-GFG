class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1, nums2);
    }
private:
    double solve(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return solve(nums2, nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        int low = 0, high = n1;
        int req = (n1 + n2 + 1) / 2;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cut1 = mid;
            int cut2 = req - mid;
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) % 2 != 0)
                    return max(l1, l2);
                
                double res = max(l1, l2) + min(r1, r2);
                return res / 2;
            }
            if(l1 > r2) {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return 0.0;
    }
};