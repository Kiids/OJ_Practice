/*
����һ��Excel����е������ƣ���������Ӧ������š�
���磬
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
ʾ�� 1:
����: "A"
���: 1
ʾ�� 2:
����: "AB"
���: 28
ʾ�� 3:
����: "ZY"
���: 701
*/

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (auto e : s)
            ret = ret * 26 + (e - 'A' + 1);
        return ret;
    }
};
// 26������ת10����
