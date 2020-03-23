//位运算，以二进制的观点去看问题。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int w=sizeof(int)*8;
        int count[w];
        fill_n(&count[0],w,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<w;j++){
                count[j]+=(nums[i]>>j)&1;
                count[j]%=3;
            }
        }
        int result=0;
        for(int j=0;j<w;j++){
            result+=(count[j]<<j);
        }
        return result;
    }
};
