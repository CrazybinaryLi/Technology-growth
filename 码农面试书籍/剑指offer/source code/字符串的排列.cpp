class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.size()==0) return ans;
        set<int> visited;
        string tmp="";
        Permutation(str,ans,visited,tmp);
        return ans;
    }

private:
    void Permutation(string& str,vector<string>& ans,set<int>& visited,string& tmp){
        if(tmp.size()==str.size()&&find(ans.begin(),ans.end(),tmp)==ans.end()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<str.size();i++){
            if(visited.find(i)==visited.end()){
                visited.insert(i);
                tmp+=str[i];
                Permutation(str,ans,visited,tmp);
                visited.erase(i);
                tmp.pop_back();
            }
        }
    }
};
