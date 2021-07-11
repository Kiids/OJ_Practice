/*
����һ�������� triangle ���ҳ��Զ����µ���С·���͡�
ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ����ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣Ҳ����˵�������λ�ڵ�ǰ�е��±� i ����ô��һ�������ƶ�����һ�е��±� i �� i + 1 ��
ʾ�� 1��
���룺triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
�����11
���ͣ��������ͼ��ʾ��
   2
  3 4
 6 5 7
4 1 8 3
�Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����
ʾ�� 2��
���룺triangle = [[-10]]
�����-10
��ʾ��
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4
���ף�
�����ֻʹ�� O(n) �Ķ���ռ䣨n Ϊ�����ε�����������������������
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int x = triangle.size(), y = triangle.back().size();
		vector<vector<int>>  dp(x, vector<int>(y, 99999999));
		for (int i = x - 1; i >= 0; i--)
        {
			for (int j = triangle[i].size() - 1; j >= 0; j--)
            {
				if (i == x - 1)
					dp[i][j] = triangle[i][j];
				else
					dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return dp[0][0];
    }
};
