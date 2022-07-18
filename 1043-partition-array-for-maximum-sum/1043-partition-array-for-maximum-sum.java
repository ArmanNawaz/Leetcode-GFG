class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];
        dp[0] = arr[0];
        for(int i = 1; i < n; ++i) {
            int maxEle = arr[i];
            for(int j = i; j >= Math.max(0, i - k + 1); --j) {
                maxEle = Math.max(maxEle, arr[j]);
                int winSize = i - j + 1;
                if(j > 0)
                    dp[i] = Math.max(dp[i], maxEle * winSize + dp[j - 1]);
                else
                    dp[i] = Math.max(dp[i], maxEle * winSize);
            }
        }
        return dp[n - 1];
    }
}