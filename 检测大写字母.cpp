/*
����һ�����ʣ�����Ҫ�жϵ��ʵĴ�дʹ���Ƿ���ȷ��
���Ƕ��壬���������ʱ�����ʵĴ�д�÷�����ȷ�ģ�
ȫ����ĸ���Ǵ�д������"USA"��
������������ĸ�����Ǵ�д������"leetcode"��
������ʲ�ֻ����һ����ĸ��ֻ������ĸ��д��?����?"Google"��
�������Ƕ����������û����ȷʹ�ô�д��ĸ��
ʾ�� 1:
����: "USA"
���: True
ʾ�� 2:
����: "FlaG"
���: False
ע��: �������ɴ�д��Сд������ĸ��ɵķǿյ��ʡ�
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperIndex = 0;
        for (int i = 0; i < word.size(); i++)
            if (isupper(word[i]) && upperIndex++ < i)
                return false;
        
        return upperIndex == word.size() || upperIndex <= 1;
    }
};
