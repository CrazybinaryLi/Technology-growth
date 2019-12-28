class Solution {
public:
    bool isPalindrome(int x) {
        string sx=to_string(x);
        for(int i=0;i<sx.size()/2;i++){
            if(sx[i]!=sx[sx.size()-1-i]) return false;
        }
        return true;
    }
};
