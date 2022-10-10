class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.length() == 1) return "";
        
        int n = palindrome.length();
        bool flag = false;
        
        for(int i = 0; i < n; ++i) {
            if(palindrome[i] != 'a' && i != n / 2) {
                palindrome[i] = 'a';
                flag = true;
                break;
            }
        }
        if(flag == false) {
            palindrome[n - 1] = 'b';
        }
        return palindrome;
    }
};