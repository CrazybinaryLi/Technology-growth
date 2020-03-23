class Solution {
public:
    void reOrderArray(vector<int> &array) {
        const int len=array.size();
        int k=0;//k记录已经排序好的奇数个数
        for(int i=0;i<len;i++){
            if(array[i]%2==1){
                int j=i;
                while(j>k){
                    swap(array[j],array[j-1]);
                    j--;
                }
                k++;
            }
        }
    }
};
