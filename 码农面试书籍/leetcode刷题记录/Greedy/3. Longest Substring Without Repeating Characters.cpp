class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int tlen=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=1;
                tlen++;
            }else{
                int j;
                for(j=i-1;s[j]!=s[i];j--);
                tlen=i-j;
                mp.erase(mp.begin(),mp.end());
                for(int k=j+1;k<=i;k++) mp[s[k]]=1;
            }
            if(tlen>res) res=tlen;
        }
        return res;
    }
};
