class Solution {//滑动窗口操作,时间复杂度O(M+N),M是s的长度，N是t的长度。
public:
    string minWindow(string s, string t) {
        //记录最短字串的开始位置和长度
        int start=0,minLen=INT_MAX;
        int left=0,right=0;
        unordered_map<char,int> window;
        unordered_map<char,int> needs;
        for(auto c:t) needs[c]++;
        int match=0;//匹配上的次数
        while(right<s.size()){
            char c1=s[right];
            if(needs.count(c1)){
                window[c1]++;
                if(window[c1]==needs[c1]) match++;
            }
            right++;
            while(match==needs.size()){//如果找到了一个可行解，就开始优化这个解。
                if(right-left<minLen){
                    start=left;
                    minLen=right-start;
                }
                char c2=s[left];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2]<needs[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};
