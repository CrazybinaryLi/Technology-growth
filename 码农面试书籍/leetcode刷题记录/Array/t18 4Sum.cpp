class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        if(nums.size()<4)
            return res;
        sort(nums.begin(),nums.end());
        for(auto i=nums.begin(); i<nums.end()-3; i++)
        {
            if(i>nums.begin()&&*i==*(i-1))
                continue;
            if(*i+*(i+1)+*(i+2)+*(i+3)>target)
                break;
            if(*i+*(nums.end()-3)+*(nums.end()-2)+*(nums.end()-1)<target)
                continue;
            for(auto j=i+1; j<nums.end()-2; j++)
            {
                if(j>i+1&&*j==*(j-1))
                    continue;
                if(*i+*(j)+*(i+1)+*(j+2)>target)
                    break;
                if(*i+*(j)+*(nums.end()-2)+*(nums.end()-1)<target)
                    continue;
                auto m=j+1;
                auto n=nums.end()-1;
                while(m<n)
                {
                    if(*i+*j+*m+*n<target)
                    {
                        ++m;
                        while(*m==*(m-1)&&m<n)
                            ++m;
                    }
                    else if(*i+*j+*m+*n>target)
                    {
                        --n;
                        while(*n==*(n+1)&&m<n)
                            --n;
                    }
                    else
                    {
                        res.push_back({*i,*j,*m,*n});
                        ++m;
                        --n;
                        while(*m==*(m-1)&&m<n)
                            ++m;
                    }
                }
            }
        }
        return res;
    }
};
