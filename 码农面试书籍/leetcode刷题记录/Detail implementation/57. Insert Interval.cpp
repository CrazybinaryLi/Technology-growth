class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int n=intervals.size();
        int cur=0;//当前遍历到的区间
        vector<vector<int>> res;
        while(cur<n&&intervals[cur][1]<newInterval[0]){
            res.push_back(intervals[cur]);
            cur++;
        }
        while(cur<n&&intervals[cur][0]<=newInterval[1]){
            newInterval[0]=min(intervals[cur][0],newInterval[0]);
            newInterval[1]=max(intervals[cur][1],newInterval[1]);
            cur++;
        }
        res.push_back(newInterval);
        while(cur<n){
            res.push_back(intervals[cur]);
            cur++;
        }
        return res;
    }
};
