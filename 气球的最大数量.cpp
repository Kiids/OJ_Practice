/*
����һ���ַ��� text������Ҫʹ�� text �е���ĸ��ƴ�վ����ܶ�ĵ��� "balloon"�����򣩡�
�ַ��� text �е�ÿ����ĸ���ֻ�ܱ�ʹ��һ�Ρ����㷵��������ƴ�ճ����ٸ����� "balloon"��
ʾ�� 1��
���룺text = "nlaebolko"
�����1
ʾ�� 2��
���룺text = "loonbalxballpoon"
�����2
ʾ�� 3��
���룺text = "leetcode"
�����0
��ʾ��
1 <= text.length <= 10^4
text ȫ����СдӢ����ĸ���
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (char e : text)
            m[e]++;
        return min({m['b'], m['a'], m['l'] / 2, m['o'] / 2, m['o']});
    }
};
