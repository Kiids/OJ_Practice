/*
����һ�� ���� �ַ������� nums ��һ�� ���� �ַ��� target �����㷵�� nums[i] + nums[j] �������ַ������ӣ�������� target ���±� (i, j) �������� i != j������Ŀ��
ʾ�� 1��
���룺nums = ["777","7","77","77"], target = "7777"
�����4
���ͣ�����Ҫ����±�԰�����
- (0, 1)��"777" + "7"
- (1, 0)��"7" + "777"
- (2, 3)��"77" + "77"
- (3, 2)��"77" + "77"
ʾ�� 2��
���룺nums = ["123","4","12","34"], target = "1234"
�����2
���ͣ�����Ҫ����±�԰���
- (0, 1)��"123" + "4"
- (2, 3)��"12" + "34"
ʾ�� 3��
���룺nums = ["1","1","1"], target = "11"
�����6
���ͣ�����Ҫ����±�԰���
- (0, 1)��"1" + "1"
- (1, 0)��"1" + "1"
- (0, 2)��"1" + "1"
- (2, 0)��"1" + "1"
- (1, 2)��"1" + "1"
- (2, 1)��"1" + "1"
��ʾ��
2 <= nums.length <= 100
1 <= nums[i].length <= 100
2 <= target.length <= 100
nums[i] �� target ֻ�������֡�
nums[i] �� target �������κ�ǰ�� 0 ��
*/

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> m;
        for (string x: nums)
            m[x]++;
        int ret = 0;
        for (int i = 1; i < target.size(); i++)
        {
            string s = target.substr(0, i);
            string t = target.substr(i);
            if (s == t)
                ret += m[s] * (m[s] - 1);
            else
                ret += m[s] * m[t];
        }
        return ret;
    }
};
