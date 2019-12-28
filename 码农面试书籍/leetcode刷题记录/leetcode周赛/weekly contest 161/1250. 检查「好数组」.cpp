class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g=nums[0];
        for(auto num : nums){
            g=gcd(g,num);
        }
        return g==1;
    }

private:
    int gcd(int a,int b){
        if(a<b) swap(a,b);
        int t=a%b;
        if(t==0) return b;
        else return gcd(b,t);
    }
};
