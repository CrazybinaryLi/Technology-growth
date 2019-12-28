class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(auto& c:s){//O(n)的时间复杂度
            if(!st.empty()&&st.back().first==c){
                if(++st.back().second==k) st.pop_back();
            }
            else{
                st.push_back(make_pair(c,1));
            }
        }
        string res;
        for(auto& i:st){
            int l=i.second;
            while(l--){
                res+=i.first;
            }
        }
        return res;
    }
};
