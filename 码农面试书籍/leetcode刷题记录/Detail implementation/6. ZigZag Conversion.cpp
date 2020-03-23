class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2) return s;
        vector<string> ans(numRows,"");
        int i=0,flag=-1;
        for(auto& c:s){
            ans[i]+=c;
            if(i==0||i==numRows-1) flag=-flag;
            i+=flag;
        }
        string res="";
        for(auto& str:ans) res+=str;
        return res;
    }
};
