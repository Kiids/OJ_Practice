/*
����һ���ַ��� S ��һ���ַ� C������һ�������ַ��� S ��ÿ���ַ����ַ��� S �е��ַ� C ����̾�������顣
ʾ�� 1:
����: S = "loveleetcode", C = 'e'
���: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
˵��:
�ַ��� S �ĳ��ȷ�ΧΪ [1, 10000]��
C ��һ�����ַ����ұ�֤���ַ��� S ����ַ���
S �� C �е�������ĸ��ΪСд��ĸ��
*/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> v(S.size(), 10001);
        for (int i = 0, j = 0; i < S.size(); i++, j++)
            if (S[i] == C) 
                while (j >= 0)
                    v[i - j --] = j;

        for (int i = S.size() - 1, j = 0; i >= 0; i--, j++)
            if (S[i] == C) 
                while (j >= 0)
                    v[i + j --] = min(v[i + j], j);
        return v;
    }
};
