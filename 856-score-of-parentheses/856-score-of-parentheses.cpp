class Solution {
public:
    int scoreOfParentheses(string s) {
        return solve(s);
    }
private:
    int solve(string s){
        stack<int> st;
        int score = 0;
        
        for(char ch: s){
            if(ch == '('){
                st.push(-1);
            }
            else{
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int value = 0;
                    while(st.top() != -1){
                        value += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(value*2);
                }
            }
        }
        while(!st.empty()){
            score += st.top();
            st.pop();
        }
        
        return score;
    }
};