class Solution {//滑动窗口
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> window;//窗口中的元素
        unordered_map<char,int> needs;//需要的所有元素跟与之对应的个数
        for(auto c:p) needs[c]++;
        int left=0,right=0;//左右双指针
        int match=0;//匹配成功的个数
        vector<int> res;
        while(right<s.size()){
            if(needs.count(s[right])){//匹配上的情况
                window[s[right]]++;
                if(window[s[right]]==needs[s[right]]) match++;//匹配成功一个元素
                else if(window[s[right]]>needs[s[right]]){//匹配多了的情况，左边指针要右移。
                    while(window[s[right]]>needs[s[right]]){
                        if(window[s[left]]==needs[s[left]]) match--;
                        window[s[left]]--;
                        left++;
                    }
                }
                if(match==needs.size()){
                    res.push_back(left);
                    match--;
                    window[s[left]]--;
                    left++;
                }
                right++;
            }
            else if(!needs.count(s[right])){//遇到匹配不上的情况，指针整体后移。
                left=right+1;
                right+=1;
                match=0;
                window.clear();
            }
        }
        return res;
    }
};
