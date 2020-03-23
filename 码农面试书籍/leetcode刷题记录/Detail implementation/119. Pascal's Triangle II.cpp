class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre(1,1);
        if(rowIndex==0) return pre;
        for(int i=2;i<=rowIndex+1;i++){
            vector<int> cur(i,1);
            for(int j=1;j<i-1;j++){
                cur[j]=pre[j-1]+pre[j];
            }
            pre=cur;
        }
        return pre;
    }
};
