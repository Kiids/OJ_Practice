// ����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
// ʾ�� 1: 
// ����: "Let's take LeetCode contest"
// ���: "s'teL ekat edoCteeL tsetnoc"
// ע�⣺���ַ����У�ÿ�������ɵ����ո�ָ��������ַ����в������κζ���Ŀո�

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] != ' ')
            {
                int j = i;
                for(; j < n && s[j] != ' '; j++);
                reverse(s.begin()+i,s.begin()+j);
                i = j;
            }
        }
        return s;
    }
};

