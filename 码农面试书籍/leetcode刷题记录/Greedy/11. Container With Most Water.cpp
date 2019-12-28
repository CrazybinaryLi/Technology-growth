class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=INT_MIN;
        int start=0;
        int end=height.size()-1;
        while(start<end){
            int area=min(height[start],height[end])*(end-start);
            result=max(result,area);
            if(height[start]<height[end]) start++;
            else end--;
        }
        return result;
    }
};
