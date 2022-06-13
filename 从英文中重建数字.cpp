/*
����һ���ַ��� s �����а�����ĸ˳����ҵ���Ӣ�ĵ��ʱ�ʾ���������֣�0-9������ ���� ����ԭʼ�����֡�
ʾ�� 1��
���룺s = "owoztneoer"
�����"012"
ʾ�� 2��
���룺s = "fviefuro"
�����"45"
��ʾ��
1 <= s.length <= 10^5
s[i] Ϊ ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] ��Щ�ַ�֮һ
s ��֤��һ��������ĿҪ����ַ���
*/

class Solution {
public:
    string originalDigits(string s) {
        string ret;
        vector<int> num(10, 0);//ͨ��0-9��Ӣ�ĵ��ʵ�������ĸ�����������ֵĸ���
        vector<int> alpha(26, 0);//��ĸ�� ͳ��ÿ����ĸ���ֵĴ���
        for (int i = 0; i < s.size(); i++)
            alpha[s[i] - 'a']++;//ͳ��ÿ����ĸ������
        num[0] = alpha['z' - 'a'];
        num[2] = alpha['w' - 'a'];
        num[4] = alpha['u' - 'a'];
        num[6] = alpha['x' - 'a'];
        num[8] = alpha['g' - 'a'];
        num[5] = alpha['f' - 'a'] - num[4];
        num[3] = alpha['h' - 'a'] - num[8];
        num[7] = alpha['s' - 'a'] - num[6];
        num[9] = alpha['i' - 'a'] - num[5] - num[6] - num[8];
        num[1] = alpha['o' - 'a'] - num[0] - num[2] - num[4];

        for (int i = 0; i < 10; i++)
        {
            int count = num[i];
            for (int j = 0; j < count; j++)
                ret.push_back(char('0' + i));
        }
        return ret;
    }
};
