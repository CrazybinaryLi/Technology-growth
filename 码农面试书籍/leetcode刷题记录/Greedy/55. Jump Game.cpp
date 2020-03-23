class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        for(int i=0;i<nums.size();i++){
            if(reach<i||reach>=nums.size()-1) break;
            if(reach<nums[i]+i)
                reach=nums[i]+i;
        }
        return reach>=nums.size()-1;
    }
};
