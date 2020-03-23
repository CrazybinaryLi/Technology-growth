class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size()<=1) return str;
        string ans="";
        int p=str.size()-1;
        int q=p;
        while(p>=0){
            while(q>=0&&str[q]!=' ') q--;
            if(ans==""){
                ans+=str.substr(q+1,p-q);
            }else{
                ans+=" ";
                ans+=str.substr(q+1,p-q);
            }
            q--;
            p=q;
        }
        return ans==""?str:ans;
    }
};
