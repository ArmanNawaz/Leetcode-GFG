class Solution {
public:
    string convert(string s, int numRows) {
        return solve(s, numRows);
    }
private:
    // Self
    string solve(string& s, int numRows) {
        if(numRows <= 1) return s;
        vector<vector<char>> res(numRows, vector<char>(1001));
        
        int dir = 1;
        int i = 0, j = 0;
        
        for(auto ch: s) {
            res[i][j] = ch;
            
            i += dir;
            
            // Changing the direction to upwards/downwards
            if(i == numRows){
                i -= 2;
                dir *= -1;
            }
            else if(i == -1) {
                i += 2;
                dir *= -1;
            }
            // if(i < 0) i = 0;
            // If direction is upward then change column
            if(dir == -1)
                ++j;
        }
        // for(auto x: res) {
        //     for(auto y: x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // } 
        string ans = "";
        for(auto row: res) {
            for(auto ch: row) {
                if(isalpha(ch) || ch == ',' || ch == '.')
                    ans += ch;
            }
        }
        return ans;
    }
};