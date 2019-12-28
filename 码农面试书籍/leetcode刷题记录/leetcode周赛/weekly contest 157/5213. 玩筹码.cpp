class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int js=0,os=0;
        for(int i=0;i<chips.size();i++){
            if(chips[i]%2==0) os++;
            else js++;
        }
        if(os==0||js==0) return 0;
        return os<js?os:js;
    }
};
