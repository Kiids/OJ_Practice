/*
����ֻ�� "I"�����󣩻� "D"����С�����ַ��� S ���� N = S.length��
���� [0, 1, ..., N] ���������� A ʹ�ö������� i = 0, ..., N-1�����У�
��� S[i] == "I"����ô A[i] < A[i+1]
��� S[i] == "D"����ô A[i] > A[i+1]
ʾ�� 1��
�����"IDID"
�����[0,4,1,3,2]
ʾ�� 2��
�����"III"
�����[0,1,2,3]
ʾ�� 3��
�����"DDI"
�����[3,2,0,1]
��ʾ��
1 <= S.length <= 10000
S ֻ�����ַ� "I" �� "D"��
*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ret;
        int i = 0, j = S.size();
        for (char c : S) 
            if (c == 'I') 
                ret.push_back(i++);
            else
                ret.push_back(j--);
        ret.push_back(i);
        return ret;
    }
};
