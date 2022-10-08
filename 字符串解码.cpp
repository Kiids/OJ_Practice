/*
����һ������������ַ������������������ַ�����
�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������
�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻������� 3a �� 2[4] �����롣
ʾ�� 1��
���룺s = "3[a]2[bc]"
�����"aaabcbc"
ʾ�� 2��
���룺s = "3[a2[c]]"
�����"accaccacc"
ʾ�� 3��
���룺s = "2[abc]3[cd]ef"
�����"abcabccdcdcdef"
ʾ�� 4��
���룺s = "abc3[cd]xyz"
�����"abccdcdcdxyz"
��ʾ��
1 <= s.length <= 30
s ��СдӢ����ĸ�����ֺͷ����� '[]' ���
s ��֤��һ�� ��Ч �����롣
s ������������ȡֵ��ΧΪ [1, 300] 
*/

class Solution {
public:
    string decodeString(string s) {
        string ret = "";
        stack <int> nums;
        stack <string> strs;
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i] - '0';
            else if ((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z'))
                ret = ret + s[i];
            else if (s[i] == '[')  // ����[��ǰ������ѹ��numsջ�ڣ� ��ĸ�ַ���ѹ��strsջ��
            {
                nums.push(num);
                num = 0;
                strs.push(ret); 
                ret = "";
            }
            else  // ������]��ʱ��������֮����ġ�[��֮����ַ���ʹ�÷�����
            {
                int times = nums.top();
                nums.pop();
                for (int j = 0; j < times; j++)
                    strs.top() += ret;
                ret = strs.top();  // ֮����������ĸ��ֱ�Ӽӵ�res֮��ͬ�����㣬���������ţ�retѹ��strsջ����Ϊ��һ�������
                strs.pop();
            }
        }
        return ret;
    }
};
