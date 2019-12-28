class Solution {//滑动窗口思想
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odd;//存储所有奇数的下标
        odd.push_back(-1);
        int i=1;//左边界奇数的坐标
        int res=0;
        for(int j=0;j<=nums.size();j++){
            if(j==nums.size()||(nums[j]&1)){
                odd.push_back(j);
            }
            if(odd.size()-i>k){//此时右面才有数
                int a=odd[i]-odd[i-1];//前面的个数
                int b=j-odd[odd.size()-2];//后面的个数
                res+=a*b;
                i++;//往右滑动一格
            }
        }
        return res;
    }
};
