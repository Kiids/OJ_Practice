/*
����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����
���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ�����
ʾ�� 1��
���룺s = "aab"
�����[["a","a","b"],["aa","b"]]
ʾ�� 2��
���룺s = "a"
�����[["a"]]
��ʾ��
1 <= s.length <= 16
s ����СдӢ����ĸ���
*/

class Solution {
    vector<vector<string>> v;
    vector<string> path;
    void DFS(string& s, size_t n, int index)
    {
        if (index >= n)
        {
            v.push_back(path);
            return;
        }
        for (int i = index; i < n; i++)
        {
            int j = index, k = i, flag = 1;
            while (j <= k)
            {
                if (s[j] != s[k])
                {
                    flag = 0;
                    break;
                }
                j++;
                k--;
            }
            if (flag)
            {
                path.push_back(s.substr(index, i - index + 1));
                DFS(s, n, i + 1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        DFS(s, s.length(), 0);
        return v;
    }
};

