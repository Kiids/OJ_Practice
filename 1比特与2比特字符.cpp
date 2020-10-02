/*
有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。
现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。
示例 1:
输入: 
bits = [1, 0, 0]
输出: True
解释: 
唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
示例 2:
输入: 
bits = [1, 1, 1, 0]
输出: False
解释: 
唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
注意:
1 <= len(bits) <= 1000.
bits[i] 总是0 或 1.
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n >= 2)
        {
            if (bits[n - 2] == 1)
            {
                int cnt = 1;
                for (int i = n - 3; i >= 0; i--)
                {
                    if (bits[i] != 1)
                        break;
                    else
                        cnt++;
                }
                return cnt % 2 == 1 ? false : true;
            }
            else
                return true;
        }
        return true;
    }
};
// 直接计算尾部连续的1的个数，当个数为奇数时，末尾的0必须与1结合；当为偶数时，0单列
