/*
����һ���ַ��� title �����ɵ����ո�����һ������������ɣ�ÿ�����ʶ�ֻ����Ӣ����ĸ�����㰴���¹���ÿ�����ʵ�����ĸ ��д ��
������ʵĳ���Ϊ 1 ���� 2 ��������ĸ���Сд��
���򣬽���������ĸ��д��ʣ����ĸ���Сд��
���㷵�� ��д�� �� title ��
ʾ�� 1��
���룺title = "capiTalIze tHe titLe"
�����"Capitalize The Title"
���ͣ�
�������е��ʵĳ��ȶ�����Ϊ 3 ����ÿ����������ĸ��д��ʣ����ĸ��ΪСд��
ʾ�� 2��
���룺title = "First leTTeR of EACH Word"
�����"First Letter of Each Word"
���ͣ�
���� "of" ����Ϊ 2 ��������������ȫСд��
�������ʳ��ȶ�����Ϊ 3 ������������������ĸ��д��ʣ����ĸСд��
ʾ�� 3��
���룺title = "i lOve leetcode"
�����"i Love Leetcode"
���ͣ�
���� "i" ����Ϊ 1 ������������Сд��
�������ʳ��ȶ�����Ϊ 3 ������������������ĸ��д��ʣ����ĸСд��
��ʾ��
1 <= title.length <= 100
title �ɵ����ո�����ĵ�����ɣ��Ҳ������κ�ǰ�����׺�ո�
ÿ�������ɴ�д��СдӢ����ĸ��ɣ��Ҷ��� �ǿ� �ġ�
*/

class Solution {
public:
    string capitalizeTitle(string title) {
        int i = 0;
        while (i < title.size())
        {
            int j = i;
            while (j < title.size() && title[j] != ' ')
                title[j++] |= 32;
            if (j - i > 2)
                title[i] &= ~32;
            i = j + 1;
        }
        return title;
    }
};
