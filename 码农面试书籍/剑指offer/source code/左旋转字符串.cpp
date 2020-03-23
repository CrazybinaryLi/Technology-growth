class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n==0) return str;
        const int len=str.size();
        if(len==0) return str;
        n%=len;
        string subStr1=str.substr(0,n);
        string subStr2=str.substr(n);
        str=subStr2+subStr1;
        return str;
    }
};
