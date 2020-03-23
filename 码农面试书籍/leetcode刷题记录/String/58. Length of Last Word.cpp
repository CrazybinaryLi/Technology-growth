class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream str(s);
        string tmp;
        int len=0;
        while(getline(str,tmp," ")){
            len=strlen(tmp);
        }
        return len;
    }
};
