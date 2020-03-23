class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n=intervals.size();
        if(n<=1) return intervals;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        int pre=0;
        int next=1;
        while(next<n){
            while(next<n&&intervals[pre][1]<intervals[next][0]){
                res.push_back(intervals[pre]);
                pre++;
                next++;
            }
            if(next<n){
                intervals[next][0]=min(intervals[pre][0],intervals[next][0]);
                intervals[next][1]=max(intervals[pre][1],intervals[next][1]);
                pre=next;
                next++;
            } else break;
        }
        res.push_back(intervals[pre]);
        return res;
    }

private:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]<b[1];
    }
};
