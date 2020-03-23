class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++) mp[nums[i]]=i;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()&&mp.find(target-nums[i])->second>i){
                res.push_back(i);
                res.push_back(mp.find(target-nums[i])->second);
                break;
            }
        }
        return res;
    }
};
