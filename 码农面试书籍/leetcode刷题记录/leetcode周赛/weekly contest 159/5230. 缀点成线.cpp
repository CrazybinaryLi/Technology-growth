class Solution
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        if(coordinates.size()==2)
            return true;
        if(coordinates[0][0]!=coordinates[1][0])
        {
            double k=(coordinates[0][1]-coordinates[1][1])/(coordinates[0][0]-coordinates[1][0]);
            for(int i=3; i<coordinates.size(); i++)
            {
                if((double)((double)coordinates[0][1]-coordinates[i][1])/((double)coordinates[0][0]-coordinates[i][0])!=k)
                    return false;
            }
        }
        else{
            double k=0;
            for(int i=3;i<coordinates.size();i++){
                if(coordinates[i][1]!=coordinates[0][1]) return false;
            }
        }
        return true;
    }
};
