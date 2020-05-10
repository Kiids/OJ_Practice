/*
ϡ�������������и��ź�����ַ������飬����ɢ����һЩ���ַ�������дһ�ַ������ҳ������ַ�����λ�á�
ʾ��1:
 ����: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 �����-1
 ˵��: �����ڷ���-1��
ʾ��2:
 ���룺words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 �����4
��ʾ:
words�ĳ�����[1, 1000000]֮��
*/

class Solution {
public:
    int findString(vector<string>& words, string s) {
        if (words.size() == 0)
            return -1;
        int l = 0, r = words.size() - 1;
        while (l <= r)
        {
            while (l <= r && words[l] == "")
                l++;
            while (l <= r && words[r] == "")
                r--;
            int m = l + (r - l) / 2;
            while (m < r && words[m] == "")
                m++;
            if (words[m] == s)
                return m;
            else if (words[m] > s)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};
