//dp+dfs
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> f(s.length()+1,false);//f[i]表示s[0...i)在字典中
        vector<vector<bool>> prev(s.length(),vector<bool>(s.length()+1,false));//prev[j][i]表示s[j...i)在字典中，可以从j处切开。
        f[0]=true;//空串
        for(size_t i=1;i<=s.length();i++){
            for(size_t j=0;j<=i-1;j++){
                if(f[j]&&find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                    f[i]=true;
                    prev[j][i]=true;//可以从j处断开
                }
            }
        }
        vector<string> result;
        if(!f[s.length()]) return result;
        vector<string> path;
        gen_path(s,prev,0,path,result);
        return result;
    }

private:
    static void gen_path(const string& s,const vector<vector<bool>>& prev,int b,vector<string>& path,vector<string>& result){
        if(b==s.size()){
            string tmp="";
            for(auto iter=path.cbegin();iter!=path.cend();iter++){
                tmp+=(*iter+" ");
            }
            tmp.erase(tmp.end()-1);
            result.push_back(tmp);
            return;
        }
        for(size_t i=b+1;i<=s.size();i++){
            if(prev[b][i]){
                path.push_back(s.substr(b,i-b));
                gen_path(s,prev,i,path,result);
                path.pop_back();
            }
        }
    }
};
