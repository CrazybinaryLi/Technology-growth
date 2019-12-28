//动态规划的方法
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen=1;
        int begin=0,end=0;
        bool f[1000][1000];
        memset(f,0,sizeof(f));
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(i==j) f[i][j]=true;
                else if(j==i+1) {
                    f[i][j]=(s[i]==s[j]);
                }
                else{
                    f[i][j]=((s[i]==s[j])&&(f[i+1][j-1]));
                }
                if(j-i+1>maxlen&&f[i][j]){
                    begin=i;
                    end=j;
                    maxlen=(end-begin+1);
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};

