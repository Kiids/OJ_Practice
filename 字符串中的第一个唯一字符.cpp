// ����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
// ����:
// s = "leetcode"
// ���� 0.
// s = "loveleetcode",
// ���� 2.
// ע����������Լٶ����ַ���ֻ����Сд��ĸ��

class Solution {
public:
    int firstUniqChar(string s) {
        int count[256] = {0};
        int size = s.size();
        for (int i = 0; i < size; i++)
            count[s[i]]++;
        for (int i = 0; i < size; i++)
            if (count[s[i]] == 1)
                return i;
        return -1;
    }
};

