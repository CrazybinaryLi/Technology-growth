//�����Ʒ���Ҫ�󼯺ϵ�Ԫ�ظ���������intλ����
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<1<<n;i++){
            //i��ʶ�м�������ɹ�ѡ��
            vector<int> tmp;
            for(int j=0;j<n;j++){
                //j��ʶѡ�ڸ�Ԫ��
                if(i&1<<j) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
