class Solution {
public:
    int fac(int n){
        int f=1;
        while(n>1){
            f*=n;
            n--;
        }
        return f;
    }

    string getPermutation(int n, int k) {
        string s;
        string temp;
        for(int i=1;i<=n;i++) temp+=(i+48);
        while(temp.size()>0){
            int m=k/fac(n-1);//定位到第几段位
            if(k%(fac(n-1))!=0){
                k-=m*(fac(n-1));
                ++m;
            }else{
                k-=(m-1)*(fac(n-1));
            }
            s+=temp[m-1];
            temp.erase(remove(temp.begin(),temp.end(),temp[m-1]),temp.end());
            --n;
        }
        return s;
    }
};
