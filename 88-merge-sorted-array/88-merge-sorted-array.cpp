class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        solve(nums1, m, nums2, n);
    }
private:
    void solve(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
            return;
        }
        if(n == 0)
            return;
        
        int i = m - 1;
        int j = n - 1;
        int l = n + m - 1;
        
        while(j >= 0 && i >= 0) {
            if(nums1[i] > nums2[j]) {
                swap(nums1[i], nums1[l]);
                --l;
                --i;
            }
            else {
                nums1[l] = nums2[j];
                --l;
                --j;
            }
        }
        
        while(l >= 0 && j >= 0) {
            nums1[l--] = nums2[j--];
        }
            
    }
};