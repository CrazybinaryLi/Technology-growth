class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(const auto s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it=mp.cbegin();it!=mp.cend();it++){
            if(it->second.size()>=1){
                res.push_back(it->second);
            }
        }
        return res;
    }
};
