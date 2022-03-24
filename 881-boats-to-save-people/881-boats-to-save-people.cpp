class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        return solve(people, limit);
    }
private:
    int solve(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int count = 0;
        int i = 0, j = people.size() - 1;
        
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                ++i;
                --j;
            }
            else
                --j;
            ++count;
        }
        return count;
    }
};