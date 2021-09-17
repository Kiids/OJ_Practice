/*
��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ���?Z �������С�
���������ַ���Ϊ "PAYPALISHIRING"?����Ϊ 3 ʱ���������£�
P   A   H   N
A P L S I I G
Y   I   R
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��
����ʵ��������ַ�������ָ�������任�ĺ�����
string convert(string s, int numRows);
ʾ�� 1��
���룺s = "PAYPALISHIRING", numRows = 3
�����"PAHNAPLSIIGYIR"
ʾ�� 2��
���룺s = "PAYPALISHIRING", numRows = 4
�����"PINALSIGYAHRPI"
���ͣ�
P     I    N
A   L S  I G
Y A   H R
P     I
ʾ�� 3��
���룺s = "A", numRows = 1
�����"A"
��ʾ��
1 <= s.length <= 1000
s ��Ӣ����ĸ��Сд�ʹ�д����',' �� '.' ���
1 <= numRows <= 1000
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool goingDown = false;
		for (char c : s)
        {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1)
				goingDown = !goingDown;
			curRow += goingDown ? 1 : -1;
		}
		string ret;
		for (string row : rows)
			ret += row;
		return ret;
    }
};
