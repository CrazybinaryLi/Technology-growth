class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;//res是最终的结果
        int tp=1,tn=1;//tp到此时正的最大值，tn到此时负的绝对值最大。
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                res=max(res,0);
                tp=1;
                tn=1;
            }else{
                if(nums[i]>0){
                    tp*=nums[i];
                    if(tn!=1){
                        tn*=nums[i];
                    }
                    res=max(res,tp);
                }else{//nums[i]<0
                    if(tn<0){
                        int tpt=tp;
                        int tnt=tn;
                        tp=tn*nums[i];
                        tn=tpt*nums[i];
                        res=max(res,tp);
                    }else{
                        tn=tp*nums[i];
                        tp=1;
                        res=max(res,tn);
                    }
                }
            }
        }
        return res;
    }
};
