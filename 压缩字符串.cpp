/*
����һ���ַ���ʹ��ԭ���㷨����ѹ����
ѹ����ĳ��ȱ���ʼ��С�ڻ����ԭ���鳤�ȡ�
�����ÿ��Ԫ��Ӧ���ǳ���Ϊ1 ���ַ������� int �������ͣ���
�����ԭ���޸���������󣬷���������³��ȡ�
���ף�
���ܷ��ʹ��O(1) �ռ������⣿
ʾ�� 1��
���룺
["a","a","b","b","c","c","c"]
�����
����6�����������ǰ6���ַ�Ӧ���ǣ�["a","2","b","2","c","3"]
˵����
"aa"��"a2"�����"bb"��"b2"�����"ccc"��"c3"�����
ʾ�� 2��
���룺
["a"]
�����
����1�����������ǰ1���ַ�Ӧ���ǣ�["a"]
˵����
û���κ��ַ����������
ʾ�� 3��
���룺
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
�����
����4�����������ǰ4���ַ�Ӧ���ǣ�["a","b","1","2"]��
˵����
�����ַ�"a"���ظ������Բ��ᱻѹ����"bbbbbbbbbbbb"����b12�������
ע��ÿ�������������ж������Լ���λ�á�
ע�⣺
�����ַ�����һ��ASCIIֵ��[35, 126]�����ڡ�
1 <= len(chars) <= 1000��
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int l = chars.size();
        int i = 0, j = 0, index = 0;
        while(i < l)
        {
            while(j < l && chars[j] == chars[i])
                j++;
            int num = j - i;
            chars[index++] = chars[i];
            if(num != 1)
            {
                string sn = toString(num);
                for(char ch : sn)
                    chars[index++] = ch;
            }
            i = j;
        }
        return index;
    }
    string toString(int x)
    {
        string ret = "";
        if(x == 0)
            return "0";
        else
            while(x != 0)
            {
                ret = char(x % 10 + '0') + ret;
                x /= 10;
            }
            return ret;
    }
};
