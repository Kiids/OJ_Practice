/*
����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "�������"student. a am I"��
ʾ�� 1��
����: "the sky is blue"
���: "blue is sky the"
ʾ�� 2��
����: "  hello world!  "
���: "world! hello"
����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
ʾ�� 3��
����: "a good   example"
���: "example good a"
����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
˵����
�޿ո��ַ�����һ�����ʡ�
�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
*/

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return s;

        string ret = "";
        int n = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && n != 0)
            {
                ret += s.substr(i + 1, n) + ' ';
                n = 0;
                continue;
            }
            if (s[i] != ' ')
                n++;
        }
        if (n != 0)
            ret += s.substr(0, n) + ' ';
        if (ret.size() > 0)  // û������жϻ�ִ�г���
            ret.erase(ret.size() - 1, 1);  // ɾ��������Ǹ��ո�
        return ret;
    }
};
