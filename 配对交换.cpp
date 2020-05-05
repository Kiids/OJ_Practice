/*
配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。
示例1:
 输入：num = 2（或者0b10）
 输出 1 (或者 0b01)
示例2:
 输入：num = 3
 输出：3
提示:
num的范围在[0, 2^30 - 1]之间，不会发生整数溢出。
*/

class Solution {
public:
    int exchangeBits(int num) {
        return ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1);
    }
};
//0xaaaaaaaa 10101010101010101010101010101010 (偶数位为1，奇数位为0）
//0x55555555 01010101010101010101010101010101 (偶数位为0，奇数位为1）
//even + odd 和 even | odd 性质一样
//int even = (num & 0xaaaaaaaa) >> 1 获取当前数字的偶数位，然后向右移动一位
//int odd = (num & 0x55555555) << 1 获取当前位数的奇数 然后向左移动一位
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
