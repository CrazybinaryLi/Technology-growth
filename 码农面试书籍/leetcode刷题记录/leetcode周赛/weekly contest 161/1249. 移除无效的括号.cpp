class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> index;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                index.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                    index.pop();
                }
                else{
                    index.push(i);
                }
            }
        }
        vector<int> tmp;
        while(!index.empty()){
            int i=index.top();
            index.pop();
            tmp.push_back(i);
        }
        string res="";
        for(int i=0;i<s.size();i++){
            if('a'<=s[i]&&s[i]<='z') res+=s[i];
            else if(find(tmp.begin(),tmp.end(),i)==tmp.end()) res+=s[i];
        }
        return res;
    }
};
