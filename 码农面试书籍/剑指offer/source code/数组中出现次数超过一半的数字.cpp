class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0) return 0;
        int flag=numbers[0];
        int count=1;
        for(int i=1;i<numbers.size();i++){
            if(numbers[i]!=flag){
                count--;
                if(count==0){
                    flag=numbers[i];
                    count=1;
                }
            }else count++;
        }
        count=0;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==flag) count++;
        }
        return count>numbers.size()/2?flag:0;
    }
};
