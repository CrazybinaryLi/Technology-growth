class Solution {
public:
	//抽屉原理的应用
    int findDuplicate(vector<int>& nums) {
    	int start=1;
    	int end=nums.size();
		while(start<end){
			int count=0;
			int mid=(start+end)/2;
			for(int i=0;i<nums.size();i++){
				if(nums[i]<=mid) count++;
			}
			if(count>mid){
				end=mid;
			}else{
				start=mid+1;
			}
		}
		return end;
    }
};
