/*
���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� ������ϡ�
ʾ�� 1��
���룺n = 3
�����["((()))","(()())","(())()","()(())","()()()"]
ʾ�� 2��
���룺n = 1
�����["()"]
��ʾ��
1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        int l = 0, r = 0;
        DFS(ret, "", n, l, r);
        return ret;
    }
    void DFS(vector<string>& res, string path, int n, int lc, int rc)
    {
        if (rc > lc || lc > n || rc > n)
            return;
        if (lc == rc && lc == n)
        {
            res.push_back(path);
            return;
        }
        DFS(res, path + '(', n, lc + 1, rc);
        DFS(res, path + ')', n, lc, rc + 1);
    }
};
