/*
����һ���ַ��� s ������ͳ�Ʋ���������ַ����� �����Ӵ� ����Ŀ��
�����ַ��� �����Ŷ��͵�������һ�����ַ�����
���ַ��� ���ַ����е��������ַ���ɵ�һ�����С�
���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ���
ʾ�� 1��
���룺s = "abc"
�����3
���ͣ����������Ӵ�: "a", "b", "c"
ʾ�� 2��
���룺s = "aaa"
�����6
���ͣ�6�������Ӵ�: "a", "a", "a", "aa", "aa", "aaa"
��ʾ��
1 <= s.length <= 1000
s ��СдӢ����ĸ���
*/

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            result += extend(s, i, i, s.size());      // ��iΪ����
            result += extend(s, i, i + 1, s.size());  // ��i��i+1Ϊ����
        }
        return result;
    }

    int extend(const string& s, int i, int j, int n) {
        int ret = 0;
        while (i >= 0 && j < n && s[i] == s[j])
        {
            i--;
            j++;
            ret++;
        }
        return ret;
    }
};

//����ȷ�����Ĵ���������Ȼ����������ɢ���Ƿ�Գơ�
//�������ĵ������������
//һ��Ԫ����Ϊ���ĵ㣬����Ԫ����Ϊ���ĵ㡣
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O(1)

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int ret = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1]))
                {
                    ret++;
                    dp[i][j] = true;
                }
            }
        }
        return ret;
    }
};
