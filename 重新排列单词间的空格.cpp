/*
����һ���ַ��� text �����ַ��������ɱ��ո��Χ�ĵ�����ɡ�ÿ��������һ�����߶��СдӢ����ĸ��ɣ�������������֮�����ٴ���һ���ո���Ŀ����������֤ text ���ٰ���һ������ ��
�����������пո�ʹÿ�����ڵ���֮��Ŀո���Ŀ�� ��� ���������� ��� ����Ŀ�������������ƽ���������пո��� ������Ŀո�������ַ���ĩβ ����Ҳ��ζ�ŷ��ص��ַ���Ӧ����ԭ text �ַ����ĳ�����ȡ�
���� �������пո����ַ��� ��
ʾ�� 1��
���룺text = "  this   is  a sentence "
�����"this   is   a   sentence"
���ͣ��ܹ��� 9 ���ո�� 4 �����ʡ����Խ� 9 ���ո�ƽ�����䵽���ڵ���֮�䣬���ڵ��ʼ�ո���Ϊ��9 / (4-1) = 3 ����
ʾ�� 2��
���룺text = " practice   makes   perfect"
�����"practice   makes   perfect "
���ͣ��ܹ��� 7 ���ո�� 3 �����ʡ�7 / (3-1) = 3 ���ո���� 1 ������Ŀո񡣶���Ŀո���Ҫ�����ַ�����ĩβ��
ʾ�� 3��
���룺text = "hello   world"
�����"hello   world"
ʾ�� 4��
���룺text = "  walks  udp package   into  bar a"
�����"walks  udp  package  into  bar  a "
ʾ�� 5��
���룺text = "a"
�����"a"
��ʾ��
1 <= text.length <= 100
text ��СдӢ����ĸ�� ' ' ���
text �����ٰ���һ������
*/

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> s;
        int i = 0, c = 0;
        while (i < text.size())
        {
            while (i < text.size() && text[i] == ' ')
                i++;
            string x;
            while (i < text.size() && text[i] != ' ')
                x += text[i], i++;
            c += x.size();
            if (x.size())
                s.push_back(x);
        }
        string ret;
        int r = text.size() - c;
        if (s.size() == 1)
        {
            ret += s.front();
            ret += string(r, ' ');
        }
        else
        {
            int a = r / (s.size() - 1);
            int b = r % (s.size() - 1);
            for (int j = 0; j < s.size(); j++)
            {
                if (j)
                    ret += string(a, ' ');
                ret += s[j];
            }
            if (b)
                ret += string(b, ' ');
        }
        return ret;
    }
};
