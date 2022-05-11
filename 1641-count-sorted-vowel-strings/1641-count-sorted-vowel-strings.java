class Solution {
    public static int recurse(int n, int idx) {
        if(idx >= 5 || n == 0) {
            if(n == 0)
                return 1;
            return 0;
        }
        return recurse(n - 1, idx) + recurse(n, idx + 1);
    }
    public int countVowelStrings(int n) {
        return recurse(n, 0);
    }
}