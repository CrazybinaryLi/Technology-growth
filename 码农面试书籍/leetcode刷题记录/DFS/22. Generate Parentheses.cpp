class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        dfs(n,res,path,0,0);
        return res;
    }

private:
    void dfs(int n,vector<string>& res,string& path,int l,int r){
        if(l==n){
            string s(path);
            res.push_back(s.append(n-r,')'));
            return;
        }
        path.push_back('(');
        dfs(n,res,path,l+1,r);
        path.pop_back();
        if(l>r){
            path.push_back(')');
            dfs(n,res,path,l,r+1);
            path.pop_back();
        }
    }
};
