class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> num;
        for(int i=0; i<tokens.size(); i++)
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
            {
                num.push(atoi(tokens[i].c_str()));
            }
            else
            {
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                if(tokens[i]=="+")
                {
                    num.push(a+b);
                }
                else if(tokens[i]=="-")
                {
                    num.push(b-a);
                }
                else if(tokens[i]=="*")
                {
                    num.push(a*b);
                }
                else
                    num.push(b/a);
            }
        }
        return num.top();
    }
};
