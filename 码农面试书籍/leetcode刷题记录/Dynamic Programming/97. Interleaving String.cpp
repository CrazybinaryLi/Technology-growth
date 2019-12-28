class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        if(s1.size()<s2.size()) isInterleave(s2,s1,s3);//s1.size()>s2.size()
        vector<bool> f(s2.size()+1,true);
        for(int j=1;j<=s2.size();j++){
            f[j]=(s2[j-1]==s3[j-1]&&f[j-1]);
        }
        for(int i=1;i<=s1.size();i++){
            f[0]=(s1[i-1]==s3[i-1]&&f[0]);
            for(int j=1;j<=s2.size();j++){
                f[j]=(s1[i-1]==s3[i+j-1]&&f[j])||(s2[j-1]==s3[i+j-1]&&f[j-1]);
            }
        }
        return f[s2.size()];
    }
};
