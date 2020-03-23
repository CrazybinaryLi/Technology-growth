class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> mp;
        int i;
        for(i=0;i<str.size();i++){
            mp[str[i]]++;
        }
        for(i=0;i<str.size();i++){
            if(mp[str[i]]==1) break;
        }
        return i<str.size()?i:-1;
    }
};
