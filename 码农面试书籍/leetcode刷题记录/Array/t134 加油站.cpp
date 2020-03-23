class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;//指示当前指针是否可行
        int total=0;//判断整个数组是否有解
        int j=-1;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0){
                j=i;
                sum=0;
            }
        }
        return total>=0?j+1:-1;
    }
};
