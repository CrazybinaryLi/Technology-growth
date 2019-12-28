class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(),folder.end());
        res.push_back(folder[0]);
        for(int prev=0,cur=1;cur<folder.size();){
            if(isSubfolder(folder[prev],folder[cur])){
                cur++;
            }
            else{
                res.push_back(folder[cur]);
                prev=cur;
                cur++;
            }
        }
        return res;
    }

private:
    bool isSubfolder(string s1,string s2){
        if(s2.size()<s1.size()) return false;
        int p=0,q=0;
        while(p<s1.size()&&q<s2.size()){
            if(s1[p]==s2[q]){
                p++;
                q++;
                continue;
            }else{
                return false;
            }
        }
        if(p==s1.size()&&q!=s2.size()){
            if(s2[q]!='/') return false;
        }
        return true;
    }
};
