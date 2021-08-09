/*
������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
����԰� �κ�˳�� ���ش𰸡�
ʾ�� 1��
���룺n = 4, k = 2
�����
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
ʾ�� 2��
���룺n = 1, k = 1
�����[[1]]
��ʾ��
1 <= n <= 20
1 <= k <= n
*/

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> v;
    vector<vector<int>> combine(int n, int k) {
        fun(n, k, k);
        return v;
    }

    void fun(int n, int k, int len){
        if (tmp.size() == len)
        {
            v.push_back(tmp);
            return;
        }
        for (; n >= k; n--) {
            tmp.push_back(n);
            fun(n - 1, k - 1, len);
            tmp.pop_back();
        }
    }
};
