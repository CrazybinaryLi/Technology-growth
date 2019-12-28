class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=1;
            }else mp[arr[i]]++;
        }
        vector<int> res;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            res.push_back(it->second);
        }
        sort(res.begin(),res.end());
        for(int i=1;i<res.size();i++){
            if(res[i]==res[i-1]) return false;
        }
        return true;
    }
};
