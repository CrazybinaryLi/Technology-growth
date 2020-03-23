class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string ans="";
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0;i<numbers.size();i++){
            string tmp=to_string(numbers[i]);
            ans+=tmp;
        }
        return ans;
    }

private:
    static bool cmp(int a,int b){
        string a_str=to_string(a);
        string b_str=to_string(b);
        return a_str+b_str<b_str+a_str;
    }
};
