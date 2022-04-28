/*
���������ַ��� s1 �� s2 ��дһ���������ж� s2 �Ƿ���� s1 �����С�����ǣ����� true �����򣬷��� false ��
���仰˵��s1 ������֮һ�� s2 �� �Ӵ� ��
ʾ�� 1��
���룺s1 = "ab" s2 = "eidbaooo"
�����true
���ͣ�s2 ���� s1 ������֮һ ("ba").
ʾ�� 2��
���룺s1= "ab" s2 = "eidboaoo"
�����false
��ʾ��
1 <= s1.length, s2.length <= 10^4
s1 �� s2 ������Сд��ĸ
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), k = s1.size();
        unordered_map<char, int> hash;
        for (auto c: s1)
            hash[c] ++ ;
        int cnt = 0, t = hash.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            if (--hash[s2[i]] == 0)
                cnt++;
            while (i - j + 1 > k)
            {
                if (!hash[s2[j]])
                    cnt--;
                hash[s2[j++]]++ ;
            }
            if (cnt == t)
                return true;
        }
        return false;
    }
};
