//二进制法，要求集合的元素个数不超过int位数。
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<1<<n;i++){
            //i标识有几种情况可供选择
            vector<int> tmp;
            for(int j=0;j<n;j++){
                //j标识选第个元素
                if(i&1<<j) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
