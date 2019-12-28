class Solution {
public:
    int balancedString(string s) {
       const int n=s.size();
       int res=n;
       unordered_map<char,int> cnt;
       for(auto& c:s) cnt[c]++;
       int i=0,avg=n/4;
       for(int j=0;j<n;j++){
            cnt[s[j]]--;
            while(i<n&&cnt['Q']<=avg&&cnt['R']<=avg&&cnt['E']<=avg&&cnt['W']<=avg){
                res=min(res,j-i+1);
                cnt[s[i++]]++;
            }
       }
       return res;
    }
};
