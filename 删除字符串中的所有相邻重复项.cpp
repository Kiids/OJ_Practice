/*
������Сд��ĸ��ɵ��ַ��� S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����
����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��
ʾ����
���룺"abbaca"
�����"ca"
���ͣ�
���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"��
��ʾ��
1 <= S.length <= 20000
S ����СдӢ����ĸ��ɡ�
*/

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for (int i = 0; i < S.size(); i++)
            if (s.empty() || S[i] != s.top())
                s.push(S[i]);
            else
                s.pop();

        string ret = "";
        while (!empty(s))
        {
            ret += s.top();
            s.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
