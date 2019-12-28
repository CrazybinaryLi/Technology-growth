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
    int factorial(int n){
        int f=1;
        for(int i=n;i>1;i--){
            f*=i;
        }
        return f;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        result.push_back(nums);
        int count=factorial(nums.size());
        count--;
        while(count--){
            nextPermutation(nums);
            result.push_back(nums);
        }
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
