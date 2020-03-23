class Solution {
public:
    //回溯法经典题
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0) return 0;
        sum=1;
        dfs(make_pair(0,0),threshold,rows,cols);
        return sum;
    }

private:
    set<pair<int,int>> visit;
    int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int sum;
    void dfs(pair<int,int> start,int threshold,int rows,int cols){
        visit.insert(start);
        for(int i=0;i<4;i++){
            pair<int,int> next=make_pair(start.first+fx[i][0],start.second+fx[i][1]);
            if(next.first>=0&&next.first<rows&&next.second>=0&&next.second<cols&&goin(next,threshold)&&visit.find(next)==visit.end()){
                ++sum;
                dfs(next,threshold,rows,cols);
            }
        }
    }

    bool goin(pair<int,int> pos,int threshold){
        int x=pos.first;
        int y=pos.second;
        int sum=0;
        while(x){
            sum+=(x%10);
            x/=10;
        }
        while(y){
            sum+=(y%10);
            y/=10;
        }
        return threshold>=sum;
    }
};
