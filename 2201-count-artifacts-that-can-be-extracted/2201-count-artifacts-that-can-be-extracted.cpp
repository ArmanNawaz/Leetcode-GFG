class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        return solve(n, artifacts, dig);
    }
private:
    // Aakash sir
    int solve(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        set<pair<int, int>> digSet;
        
        // Make set for given pairs to have a constant lookup for any pair
        for(auto each: dig) {
            digSet.insert({each[0], each[1]});
        }
        
        int ans = 0;
        
        // iterate through given artifacts
        for(auto points: artifacts) {
            
            // assume that complete cell can be visited
            bool completeVisit = true;
            
            // iterate through every rectangle for each artifact
            for(int x = points[0]; x <= points[2]; ++x) {
                for(int y = points[1]; y <= points[3]; ++y) {
                    
                    // if any cell in the rectangle cannot be visited
                    // then break immediately
                    if(digSet.find({x, y}) == digSet.end()) {
                        completeVisit = false;
                        break;
                    }
                }
            }
            // if the artifact rectangle can be completely visited
            if(completeVisit)
                ++ans;
        }
        return ans;
    }
};