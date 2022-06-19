class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        return daily1(products, searchWord);
    }
private:
    bool match(string word1, string word2) {
        int i = 0, j = 0;
        
        while(i < word1.length() && j < word2.length()) {
            if(word1[i] != word2[j])
                return false;
            ++i;
            ++j;
        }
        return true;
    }
    
    vector<vector<string>> daily(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans;
        string word = "";
        
        for(char ch: searchWord) {
            word += ch;
            vector<string> eachSearch;
            for(auto pro: products) {
                if(match(word, pro))
                    eachSearch.push_back(pro);
                if(eachSearch.size() >= 3)
                    break;
            }
            ans.push_back(eachSearch);
        }
        
        return ans;
    }
    
    vector<vector<string>> daily1(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        unordered_map<string, vector<string>> hashMap;
        
        for(auto pro: products) {
            string word = "";
            for(char ch: pro) {
                word += ch;
                hashMap[word].push_back(pro);
            }
        }
        // for(auto x: hashMap["m"])
        // cout<<x<<endl;
        
        vector<vector<string>> ans;
        string word = "";
        for(char ch: searchWord) {
            word += ch;
            if(hashMap[word].size() > 3)
                ans.push_back({hashMap[word][0], hashMap[word][1], hashMap[word][2]});
            else
                ans.push_back(hashMap[word]);
        }
        
        
        
        return ans;
    }
};