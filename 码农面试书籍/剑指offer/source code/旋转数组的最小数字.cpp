class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left=0;
        int right=rotateArray.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(rotateArray[mid]>rotateArray[right]) left=mid+1;//在右半部分
            else if(rotateArray[mid]<rotateArray[right]) right=mid;//在左半部分
            else if(rotateArray[mid]==rotateArray[right]) right--;//缩小范围
        }
        return rotateArray[right+1];
    }
};
