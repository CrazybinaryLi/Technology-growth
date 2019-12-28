class Solution {//以点为中心，计算与每个点共线的点最大的个数。
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<3) return points.size();
        int result=0;
        unordered_map<double,int> slope_count;//斜率跟个数的对应关系
        for(int i=0;i<points.size()-1;++i){
            slope_count.clear();
            int samePointNum=0;//与i重合的点
            int point_max=1;//与i共线的最大点数
            for(int j=i+1;j<points.size();++j){
                double slope;//斜率
                if(points[i][0]==points[j][0]){
                    slope=std::numeric_limits<double>::infinity();
                    if(points[i][1]==points[j][1]){
                        samePointNum++;
                        continue;
                    }
                }else{
                    //因为除法精度的问题，所以要扩大1000倍。
                    slope=((double)points[i][1]-points[j][1])*1000/((double)points[i][0]-points[j][0]);
                    //cout<<slope<<endl;
                }
                int count=0;
                if(slope_count.find(slope)!=slope_count.end()){
                    count=++slope_count[slope];
                }else{
                    count=2;
                    slope_count[slope]=2;
                }
                if(point_max<count) point_max=count;
            }
            result=max(result,point_max+samePointNum);
        }
        return result;
    }
};
