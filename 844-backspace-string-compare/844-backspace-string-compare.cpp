class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return bruteForce(s, t);
    }
private:
    // Daily
    bool bruteForce(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        
        for(auto ch: s) {
            if(ch == '#') {
                if(!st1.empty())
                    st1.pop();
            }
            else
                st1.push(ch);
        }
        
        for(auto ch: t) {
            if(ch == '#') {
                if(!st2.empty())
                    st2.pop();
            }
            else
                st2.push(ch);
        }
        
        while(!st1.empty() && !st2.empty()) {
            if(st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }
        if(!st1.empty() || !st2.empty())
            return false;
        return true;
    }
};