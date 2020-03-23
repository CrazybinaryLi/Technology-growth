class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        dfs(res,ip,s,0);
        return res;
    }

private:
    void dfs(vector<string>& res,vector<string>& ip,string& s,int start){
        if(start==s.size()&&ip.size()==4){
            res.push_back(ip[0]+'.'+ip[1]+'.'+ip[2]+'.'+ip[3]);
            return;
        }
        if(s.size()-start>(4-ip.size())*3) return;
        if(s.size()-start<(4-ip.size())) return;
        int num=0;
        for(int i=start;i<start+3;i++){
            num=num*10+s[i]-'0';
            if(num>255) return;
            ip.push_back(s.substr(start,i-start+1));
            dfs(res,ip,s,i+1);
            ip.pop_back();
            if(num==0) break;
        }
    }
};
