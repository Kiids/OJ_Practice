/*
�����ַ����б� strs ���������� ����������� �ĳ��ȡ������������в����ڣ����� -1 ��
�������� �������£�������Ϊĳ�ַ��� ���е������У��������������ַ����������У���
 s �� �����п���ͨ��ɾȥ�ַ��� s �е�ĳЩ�ַ�ʵ�֡�
���磬"abc" �� "aebdc" �������У���Ϊ������ɾ��"aebdc"�е��»����ַ����õ� "abc" ��"aebdc"�������л�����"aebdc"�� "aeb" �� "" (���ַ���)��
ʾ�� 1��
����: strs = ["aba","cdc","eae"]
���: 3
ʾ�� 2:
����: strs = ["aaa","aaa","aa"]
���: -1
��ʾ:
2 <= strs.length <= 50
1 <= strs[i].length <= 10
strs[i] ֻ����СдӢ����ĸ
*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ret = -1;
        for (int i = 0; i < strs.size(); i++)
        {
            bool flag = 1;
            for (int j = 0; j < strs.size(); j++)
                if (i != j)
                {
                    for (int k = 0, w = 0; k < strs[j].size(); k++)
                    {
                        if (w < strs[i].size() && strs[i][w] == strs[j][k])
                            w++;
                        if (w == strs[i].size())
                            flag = 0;
                }
            }
            if (flag)
                ret = max(ret, (int)strs[i].size());
        }
        return ret;
    }
};

//���� res �� s_i �������е��ǲ��������ַ����������У���ô res=s_i ����������
//����ֻ��Ҫ��ÿһ���ַ�������һ���Ƿ����������������С�

