/*
�����������ʹ�ü��������������� name��ż�����ڼ����ַ� c ʱ���������ܻᱻ���������ַ����ܱ����� 1 �λ��Ρ�
�㽫�������������ַ� typed���������Ӧ�Ŀ�����������ѵ����֣�����һЩ�ַ����ܱ�����������ô�ͷ��� True��
ʾ�� 1��
���룺name = "alex", typed = "aaleex"
�����true
���ͣ�'alex' �е� 'a' �� 'e' ��������
ʾ�� 2��
���룺name = "saeed", typed = "ssaaedd"
�����false
���ͣ�'e' һ����Ҫ���������Σ����� typed ������в���������
ʾ�� 3��
���룺name = "leelee", typed = "lleeelee"
�����true
ʾ�� 4��
���룺name = "laiden", typed = "laiden"
�����true
���ͣ����������е��ַ������Ǳ�Ҫ�ġ�
��ʾ�� 
name.length <= 1000
typed.length <= 1000
name �� typed ���ַ�����Сд��ĸ��
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        for (i = 0; i < name.size(); i++)
        {
            if (name[i] != typed[j])
                return false;
            while (name[i] == typed[j])
            {
                if (name[i] == name[i+1])
                {
                    j++;
                    break;
                }
                j++;
            }
        }
        return true;
    }
};
