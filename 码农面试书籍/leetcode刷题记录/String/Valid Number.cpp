class Solution {
public:
    bool isNumber(string s) {
        char* endptr;
        strtod(s.c_str(),&endptr);
        if(endptr==s) return false;
        for(;*endptr;endptr++){
            if(!isspace(*endptr)) return false;
        }
        return true;
    }
};
