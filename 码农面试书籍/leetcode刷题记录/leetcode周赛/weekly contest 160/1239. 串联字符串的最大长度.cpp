//深度优先搜索(dfs)
class Solution {
public:
    int maxLength(vector<string>& arr) {
        h=0;
        string s="";
        st.push(s);
        for(int i=0;i<arr.size();i++){
            int th=0;
            dfs(arr,i,th);
        }
        return h;
    }

private:
    stack<string> st;
    int h=0;
    void dfs(vector<string>& arr,int b,int& th){
        for(int i=b;i<arr.size();i++){
            if(check(st,arr[i])){
                st.push(arr[i]);
                //output_st(st);
                th+=arr[i].size();
                if(th>h) h=th;
                //cout<<h<<endl;
                dfs(arr,i+1,th);
                st.pop();
                th-=arr[i].size();
            }
        }
    }

    bool check(stack<string>& st,string& str){
        for(int i=0;i<str.size();i++){
            for(int j=i+1;j<str.size();j++){
                if(str[i]==str[j]) return false;
            }
        }
        stack<string> tst(st);
        while(!tst.empty()){
            string s=tst.top();
            tst.pop();
            for(int i=0;i<s.size();i++){
                for(int j=0;j<str.size();j++){
                    if(s[i]==str[j]) return false;
                }
            }
        }
        return true;
    }

    /*void output_st(stack<string>& st){
        stack<string> tst(st);
        while(!tst.empty()){
            cout<<tst.top()<<" ";
            tst.pop();
        }
        cout<<endl;
    }*/
};
