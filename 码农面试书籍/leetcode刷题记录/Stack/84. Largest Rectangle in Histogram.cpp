class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int cur=st.top();st.pop();//栈中的索引都是比当前高度低的
                res=max(res,heights[cur]*(st.empty()?i:(i-st.top()-1)));
            }
            st.push(i);
        }
        return res;
    }
};
