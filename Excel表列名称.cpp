/*
����һ������������������ Excel �������Ӧ�������ơ�
���磬
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
ʾ�� 1:
����: 1
���: "A"
ʾ�� 2:
����: 28
���: "AB"
ʾ�� 3:
����: 701
���: "ZY"
*/

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while (n-- > 0)
        {
            ret.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
