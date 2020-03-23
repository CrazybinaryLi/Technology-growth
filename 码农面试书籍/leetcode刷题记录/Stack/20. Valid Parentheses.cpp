class Solution
{
public:
    bool isValid(string s)
    {
        if(s.size()==0)
            return true;
        return isValid(s.c_str());
    }

private:
    bool isValid(const char* s)
    {
        stack<char> st;
        while(st.size()!=0)
            st.pop();
        while(*s!='\0')
        {
            if(*s=='('||*s=='['||*s=='{')
                st.push(*s);
            else if(st.size()==0) return false;
            else
            {
                switch(*s)
                {
                case ')':
                    if(st.top()!='(')
                        return false;
                    else
                        st.pop();
                    break;
                case ']':
                    if(st.top()!='[')
                        return false;
                    else
                        st.pop();
                    break;
                default:
                    if(st.top()!='{')
                        return false;
                    else
                        st.pop();
                }
            }
            s++;
        }
        if(st.size()!=0) return false;
        return true;
    }
};
