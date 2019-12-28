class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        const int len=s1.size();
        int count_xy=0;
        int count_yx=0;
        int sum=0;
        for(int i=0; i<len; i++)
        {
            if(s1[i]==s2[i])
                continue;
            if(s1[i]=='x'&&s2[i]=='y')
                count_xy++;
            else
            {
                count_yx++;
            }
            if(count_xy==2){
                sum+=1;
                count_xy=0;
            }
            if(count_yx==2){
                sum+=1;
                count_yx=0;
            }
        }
        if(count_xy!=count_yx) return -1;
        sum+=count_xy*2;
        return sum;
    }
};
