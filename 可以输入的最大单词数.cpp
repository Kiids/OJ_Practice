/*
���̳�����һЩ���ϣ���Щ��ĸ���޷��������������������������������ܹ�����������
����һ�������ɵ�����ɵ��ַ��� text �����ʼ��ɵ����ո���ɣ�����ǰ����β��ո񣩣�����һ���ַ��� brokenLetters �����������𻵵Ĳ�ͬ��ĸ����ɣ����������ʹ�ô˼�����ȫ����� text �е��ʵ���Ŀ��
ʾ�� 1��
���룺text = "hello world", brokenLetters = "ad"
�����1
���ͣ��޷����� "world" ����Ϊ��ĸ�� 'd' ���𻵡�
ʾ�� 2��
���룺text = "leet code", brokenLetters = "lt"
�����1
���ͣ��޷����� "leet" ����Ϊ��ĸ�� 'l' �� 't' ���𻵡�
ʾ�� 3��
���룺text = "leet code", brokenLetters = "e"
�����0
���ͣ��޷������κε��ʣ���Ϊ��ĸ�� 'e' ���𻵡�
��ʾ��
1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text �������õ����ո�ָ��ĵ�����ɣ��Ҳ����κ�ǰ����β��ո�
ÿ�����ʽ���СдӢ����ĸ���
brokenLetters �� ������ͬ ��СдӢ����ĸ���
*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = 0, flag = 1;
        for (char e : text)
        {
            if (e == ' ')
            {
                if (flag)
                    n++;
                else
                    flag = 1;
            }
            else
            {
                for (char c : brokenLetters)
                {
                    if (e == c)
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
            n++;
        return n;
    }
};
