/*
����������Сд��ĸ���ɵ��ַ��� A �� B ��ֻҪ���ǿ���ͨ������ A �е�������ĸ�õ��� B ��ȵĽ�����ͷ��� true �����򷵻� false ��
������ĸ�Ķ�����ȡ�����±� i �� j ���±�� 0 ��ʼ����ֻҪ i!=j �ͽ��� A[i] �� A[j] �����ַ������磬�� "abcd" �н����±� 0 ���±� 2 ��Ԫ�ؿ������� "cbad" ��
ʾ�� 1��
���룺 A = "ab", B = "ba"
����� true
���ͣ� ����Խ��� A[0] = 'a' �� A[1] = 'b' ���� "ba"����ʱ A �� B ��ȡ�
ʾ�� 2��
���룺 A = "ab", B = "ab"
����� false
���ͣ� ��ֻ�ܽ��� A[0] = 'a' �� A[1] = 'b' ���� "ba"����ʱ A �� B ����ȡ�
ʾ�� 3:
���룺 A = "aa", B = "aa"
����� true
���ͣ� ����Խ��� A[0] = 'a' �� A[1] = 'a' ���� "aa"����ʱ A �� B ��ȡ�
ʾ�� 4��
���룺 A = "aaaaaaabc", B = "aaaaaaacb"
����� true
ʾ�� 5��
���룺 A = "", B = "aa"
����� false
��ʾ��
0 <= A.length <= 20000
0 <= B.length <= 20000
A �� B ����Сд��ĸ���ɡ�
*/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;
        if (A == B)
        {
            unordered_map<char, int> m;
            for (char c : A)
                m[c] += 1;
            for (char c : A)
                if (m[c] > 1)
                    return true;
            return false;
        }
        else
        {
            int first = -1, second = -1;
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i] != B[i])
                {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }
            return (second != -1 && A[first] == B[second] && A[second] == B[first]);
        }
    }
};
