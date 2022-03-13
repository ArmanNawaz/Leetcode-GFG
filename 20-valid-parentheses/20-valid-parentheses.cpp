class Solution {
public:
    bool isValid(string s) {
        return solve(s);
    }
private:
    bool solve(string s){
        stack<char> st;
        
        for(char c: s){
            if(c == '(' or c == '{' or c == '[')
                st.push(c);
            else if(!st.empty() and st.top() == '(' and c == ')') st.pop();
            else if(!st.empty() and st.top() == '{' and c == '}') st.pop();
            else if(!st.empty() and st.top() == '[' and c == ']') st.pop();
            else return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};