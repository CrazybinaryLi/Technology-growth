class Solution {
public:
    //先计算下三角乘积，再计算上三角乘积。
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(),1);
        //计算下三角乘积
        for(int i=1;i<A.size();i++){
            B[i]=B[i-1]*A[i-1];
        }
        //计算上三角乘积
        int temp=1;
        for(int i=A.size()-2;i>=0;i--){
            temp*=A[i+1];
            B[i]*=temp;
        }
        return B;
    }
};
