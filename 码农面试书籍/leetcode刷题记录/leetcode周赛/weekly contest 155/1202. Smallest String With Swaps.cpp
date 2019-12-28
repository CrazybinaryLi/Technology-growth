class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int len=s.size();
        vector<int> index[len];
        vector<int> v[len];
        for(int i=0;i<len;i++){
            father[i]=i;
            index[i].clear();
            v[i].clear();
        }
        for(int i=0;i<pairs.size();i++){
            Union(pairs[i][0],pairs[i][1]);
        }
        for(int i=0;i<len;i++){
            int f=findFather(i);
            index[f].push_back(i);
            v[f].push_back(s[i]);
        }
        for(int i=0;i<len;i++){
            sort(v[i].begin(),v[i].end());
        }
        char ans[len+1];
        for(int i=0;i<len;i++){
            int sz=index[i].size();
            for(int j=0;j<sz;j++){
                ans[index[i][j]]=v[i][j];
            }
        }
        ans[len]='\0';
        return ans;
    }

private:
    vector<int> father=vector<int>(100005,-1);//类中vector的初始化方法

    int findFather(int x){
        int k,j,r;
        r=x;
        while(r!=father[r]){
            r=father[r];//先找到根节点
        }
        k=x;
        while(k!=r){//路径压缩
            j=father[k];
            father[k]=r;
            k=j;
        }
        return r;
    }

    void Union(int x,int y){
        int fx=findFather(x);
        int fy=findFather(y);
        if(fx<fy){
            father[fy]=fx;
            father[y]=fx;
        }else{
            father[fx]=fy;
            father[x]=fy;
        }
    }
};
