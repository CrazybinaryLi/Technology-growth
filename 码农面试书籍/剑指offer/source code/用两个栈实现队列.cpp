class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res=-1;
        if(!stack2.empty()){
            res=stack2.top();
            stack2.pop();
        }else{
            if(!stack1.empty()){
                while(!stack1.empty()){
                    int tmp=stack1.top();
                    stack2.push(tmp);
                    stack1.pop();
                }
            }
            if(!stack2.empty()){
                res=stack2.top();
                stack2.pop();
            }
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
