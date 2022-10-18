class Solution {
public:
    string countAndSay(int n) {
        return recurse(n);
    }
private:
    string recurse(int n) {
        if(n == 1) 
            return "1";
        
        string currAns = recurse(n - 1);
        int count = 1;
        string ans = "";
        
       for(int i = 0; i < currAns.length() - 1; ++i) {
           if(currAns[i] == currAns[i + 1])
               ++count;
           else {
               ans += (count + '0');
               ans += currAns[i];
               count = 1;
           }
        }
        int len = currAns.length();
        if(len >= 2) {
            if(currAns[len - 1] == currAns[len - 2]) {
                ans += (count + '0');
                ans += currAns[len - 1];
            }
            else {
                ans += '1';
                ans += currAns[len - 1];
            }
        }
        if(len == 1) {
            ans += '1';
            ans += currAns[0];
        }
        
        return ans;
    }
};