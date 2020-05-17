/*
给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。
示例 1：
输入: num = 1775(110111011112)
输出: 8
示例 2：
输入: num = 7(01112)
输出: 4
*/

class Solution {
public:
    int reverseBits(int num) {
        int pre = 0, cur = 0, ret = 1;
        for (int i = 0; i < 32; i++)
        {
            if (num & (1 << i))
                cur++;
            else
            {
                ret = max(ret, pre + cur);
                pre = cur + 1;
                cur = 0;
            }
        }
        ret = max(ret, pre + cur);
        return ret;
    }
};

//pre表示上一个连续1的长度+1
//cur表示当前连续1的长度
//结果即为最大的pre+cur
//注意循环结束时需要再次更新res, 因为有可能最高位是1
