class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        //首先计算出每个单词的分数，然后用回溯法统计单词组合能得到的最大分数。
        map<string,int> mp;//每个单词的分数
        map<char,int> cont;//每个字符的个数
        for(int i=0;i<words.size();i++){
            string str=words[i];
            mp[str]=0;
            for(int j=0;j<str.size();j++){
                mp[str]+=score[str[j]-'a'];
            }
        }
        for(int i=0;i<letters.size();i++){
            if(cont.find(letters[i])!=cont.end()) cont[letters[i]]++;
            else cont[letters[i]]=1;
        }
        maxScore=0;
        tmpScore=0;
        h(words,0,mp,tmpScore,cont);
        return maxScore;
    }

private:
    int maxScore;
    int tmpScore;
    void h(vector<string>& words,int begin,map<string,int>& mp,int& tmpScore,map<char,int>& cont2){
        for(int i=begin;i<words.size();i++){
            if(check(words[i],cont2)){
                for(int j=0;j<words[i].size();j++) cont2[words[i][j]]--;
                tmpScore+=mp[words[i]];
                if(tmpScore>maxScore) maxScore=tmpScore;
                //节点进入
                h(words,i+1,mp,tmpScore,cont2);
                //节点退出
                for(int j=0;j<words[i].size();j++) cont2[words[i][j]]++;
                tmpScore-=mp[words[i]];
            }
        }
    }
    bool check(string& str,map<char,int>& cont2){
        map<char,int> cont3(cont2);
        for(int i=0;i<str.size();i++){
            if(cont3[str[i]]-1<0) return false;
            else cont3[str[i]]--;
        }
        return true;
    }
};
