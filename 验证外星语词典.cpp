/*
ĳ��������Ҳʹ��Ӣ��Сд��ĸ��������˳�� order ��ͬ����ĸ���˳��order����һЩСд��ĸ�����С�
����һ������������д�ĵ��� words���Լ�����ĸ���˳�� order��ֻ�е������ĵ����������������а��ֵ�������ʱ������ true�����򣬷��� false��
ʾ�� 1��
���룺words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
�����true
���ͣ��ڸ����Ե���ĸ���У�'h' λ�� 'l' ֮ǰ�����Ե��������ǰ��ֵ������еġ�
ʾ�� 2��
���룺words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
�����false
���ͣ��ڸ����Ե���ĸ���У�'d' λ�� 'l' ֮����ô words[0] > words[1]����˵������в��ǰ��ֵ������еġ�
ʾ�� 3��
���룺words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
�����false
���ͣ���ǰ�����ַ� "app" ƥ��ʱ���ڶ����ַ�����Զ�һЩ��Ȼ����ݴʵ������� "apple" > "app"����Ϊ 'l' > ' '������ ' ' �ǿհ��ַ�������Ϊ���κ������ַ���С��������Ϣ����
��ʾ��
1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
�� words[i] �� order �е������ַ�����Ӣ��Сд��ĸ��
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < words.size() - 1; i++)
        {
            int index = 0;
            while (words[i][index] == words[i + 1][index] && index < words[i].size() && index < words[i + 1].size())
                index++;
            if (index == words[i].size())
                return true;
            if (index == words[i + 1].size())
                return false;

            char a = words[i][index], b = words[i + 1][index];
            if (order.find(a) > order.find(b))
                return false;
        }
        return true;
    }
};
