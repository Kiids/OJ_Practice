/*
����һ���ַ�������дһ�������ж����Ƿ�Ϊĳ�����Ĵ�������֮һ��
���Ĵ���ָ������������һ���ĵ��ʻ���������ָ��ĸ���������С�
���Ĵ���һ�����ֵ䵱�еĵ��ʡ�
ʾ��1��
���룺"tactcoa"
�����true��������"tacocat"��"atcocta"���ȵȣ�
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if (s.size() == 0)
            return false;

        set<char> se;
        for (auto e : s)
        {
            if (!se.insert(e).second)
                se.erase(e);
        }
        return se.size() <= 1;
    }
};
