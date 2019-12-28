class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int res=0;
        int curCost=0;
        int b=0,e=0;
        const int len=s.size();
        while(e<len&&b<=e)
        {
            int diff=abs(s[e]-t[e]);//当前数组元素的绝对值的差
            if(curCost+diff<=maxCost)
            {
                curCost+=diff;
                if(e-b+1>res)
                {
                    res=e-b+1;
                }
                e++;
            }
            else if(curCost==0){
                e++;
                b=e;
            }
            else
            {
                curCost-=abs(s[b]-t[b]);
                b++;
            }
        }
        return res;
    }
};
