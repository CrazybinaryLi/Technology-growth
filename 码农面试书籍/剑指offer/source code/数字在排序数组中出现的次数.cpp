class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //因为数组是有序的，所以用二分法搜索k在数组中出现的两个位置。
        const int len=data.size();
        if(len==0) return 0;
        int left=0,right=len-1;
        int lpos=0,rpos=0;//k在数组中最左边的位置跟最右边的位置
        while(left<=right){
            int mid=(left+right)>>1;
            if(data[mid]<k) left=mid+1;
            else if(data[mid]>k) right=mid-1;
            else if(mid-1>=0&&data[mid-1]==k) right=mid-1;
            else{
                lpos=mid;
                break;
            }
        }
        left=0;right=len-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(data[mid]<k) left=mid+1;
            else if(data[mid]>k) right=mid-1;
            else if(mid+1<len&&data[mid+1]==k) left=mid+1;
            else{
                rpos=mid;
                break;
            }
        }
        return data[rpos]==k?rpos-lpos+1:0;
    }
};
