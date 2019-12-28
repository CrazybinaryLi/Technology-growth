class Solution {
public:
    int numWays(int steps, int arrLen) {
        double modX = 1000000007;
        if (arrLen > steps)
        {
            arrLen = steps;
        }
        vector<vector<double> > arr(steps + 1, vector<double>(arrLen, 0));
        arr[0][0] = 1;
        for (int i = 0; i < steps; ++i)
        {
            for (int j = 0; j < arrLen; ++j)
            {
                while (arr[i][j] >= modX)
                {
                    arr[i][j] -= modX;
                }

                if (j - 1 >= 0)
                {
                    arr[i+1][j-1] += arr[i][j];
                }
                if (j + 1 <= arrLen - 1)
                {
                    arr[i+1][j+1] += arr[i][j];
                }
                arr[i+1][j] += arr[i][j];
            }
        }
        while (arr[steps][0] >= modX)
        {
            arr[steps][0] -= modX;
        }
        return arr[steps][0];
    }
};
