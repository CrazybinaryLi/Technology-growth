class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p=0,q=0;
        vector<int> tmp(nums1);
        nums1.clear();
        nums1.resize(m+n);
        int k=0;
        while(p<m&&q<n){
            if(tmp[p]<=nums2[q]){
                nums1[k++]=tmp[p++];
            }
            else nums1[k++]=nums2[q++];
        }
        while(p<m) nums1[k++]=tmp[p++];
        while(q<n) nums1[k++]=nums2[q++];
    }
};
