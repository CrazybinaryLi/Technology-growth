class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int res=0;
        vector<int> height;
        height.resize(matrix[0].size());
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                height[j]=(matrix[i][j]=='0'?0:(1+height[j]));
            }
            res=max(res,largestRectangleArea(height));
        }
        return res;
    }

private:
    int largestRectangleArea(vector<int>& height){
        int res=0;
        stack<int> st;//单调递增栈
        height.push_back(0);
        for(int i=0;i<height.size();i++){
            while(!st.empty()&&height[st.top()]>=height[i]){
                int cur=st.top();st.pop();
                res=max(res,height[cur]*(st.empty()?i:(i-st.top()-1)));
            }
            st.push(i);
        }
        return res;
    }
};
