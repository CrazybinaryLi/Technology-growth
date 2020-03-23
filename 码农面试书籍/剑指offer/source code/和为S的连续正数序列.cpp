class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        //采用的是滑动窗口法（双指针法），预先设定两个指针，
        //如果此时窗口内的值加起来大于sum，则左指针右移，
        //如果此时窗口内的值加起来小于sum，则右指针右移。
        vector<vector<int>> ans;
        int low=1,high=2;
        while(low<high){
            int curSum=(low+high)*(high-low+1)/2;//当前窗口内的数加起来的和
            if(curSum==sum){
                vector<int> tmp;
                for(int i=low;i<=high;i++) tmp.push_back(i);
                ans.push_back(tmp);
                low++;
            }else if(curSum<sum) high++;
            else low++;
        }
        return ans;
    }
};
