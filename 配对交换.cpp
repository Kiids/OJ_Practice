/*
��Խ�������д���򣬽���ĳ������������λ��ż��λ������ʹ�ý��ٵ�ָ�Ҳ����˵��λ0��λ1������λ2��λ3�������Դ����ƣ���
ʾ��1:
 ���룺num = 2������0b10��
 ��� 1 (���� 0b01)
ʾ��2:
 ���룺num = 3
 �����3
��ʾ:
num�ķ�Χ��[0, 2^30 - 1]֮�䣬���ᷢ�����������
*/

class Solution {
public:
    int exchangeBits(int num) {
        return ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1);
    }
};
//0xaaaaaaaa 10101010101010101010101010101010 (ż��λΪ1������λΪ0��
//0x55555555 01010101010101010101010101010101 (ż��λΪ0������λΪ1��
//even + odd �� even | odd ����һ��
//int even = (num & 0xaaaaaaaa) >> 1 ��ȡ��ǰ���ֵ�ż��λ��Ȼ�������ƶ�һλ
//int odd = (num & 0x55555555) << 1 ��ȡ��ǰλ�������� Ȼ�������ƶ�һλ
//return even | odd

class Solution {
public:
    int exchangeBits(int num) {
        string s = "";
        while (num) 
		{
            if (num & 1) 
				s += '1';
            else 
				s += '0';
            num >>= 1;
        }
        if ((int)s.size() & 1) 
			s += '0';
        int cnt = 1, ans = 0;
        for (int i = 0; i < s.size(); i += 2) 
		{
            swap(s[i], s[i + 1]);
            if (s[i] == '1') 
				ans += cnt;
            cnt <<= 1;
            if (s[i+1] == '1') 
				ans += cnt;
            cnt <<= 1;
        }
        return ans;
    }
};
