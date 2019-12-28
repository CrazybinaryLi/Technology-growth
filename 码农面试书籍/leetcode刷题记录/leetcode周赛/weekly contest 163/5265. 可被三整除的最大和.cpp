class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%3==0)
            return sum;
        else if(sum%3==1)
        {
            int sub1=0;
            bool flag1=false;
            int sub2=0;
            int count2=0;
            bool flag2=false;
            for(int i=0; i<nums.size(); i++)
            {
                if(!flag1&&nums[i]%3==1){
                    sub1=nums[i];
                    flag1=true;
                }
                else if(!flag2&&nums[i]%3==2){
                    sub2+=nums[i];
                    count2++;
                }
                if(count2==2) flag2=true;
                if(flag1&&flag2) break;
            }
            if(sub1<sub2&&sub1!=0) sum-=sub1;
            else sum-=sub2;
        }
        else
        {
            int sub1=0;
            bool flag1=false;
            int count1=0;
            int sub2=0;
            bool flag2=false;
            for(int i=0; i<nums.size(); i++)
            {
                if(!flag2&&nums[i]%3==2){
                    flag2=true;
                    sub2=nums[i];
                }
                if(!flag1&&nums[i]%3==1){
                    sub1+=nums[i];
                    count1++;
                }
                if(count1==2) flag1=true;
                if(flag1&&flag2) break;
            }
            if(sub1<sub2&&sub1%3==2) sum-=sub1;
            else sum-=sub2;
        }
        if(sum%3==0) return sum;
        else return 0;
    }
};
