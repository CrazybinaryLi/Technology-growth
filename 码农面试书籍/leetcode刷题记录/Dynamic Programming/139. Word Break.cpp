class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n=s.size();
        if(wordDict.size()==0) return n==0;
        vector<bool> f(n,false);
        string tmp="";
        tmp+=s[0];
        f[0]=find(wordDict.begin(),wordDict.end(),tmp)!=wordDict.end()?true:false;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                string tmp=s.substr(j+1,i-j);
                if(f[j]&&find(wordDict.begin(),wordDict.end(),tmp)!=wordDict.end()){
                    f[i]=true;
                    break;
                }
            }
            if(find(wordDict.begin(),wordDict.end(),s.substr(0,i+1))!=wordDict.end()) f[i]=true;//判断全字符串
        }
        return f[n-1];
    }
};
