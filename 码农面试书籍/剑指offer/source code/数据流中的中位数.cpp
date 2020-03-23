class Solution {
public:
    void Insert(int num)
    {
        number.push_back(num);
        sort(number.begin(),number.end());
    }

    double GetMedian()
    {
        if(number.size()%2==0){//偶数
            return ((double)number[number.size()/2]+(double)number[number.size()/2-1])/2;
        }
        return (double)number[number.size()/2];
    }

private:
    vector<int> number;
};
