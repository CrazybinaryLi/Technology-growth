class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int dis=INT_MAX;
        int result;
        for(auto i=nums.begin();i<nums.end()-2;i++){
            if(i>nums.begin()&&*i==*(i-1)) continue;
            auto j=i+1;
            auto k=nums.end()-1;
            while(j<k){
                if(*i+*j+*k==target) {
                    return target;
                }else if(*i+*j+*k>target&&abs(*i+*j+*k-target)>dis){
                    --k;
                    while(*k==*(k+1)&&j<k) --k;
                }else if(*i+*j+*k<target&&abs(*i+*j+*k-target)>dis){
                    ++j;
                    while(*j==*(j-1)&&j<k) ++j;
                }else{
                    dis=abs(*i+*j+*k-target);
                    result=*i+*j+*k;
                    if(abs(*i+*(j+1)+*k-target)<abs(*i+*j+*(k-1)-target)) j++;
                    else --k;
                }
            }
        }
        return result;
    }
};
