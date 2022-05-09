class Solution {
public:
    vector<string> hashMap = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        return solve(digits);
    }
private:
    void backtrack(string& digits, int idx, string& partialAns, vector<string>& ans) {
        // Base case
        if(idx >= digits.length()) {
            // here we have length of partialAns == length of digits
            ans.push_back(partialAns); 
            return;
        }
        
        // iterate through each character of current digit
        for(auto ch: hashMap[digits[idx] - '2']) {
            partialAns.push_back(ch); // append the current character to partial ans
            backtrack(digits, idx + 1, partialAns, ans); // solve for next index
            partialAns.pop_back();  // backtracking step
        }
    }
    
    vector<string> solve(string& digits) {
        if(digits.length() == 0)
            return {};
        
        
        string partialAns = "";
        vector<string> ans;
        
        backtrack(digits, 0, partialAns, ans);
        return ans;
    }
};