//dp[i]表示到s[i]为止的解码方案总数，则这道题类似于爬楼梯那道题:dp[i]=num<=26?dp[i-2]+dp[i-1]:dp[i-1]。
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0||s[0]=='0') return 0;
        const int n=s.size();
        vector<int> dp(n+5);
        dp[0]=1;
        int num;
        for(int i=1;i<n;i++){
            if(i==1){
                if(s[i]=='0'){
                    num=(s[i-1]-'0')*10+s[i]-'0';
                    if(num<=26) dp[1]=1;
                    else return 0;
                }
                else{
                    num=(s[i-1]-'0')*10+s[i]-'0';
                    dp[1]=num<=26?2:1;
                }
            }else{
                if(s[i]=='0'){//当前元素是0
                    if(s[i-1]=='0') return 0;
                    else{
                        num=(s[i-1]-'0')*10+s[i]-'0';
                        if(num<=26) dp[i]=dp[i-2];
                        else return 0;
                    }
                }else{//当前元素不是0
                    if(s[i-1]=='0'){
                        dp[i]=dp[i-1];
                    }else{
                        num=(s[i-1]-'0')*10+s[i]-'0';
                        if(num<=26) dp[i]=dp[i-2]+dp[i-1];
                        else dp[i]=dp[i-1];
                    }
                }
            }
        }
        return dp[n-1];
    }
};
