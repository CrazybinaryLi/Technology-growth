class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first=0,second=nums.size()-1;
        while(first<=second){
            int mid=(first+second)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) first=mid+1;
            else second=mid-1;
        }
        return second+1;
    }
};
