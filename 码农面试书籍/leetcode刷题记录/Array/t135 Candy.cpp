//Ì°ÐÄËã·¨
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n=ratings.size();
        vector<int> increment(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                increment[i]=max(increment[i-1]+1,increment[i]);
            }else{
                increment[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                increment[i]=max(increment[i+1]+1,increment[i]);
            }else continue;
        }
        return accumulate(&increment[0],&increment[0]+n,0);
    }
};
