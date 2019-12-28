class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;//窗口中的元素都是符合条件的元素
        int left=0,right=0;
        int maxLen=0;
        while(right<s.size()){
            window[s[right]]++;
            if(window[s[right]]==1){
                if(right-left+1>maxLen) maxLen=right-left+1;
                //cout<<left<<" "<<right<<endl;
            }
            else if(window[s[right]]>=2){
                while(window[s[right]]>=2){
                    window[s[left]]--;
                    left++;
                }
            }
            right++;
        }
        return maxLen;
    }
};
