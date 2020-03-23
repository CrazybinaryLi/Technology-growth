class Solution {
public:
    string addBinary(string a, string b) {
        string tmp="";
        int i=a.size()-1,j=b.size()-1;
        int carry=0;
        while(i>=0||j>=0){
            int aa=(i>=0?a[i]-'0'+0:0);
            int bb=(j>=0?b[j]-'0'+0:0);
            int t=aa+bb+carry>=2?aa+bb+carry-2:aa+bb+carry;
            carry=(aa+bb+carry>=2?1:0);
            tmp+=(t+'0'-0);
            i--;
            j--;
        }
        if(carry!=0) tmp+=(carry-0+'0');
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }
};
