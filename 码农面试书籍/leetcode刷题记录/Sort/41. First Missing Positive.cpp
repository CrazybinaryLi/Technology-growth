//利用桶排序的思想
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bucket_sort(nums);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }

private:
    static void bucket_sort(vector<int>& nums){
        const int len=nums.size();
        for(int i=0;i<len;i++){
            while(nums[i]!=i+1){
                if(nums[i]<=0||nums[i]>len||nums[i]==nums[nums[i]-1])
                    break;
                swap(nums[i],nums[nums[i]-1]);
            }
        }
    }
};
