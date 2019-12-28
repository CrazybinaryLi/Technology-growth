//贪心算法
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        const int n=colsum.size();
        int sum=0;
        for(auto v:colsum){
            sum+=v;
        }
        if(upper+lower!=sum) return {};
        vector<vector<int>> arr(2,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                upper--;
                lower--;
                arr[0][i]=1;
                arr[1][i]=1;
            }
        }
        if(upper<0||lower<0) return {};
        for(int i=0;i<n;i++){
            if(colsum[i]==1){
                if(upper>0){
                    upper--;
                    arr[0][i]=1;
                }else if(lower>0){
                    lower--;
                    arr[1][i]=1;
                }else return {};
            }
        }
        return arr;
    }
};
