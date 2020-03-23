class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto i:nums) mp[i]=false;
        int llen=0;
        for(auto i:nums){
            if(mp[i]) continue;
            mp[i]=true;
            int len=1;
            for(int j=i+1;mp.find(j)!=mp.end();j++){
                mp[j]=true;
                ++len;
            }
            for(int j=i-1;mp.find(j)!=mp.end();j--){
                mp[j]=true;
                ++len;
            }
            llen=max(llen,len);
        }
        return llen;
    }
};
