class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()==0) return 0;
        vector<int> copy(data);//辅助数组
        int count=InversePairsCore(data,copy,0,data.size()-1);
        return count%1000000007;
    }

private:
    int InversePairsCore(vector<int>& data,vector<int>& copy,int begin,int end){
        if(begin==end){
            copy[begin]=data[end];
            return 0;
        }
        int mid=(begin+end)>>1;
        int leftCount=InversePairsCore(data,copy,begin,mid);//统计左半部分的逆序对数，同时对左半部分排序。
        int rightCount=InversePairsCore(data,copy,mid+1,end);//统计右半部分的逆序对数，同时对右半部分排序。
        int i=mid;//左半元素最后一个元素的下标
        int j=end;//右半元素最后一个元素的下标
        int index=end;//复制到辅助数组的最后一个元素的下标
        int count=leftCount+rightCount;//逆序对的计数器
        count%=1000000007;
        while(i>=begin&&j>=mid+1){
            if(data[i]>data[j]){//合并的过程中出现了逆序对
                count+=j-mid;//与该元素包括其后的所有元素都构成逆序对
                count%=1000000007;
                copy[index--]=data[i--];
            }else{
                copy[index--]=data[j--];
            }
        }
        while(i>=begin){
            copy[index--]=data[i--];
        }
        while(j>=mid+1){
            copy[index--]=data[j--];
        }
        for(int i=begin;i<=end;i++) data[i]=copy[i];
        return count;
    }
};
