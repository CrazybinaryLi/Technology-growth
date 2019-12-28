class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1) return true;
        int max_step=1;
        for(int i=0;i<nums.size()-1;i++){
            max_step--;
            if(max_step<0) break;
            if((i+nums[i])>=(nums.size()-1)) return true;
            if(max_step<nums[i]) max_step=nums[i];
        }
        return false;
    }
};
