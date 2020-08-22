/*
��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ��������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ������� 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�
����԰�����˳�򷵻ش𰸡�
ʾ�� 1��
���룺["bella","label","roller"]
�����["e","l","l"]
ʾ�� 2��
���룺["cool","lock","cook"]
�����["c","o"]
��ʾ��
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] ��Сд��ĸ
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> ret;
        int num[100][26] = {0};                       //����һ����ά���飬������г��ֵ���ĸ����
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[i].size(); j++)
                num[i][(A[i][j] - 'a')]++;
        
        for (int j = 0; j < 26; j++)                  //�������е���Сֵ�浽��һ��
            for (int i = 1; i < A.size(); i++)
                num[0][j] = min (num[0][j], num[i][j]);
                    
        string str;                                   //���յ�һ�б���Ĵ��������Ӧ��ĸ
        for (int i = 0; i < 26; i++)
        {
            while (num[0][i]--)
            {
                str.clear();
                str.push_back((char)('a' + i));
                ret.push_back(str);
            }
        }
        return ret;
    }
};
