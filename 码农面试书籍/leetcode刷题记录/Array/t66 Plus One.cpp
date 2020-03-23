class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        int carry=1;
        int current=0;
        vector<int> res;
        while(n--){
            current=digits[i]+carry;
            if(current>=10){
                current-=10;
                carry=1;
                res.push_back(current);
            }else{
                res.push_back(current);
                carry=0;
            }
            i--;
        }
        if(carry>0) res.push_back(carry);
        for(int i=0;i<res.size()/2;i++){
            swap(res[i],res[res.size()-1-i]);
        }
        return res;
    }
};
