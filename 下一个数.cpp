/*
下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）。
示例1:
 输入：num = 2（或者0b10）
 输出：[4, 1] 或者（[0b100, 0b1]）
示例2:
 输入：num = 1
 输出：[2, -1]
提示:
num的范围在[1, 2147483647]之间；
如果找不到前一个或者后一个满足条件的正数，那么输出 -1。
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
