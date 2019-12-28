class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        if(s.size()==0||words.size()==0)
            return {};
        vector<int> ans;
        map<string,int> needs;
        map<string,int> window;
        for(auto& word:words)
            needs[word]++;
        int left=0,right=words[0].size()*words.size()-1;//初始滑动窗口的范围
        //cout<<left<<" "<<right<<endl;
        int match=0;
        while(right<s.size())
        {
            for(int i=left; i<=right+1-words[0].size(); i+=words[0].size())
            {
                string str=s.substr(i,words[0].size());
                if(needs.count(str)){
                    window[str]++;
                    if(window[str]==needs[str])
                    match++;
                }
            }
            if(match==needs.size())
                ans.push_back(left);
            match=0;
            window.clear();
            left++;
            right++;
        }
        return ans;
    }
};
