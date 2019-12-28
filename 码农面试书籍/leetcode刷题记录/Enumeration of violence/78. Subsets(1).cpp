//ÿ���㶼����ѡ��ȡ���߲�ȡ�����Կ��������ѵķ���,���ʵݹ顣
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> path;
        subsets(nums,path,0,result);
        return result;
    }

private:
    static void subsets(const vector<int>& nums,vector<int>& path,int step,vector<vector<int>>& result){
        if(step==nums.size()){
            result.push_back(path);
            return;
        }
        //��ѡnums[step]
        subsets(nums,path,step+1,result);
        //ѡnums[step]
        path.push_back(nums[step]);
        subsets(nums,path,step+1,result);
        path.pop_back();
    }
};
