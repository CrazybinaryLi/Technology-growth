class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int first=0,second=array.size()-1;
        while(first<second&&array[first]+array[second]!=sum){
            if(array[first]+array[second]<sum) first++;
            else if(array[first]+array[second]>sum) second--;
        }
        vector<int> ans;
        if(first<second){
            ans.push_back(array[first]);
            ans.push_back(array[second]);
        }
        return ans;
    }
};
