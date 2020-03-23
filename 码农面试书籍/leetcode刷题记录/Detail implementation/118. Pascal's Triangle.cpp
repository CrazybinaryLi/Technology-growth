class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> pre;
        vector<int> cur;
        for(int i=0;i<numRows;i++){
            if(i==0){
                cur.push_back(1);
                pre.assign(cur.begin(),cur.end());
                ans.push_back(cur);
                cur.clear();
                continue;
            }
            for(int j=0;j<=i;j++){
                if(j==0||j==i) cur.push_back(1);
                else cur.push_back(pre[j-1]+pre[j]);
            }
            ans.push_back(cur);
            pre.assign(cur.begin(),cur.end());
            cur.clear();
        }
        return ans;
    }
};
