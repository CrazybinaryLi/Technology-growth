class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        priority_queue<int,vector<int>,less<int>> que;//优先队列
        vector<int> ans;
        if(num.size()==0||size==0||size>num.size()) return ans;
        for(int i=0;i<num.size()&&i<size;i++){
            que.push(num[i]);
        }
        ans.push_back(que.top());
        int p=0,q=size-1;
        while(++q<num.size()){
            if(que.top()==num[p++]) que.pop();
            que.push(num[q]);
            ans.push_back(que.top());
        }
        return ans;
    }
};
