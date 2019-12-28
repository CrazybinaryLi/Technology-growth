class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        const int len=arr.size();
        vector<vector<int>> res;
        res.resize(len,vector<int>(2));
        res.clear();
        sort(arr.begin(),arr.end());
        int min_diff=INT_MAX;
        for(int i=1;i<len;i++){
            if(arr[i]-arr[i-1]<min_diff){
                min_diff=arr[i]-arr[i-1];
            }
        }
        for(int i=1;i<len;i++){
            if(arr[i]-arr[i-1]==min_diff){
                vector<int> tmp;
                tmp.push_back(arr[i-1]);
                tmp.push_back(arr[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
