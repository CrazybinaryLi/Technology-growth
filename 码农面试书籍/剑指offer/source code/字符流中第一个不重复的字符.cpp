class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        hash[ch]++;
        if(hash[ch]==1){
            que.push(ch);
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(hash[que.front()]>1){
            que.pop();
        }
        return que.empty()?'#':que.front();
    }

private:
    queue<char> que;
    int hash[256];
};
