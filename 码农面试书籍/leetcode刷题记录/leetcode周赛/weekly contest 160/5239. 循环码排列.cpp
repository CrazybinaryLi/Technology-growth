class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        int gray=start;
        int binary=gray;
        while(start>>=1) binary^=start;
        int i=1;
        while(i++<=(int)pow(2,n)){
            res.push_back(gray);
            binary+=1;
            binary%=(int)pow(2,n);
            gray=binary^(binary>>1);
        }
        return res;
    }
};
