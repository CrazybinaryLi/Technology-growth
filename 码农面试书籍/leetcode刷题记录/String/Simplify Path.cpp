class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        string res,t;
        stringstream ss(path);
        while(getline(ss,t,'/')){
            if(t==""||t==".") continue;
            if(t==".."&&!v.empty()) v.pop_back();
            else if(t!="..") v.push_back(t);
        }
        for(string s:v) res+="/"+s;
        return res.empty()?"/":res;
    }
};
