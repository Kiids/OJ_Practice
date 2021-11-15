/*
�������������� A �� B ���������������й����ġ��������������ĳ��ȡ�
ʾ����
���룺
A: [1,2,3,2,1]
B: [3,2,1,4,7]
�����3
���ͣ�
������Ĺ����������� [3, 2, 1] ��
��ʾ��
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ret = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > ret)
                    ret = dp[i][j];
            }
        }
        return ret;
    }
};
