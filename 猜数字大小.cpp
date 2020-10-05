/*
��������Ϸ�Ĺ������£�
ÿ����Ϸ��ϵͳ����� 1?�� n ���ѡ��һ�����֡� �����ѡ�������ĸ����֡�
�����´��ˣ�ϵͳ������㣬��²�����ֱ�ϵͳѡ���������Ǵ��˻���С�ˡ�
�����ͨ������һ��Ԥ�ȶ���õĽӿ� guess(int num) ����ȡ�²���������ֵһ���� 3 �ֿ��ܵ������-1��1 �� 0����
-1 : ��²�����ֱ�ϵͳѡ�������ִ�
 1 : ��²�����ֱ�ϵͳѡ��������С
 0 : ��ϲ����¶��ˣ�
ʾ�� :
����: n = 10, pick = 6
���: 6
*/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n, m;
		while (i <= j)
		{
			m = i + (j - i) / 2;
			if (guess(m) == 0)
				return m;
			else
				if (guess(m) == 1)
				
					i = m + 1;
				else
					j = m - 1;
		}
		return -1;
    }
};
