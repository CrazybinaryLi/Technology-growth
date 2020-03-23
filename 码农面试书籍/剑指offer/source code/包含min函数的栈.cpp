class Solution {
public:
    void push(int value) {
        st.push(value);
        Min=Min<value?Min:value;
        st_min.push(Min);
    }
    void pop() {
        st.pop();
        st_min.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return st_min.top();
    }

private:
    int Min=INT_MAX;//记录最小值
    stack<int> st;
    stack<int> st_min;//最小值组成一个栈
};
