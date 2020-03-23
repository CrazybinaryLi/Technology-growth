class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()<5) return false;
        int zeroSum=0;
        int interval=0;
        sort(numbers.begin(),numbers.end());
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==0) zeroSum++;
            else if(i>0&&numbers[i]==numbers[i-1]) return false;//出现了对子，则不可能是顺子。
            else if(i>0&&numbers[i-1]!=0) interval+=numbers[i]-numbers[i-1]-1; //统计间隔数
        }
        return zeroSum>=interval;
    }
};
