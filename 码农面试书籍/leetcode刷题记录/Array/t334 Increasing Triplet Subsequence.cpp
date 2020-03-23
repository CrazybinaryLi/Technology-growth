class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=2) return false;
        int Min=INT_MAX, Mid=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=Min){
                Min=nums[i];
            }
            else if(nums[i]<=Mid){
                Mid=nums[i];
            }
            else return true;
        }
        return false;
    }
};

static int _ = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
