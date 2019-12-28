class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s,res,path,0);
        return res;
    }

private:
    void dfs(string s,vector<vector<string>>& res,vector<string>& path,int start){
        if(start==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                path.push_back(s.substr(start,i-start+1));
                dfs(s,res,path,i+1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int start,int end){
        while(start<end&&s[start]==s[end]){
            ++start;
            --end;
        }
        return start>=end;
    }
};
