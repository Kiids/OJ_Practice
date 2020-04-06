/*
对于一个矩阵，请设计一个算法从左上角(mat[0][0])开始，顺时针打印矩阵元素。
给定int矩阵mat,以及它的维数nxm，请返回一个数组，数组中的元素为矩阵元素的顺时针输出。
测试样例：
[[1,2],[3,4]],2,2
返回：[1,2,4,3]
*/

class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        // write code here
        vector<int> ret;
        if (mat.empty())
            return ret;
        
        int row = n;
        int col = m;
        int l = 0, r = col - 1, top = 0, end = row - 1;
        
        while (l <= r && top <= end)
        {
            for (int i = l; i <= r; i++)
                ret.push_back(mat[top][i]);
            for (int i = top + 1; i <= end; i++)
                ret.push_back(mat[i][r]);
            if (top != end)
                for (int i = r - 1; i >= l; i--)
                    ret.push_back(mat[end][i]);
            if (l != r)
                for (int i = end - 1; i > top; i--)
                    ret.push_back(mat[i][l]);
            
            l++;
            r--;
            top++;
            end--;
        }
        return ret;
    }
};
