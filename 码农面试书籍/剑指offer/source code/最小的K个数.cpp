class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //借助快速排序划分的思想，时间复杂度是O(n)。
        vector<int> ans;
        if(input.size()<1||k>input.size()||k<=0) return ans;
        int start=0;
        int end=input.size()-1;
        //将第一个数选做key对数组进行划分，划分以后返回此数被安排好以后对应的“座次”。
        int index=Partition(input,start,end);
        while(index!=k-1){
            if(index>k-1){
                end=index-1;
                index=Partition(input,start,end);
            }else{
                start=index+1;
                index=Partition(input,start,end);
            }
        }
        for(int i=0;i<=index;i++){
            ans.push_back(input[i]);
        }
        return ans;
    }

private:
    int Partition(vector<int>& input,int start,int end){
        int key=input[start];
        while(start<end){
            while(start<end&&input[end]>=key) end--;
            input[start]=input[end];
            while(start<end&&input[start]<=key) start++;
            input[end]=input[start];
        }
        input[start]=key;
        return start;
    }
};
