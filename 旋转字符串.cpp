/*
���������ַ���, A �� B��
A ����ת�������ǽ� A ����ߵ��ַ��ƶ������ұߡ� ����, �� A = 'abcde'�����ƶ�һ��֮��������'bcdea' ����������ɴ���ת����֮��A �ܱ��B����ô����True��
ʾ�� 1:
����: A = 'abcde', B = 'cdeab'
���: true
ʾ�� 2:
����: A = 'abcde', B = 'abced'
���: false
ע�⣺
A �� B ���Ȳ����� 100��
*/

class Solution {
public:
    bool rotateString(string A, string B) {
        int m = A.size(), n = B.size();
        if (m != n)
            return false;
        if (A == B)
            return true;
        return (A + A).find(B) != string::npos;
    }
};

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};
