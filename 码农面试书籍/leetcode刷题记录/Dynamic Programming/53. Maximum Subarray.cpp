class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m=nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i]=max(nums[i-1]+nums[i],nums[i]);
            m=max(nums[i],m);
        }
        return m;
    }
};
