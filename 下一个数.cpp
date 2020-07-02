/*
��һ����������һ�����������ҳ���������Ʊ��ʽ��1�ĸ�����ͬ�Ҵ�С��ӽ�������������һ���Դ�һ����С����
ʾ��1:
 ���룺num = 2������0b10��
 �����[4, 1] ���ߣ�[0b100, 0b1]��
ʾ��2:
 ���룺num = 1
 �����[2, -1]
��ʾ:
num�ķ�Χ��[1, 2147483647]֮�䣻
����Ҳ���ǰһ�����ߺ�һ��������������������ô��� -1��
*/

class Solution {
public:
    int count1(int num)
    {
		int cnt = 0;
		for (int i = 0; i < 32; i++)
			if (num & (1 << i)) cnt++;
		return cnt;
	}

	vector<int> findClosedNumbers(int num)
    {
		int s = count1(num);
		vector<int> res = { -1,-1 };
		for (int i = num + 1; i <= 2147483647; i++)
			if (count1(i) == s)
            {
				res[0] = i;
                break;
            }
		for (int i = num - 1; i >= 0; i--)
			if (count1(i) == s)
            {
				res[1] = i;
                break;
            }
		return res;
	}
};
