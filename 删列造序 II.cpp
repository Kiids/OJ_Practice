/*
������ n ���ַ�����ɵ����� strs������ÿ���ַ���������ȡ�
ѡȡһ��ɾ���������У����� strs �е�ÿ���ַ�����ɾ����Ӧÿ�����������ַ���
���磬�� strs = ["abcdef", "uvwxyz"]��ɾ���������� {0, 2, 3}��ɾ���� strs Ϊ["bef", "vyz"]��
���裬����ѡ����һ��ɾ������ answer����ô��ִ��ɾ������֮�����յõ��������Ԫ���ǰ� �ֵ���strs[0] <= strs[1] <= strs[2] ... <= strs[n - 1]�����еģ�Ȼ�����㷵�� answer.length ����С����ֵ��
ʾ�� 1��
���룺strs = ["ca","bb","ac"]
�����1
���ͣ� 
ɾ����һ�к�strs = ["a", "b", "c"]��
���� strs ��Ԫ���ǰ��ֵ����е� (����strs[0] <= strs[1] <= strs[2])��
����������Ҫ���� 1 ��ɾ������Ϊ��� strs ���ǰ��ֵ������еģ����Դ��� 1��
ʾ�� 2��
���룺strs = ["xc","yb","za"]
�����0
���ͣ�
strs �����Ѿ��ǰ��ֵ��������ˣ��������ǲ���Ҫɾ���κζ�����
ע�� strs ���в���Ҫ���ֵ������С�
Ҳ����˵��strs[0][0] <= strs[0][1] <= ... ��һ��������
ʾ�� 3��
���룺strs = ["zyx","wvu","tsr"]
�����3
���ͣ�
���Ǳ���ɾ��ÿһ�С�
��ʾ��
n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 100
strs[i] ��СдӢ����ĸ���
*/

class Solution {
    bool IsSorted(vector<string>& s)  // �ֵ���
    {
        for (int i = 0; i < s.size() - 1; i++)
            if (s[i] > s[i + 1])
                return false;
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> v(strs.size(), "");              // ά����ǰ�ַ������飬����������ԣ������������ַ�����
        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 0; j < strs.size(); j++)
                v[j] += strs[j][i];
            if (!IsSorted(v))                           // �жϵ�ǰ�ַ����Ƿ����㣬���������v
                for (int j = 0; j < strs.size(); j++)   // �����㣬�������ַ�
                    v[j].pop_back();
        }
        return strs[0].size() - v[0].size();            // ��ֵ���Ǳ��Ƴ��ַ�������
    }
};
