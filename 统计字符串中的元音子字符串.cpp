/*
���ַ��� ���ַ����е�һ���������ǿգ����ַ����С�
Ԫ�����ַ��� �� �� ��Ԫ����'a'��'e'��'i'��'o' �� 'u'����ɵ�һ�����ַ������ұ������ ȫ������ Ԫ����
����һ���ַ��� word ��ͳ�Ʋ����� word �� Ԫ�����ַ�������Ŀ ��
ʾ�� 1��
���룺word = "aeiouu"
�����2
���ͣ������г� word �е�Ԫ�����ַ�����б��Ӵֲ��֣���
- "aeiouu"
- "aeiouu"
ʾ�� 2��
���룺word = "unicornarihan"
�����0
���ͣ�word �в��� 5 ��Ԫ��������Ҳ�������Ԫ�����ַ�����
ʾ�� 3��
���룺word = "cuaieuouac"
�����7
���ͣ������г� word �е�Ԫ�����ַ�����б��Ӵֲ��֣���
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
ʾ�� 4��
���룺word = "bbaeixoubb"
�����0
���ͣ����а���ȫ������Ԫ�������ַ��������и��������Բ�����Ԫ�����ַ�����
��ʾ��
1 <= word.length <= 100
word ����СдӢ����ĸ���
*/

class Solution {
    unordered_set<char> st;
    int ret;
public:
    int countVowelSubstrings(string word) {
        for (int i = 0; i < int(word.size() - 4); i++)
        {
            st.clear();
            for (int j = i; j < word.size(); j++)
            {
                if (word[j] != 'a' && word[j] != 'e' && word[j] != 'i' && word[j] != 'o' && word[j] != 'u')
                    break;
                st.insert(word[j]);
                if (st.size() == 5)
                    ret++;
            }
        }
        return ret;
    }
};

