class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<1) return true;
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]<='z'&&s[i]>='a') tmp+=s[i];
            else if(s[i]<='Z'&&s[i]>='A') tmp+=s[i]-'A'+'a';
            else if(s[i]>='0'&&s[i]<='9') tmp+=s[i];
            else continue;
        }
        for(int j=0;j<tmp.size()/2;j++){
            if(tmp[j]!=tmp[tmp.size()-1-j]) return false;
        }
        return true;
    }
};
