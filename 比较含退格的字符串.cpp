/*
���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ���
ע�⣺����Կ��ı������˸��ַ����ı�����Ϊ�ա�
ʾ�� 1��
���룺S = "ab#c", T = "ad#c"
�����true
���ͣ�S �� T ������ ��ac����
ʾ�� 2��
���룺S = "ab##", T = "c#d#"
�����true
���ͣ�S �� T ������ ������
ʾ�� 3��
���룺S = "a##c", T = "#a#c"
�����true
���ͣ�S �� T ������ ��c����
ʾ�� 4��
���룺S = "a#c", T = "b"
�����false
���ͣ�S ���� ��c������ T ��Ȼ�� ��b����
��ʾ��
1 <= S.length <= 200
1 <= T.length <= 200
S �� T ֻ����Сд��ĸ�Լ��ַ� '#'��
���ף�
������� O(N) ��ʱ�临�ӶȺ� O(1) �Ŀռ临�ӶȽ����������
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s, t;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] != '#')
                s += S[i];
            else if (!s.empty())
                s.pop_back();
        }
        for (int i = 0; i < T.size(); i++)
        {
            if (T[i] != '#')
                t += T[i];
            else if (!t.empty())
                t.pop_back();
        }
        if (s == t)
            return true;
        return false;
    }
};
