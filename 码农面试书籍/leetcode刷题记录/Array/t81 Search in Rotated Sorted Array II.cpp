class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]<nums[high]){
                //右边一定有序
                if(nums[mid]<target&&nums[high]>=target) low=mid+1;
                else high=mid-1;
            }else if(nums[mid]==nums[high]){
                //右边不一定有序
                while(nums[high]==nums[mid]&&high>0){
                    high--;
                }
            }else{
                //左边一定有序
                if(nums[mid]>target&&nums[low]<=target) high=mid-1;
                else low=mid+1;
            }
        }
        if(low==high&&nums[low]==target) return true;
        return false;
    }
};
