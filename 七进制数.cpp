/*
����һ������������ת��Ϊ7���ƣ������ַ�����ʽ�����
ʾ�� 1:
����: 100
���: "202"
ʾ�� 2:
����: -7
���: "-10"
ע��: ���뷶Χ�� [-1e7, 1e7] ��
*/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
            
        bool flag = true;
        if (num < 0)
        {
            flag = false;
            num = -num;
        }

        string ret;
        while (num != 0)
        {
            ret += (char)(num % 7 + '0');
            num /= 7;
        }
        if (!flag)
            ret += '-';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// �ݹ�ⷨ
class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0)
            return "-" + convertToBase7(-1 * num);
        if (num < 7)
            return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
}; 
