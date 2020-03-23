class Solution {
public:
    int reverse(int x) {
        vector<int> vec;
        while(x!=0){
            vec.push_back(x%10);
            x/=10;
        }
        long long res=0;
        for(int i=0;i<vec.size();i++){
            res*=10;
            res+=vec[i];
        }
        return (int)res==res?res:0;
    }
};
