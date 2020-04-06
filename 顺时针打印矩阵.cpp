/*
����һ�����������һ���㷨�����Ͻ�(mat[0][0])��ʼ��˳ʱ���ӡ����Ԫ�ء�
����int����mat,�Լ�����ά��nxm���뷵��һ�����飬�����е�Ԫ��Ϊ����Ԫ�ص�˳ʱ�������
����������
[[1,2],[3,4]],2,2
���أ�[1,2,4,3]
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
