class Solution {
public:
    string simplifyPath(string path) {
        return solve(path);
    }
private:
    string solve(string path) {
        string curr, ans;
        stack<string> st;
        path.push_back('/');
        
        for(char c : path) {
            if(c == '/') {
                if(curr.empty())    continue;
                else if(curr == "..") {
                    if(!st.empty())   st.pop(); 
                }
                else if(curr != ".")    st.push(curr); 
                curr = "";
            }
            else
                curr.push_back(c);
        }
        
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.empty()) return "/";
        return ans;
    }
};