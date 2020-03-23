class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> aux_st;//辅助栈，用来模拟压栈的过程，若栈顶元素是popV当前元素，则弹出。
        for(int i=0,k=0;i<pushV.size();i++){
            aux_st.push(pushV[i]);
            while(!aux_st.empty()&&k<popV.size()&&aux_st.top()==popV[k]){
                aux_st.pop();
                k++;
            }
        }
        return aux_st.empty()?true:false;
    }
};
