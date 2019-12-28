class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        string path="";
        dfs(digits,res,path,0);
        return res;
    }

private:
    const vector<string> mp{""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string& digits,vector<string>& res,string path,int cur){
        if(cur==digits.size()){
            res.push_back(path);
            return;
        }
        for(auto c:mp[digits[cur]-'0']){
            dfs(digits,res,path+c,cur+1);
        }
    }
};
