/*
����һ���ַ��� sequence ������ַ��� word �����ظ� k ���γɵ��ַ����� sequence ��һ�����ַ�������ô���� word �� �ظ�ֵΪ k ������ word �� ����ظ�ֵ �ǵ��� word �� sequence �������ظ�ֵ����� word ���� sequence ���Ӵ�����ô�ظ�ֵ k Ϊ 0 ��
����һ���ַ��� sequence �� word �����㷵�� ����ظ�ֵ k ��
ʾ�� 1��
���룺sequence = "ababc", word = "ab"
�����2
���ͣ�"abab" �� "ababc" �����ַ�����
ʾ�� 2��
���룺sequence = "ababc", word = "ba"
�����1
���ͣ�"ba" �� "ababc" �����ַ������� "baba" ���� "ababc" �����ַ�����
ʾ�� 3��
���룺sequence = "ababc", word = "ac"
�����0
���ͣ�"ac" ���� "ababc" �����ַ�����
��ʾ��
1 <= sequence.length <= 100
1 <= word.length <= 100
sequence �� word ��ֻ����СдӢ����ĸ��
*/

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ret = 0;
        string curr = word;
        while (sequence.find(curr) != string::npos)
        {
            ret++;
            curr += word;
        }
        return ret;
    }
};
