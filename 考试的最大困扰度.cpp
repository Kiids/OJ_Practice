/*
һλ��ʦ���ڳ�һ���� n ���ж��⹹�ɵĿ��ԣ�ÿ����Ĵ�Ϊ true ���� 'T' ��ʾ������ false ���� 'F' ��ʾ������ʦ������ѧ�����Լ������𰸵Ĳ�ȷ���ԣ������� ��� �� ������ͬ �������������Ҳ������������ true ������������ false����
����һ���ַ��� answerKey ������ answerKey[i] �ǵ� i ���������ȷ������������⣬������һ������ k ����ʾ���ܽ������²�������������
ÿ�β����У����������ȷ�𰸸�Ϊ 'T' ���� 'F' ��Ҳ���ǽ� answerKey[i] ��Ϊ 'T' ���� 'F' ����
���㷵���ڲ����� k �β���������£���� ���� 'T' ���� 'F' ����Ŀ��
ʾ�� 1��
���룺answerKey = "TTFF", k = 2
�����4
���ͣ����ǿ��Խ����� 'F' ����Ϊ 'T' ���õ� answerKey = "TTTT" ��
�ܹ����ĸ������� 'T' ��
ʾ�� 2��
���룺answerKey = "TFFT", k = 1
�����3
���ͣ����ǿ��Խ���ǰ��� 'T' ���� 'F' ���õ� answerKey = "FFFT" ��
���ߣ����ǿ��Խ��ڶ��� 'T' ���� 'F' ���õ� answerKey = "TFFF" ��
��������£��������������� 'F' ��
ʾ�� 3��
���룺answerKey = "TTFTTFTT", k = 1
�����5
���ͣ����ǿ��Խ���һ�� 'F' ���� 'T' ���õ� answerKey = "TTTTTFTT" ��
�������ǿ��Խ��ڶ��� 'F' ���� 'T' ���õ� answerKey = "TTFTTTTT" ��
��������£�������������� 'T' ��
��ʾ��
n == answerKey.length
1 <= n <= 5 * 10^4
answerKey[i] Ҫô�� 'T' ��Ҫô�� 'F'
1 <= k <= n
*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        auto getAns = [&] (char c) -> int {
            int n = 0, i, j;
            for (i = 0, j = 0; j < answerKey.size(); j++)
            {
                if (answerKey[j] == c)
                    n++;
                if (n > k && answerKey[i++] == c)
                    n--;
            }
            return j - i;
        };
        return max(getAns('T'), getAns('F'));
    }
};

//���޸ĵ����ַ� T������ָ��ά���м� T �ĸ�������ָ��ÿ������һ�Ρ�
//���м� T �������� k ʱ����ָ������һ�Σ�����˫ָ��֮��ĳ��ȼ���� F ���ȡ�

