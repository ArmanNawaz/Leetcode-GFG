class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        if(n1 > n2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        low, high = 0, n1
        req = (n1 + n2 + 1) // 2
        
        while low <= high:
            mid = low + (high - low) // 2
            cut1 = mid
            cut2 = req - cut1
            
            l1 = -float('inf') if cut1 == 0 else nums1[cut1 - 1]
            l2 = -float('inf') if cut2 == 0 else nums2[cut2 - 1]
            
            r1 = float('inf') if cut1 == n1 else nums1[cut1]
            r2 = float('inf') if cut2 == n2 else nums2[cut2]
            
            if l1 <= r2 and l2 <= r1:
                if (n1 + n2) % 2 == 0:
                    return (max(l1, l2) + min(r1, r2)) / 2
                return max(l1, l2)
            if l1 > l2:
                high = mid - 1
            else:
                low = mid + 1
        return 0.0