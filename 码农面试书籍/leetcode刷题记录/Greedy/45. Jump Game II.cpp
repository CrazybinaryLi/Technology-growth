class Solution {
public:
    int jump(vector<int>& nums) {
        int ret=0;//最少的跳数
        int cur=0;//当前一跳能到达的最远距离
        int last=0;//上一跳能到达的最远距离
        for(int i=0;i<nums.size();i++){
            if(i>cur) return -1;//当前怎么跳都无法抵达
            if(i>last){//上一跳已经无法达到
                last=cur;
                ++ret;
            }
            cur=max(cur,i+nums[i]);
        }
        return ret;
    }
};
