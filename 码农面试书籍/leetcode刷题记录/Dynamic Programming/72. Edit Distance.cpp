class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0) return word2.size();
        else if(word2.size()==0) return word1.size();
        vector<int> dp(word2.size(),INT_MAX);
        dp[0]=word1[0]==word2[0]?0:1;
        for(int j=1;j<word2.size();j++){
            if(word2[j]==word1[0]) dp[j]=j;
            else{
                dp[j]=min(j,dp[j-1])+1;//替换、删除、增加
            }
        }
        vector<int> tmp=dp;
        for(int i=1;i<word1.size();i++){
            dp[0]=i;
            for(int j=1;j<word2.size();j++){
                dp[j]=min(tmp[j-1],min(dp[j-1],dp[j]));
            }
            tmp=dp;
        }
        return dp[word2.size()-1];
    }
};
