class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        vector<int>::iterator a=nums.end()-1;
        vector<int>::iterator b=nums.end()-2;
        while(*b>=*a&&b>nums.begin()){
            b--;
            a--;
        }
        if(b==nums.begin()&&(*b)>=(*a)){
            sort(nums.begin(),nums.end());
            return;
        }
        vector<int>::iterator i;
        for(i=nums.end()-1;*i<=*b;i--);
        int temp;
        temp=*b;
        *b=*i;
        *i=temp;
        b++;
        sort(b,nums.end());
        return;
    }
};
