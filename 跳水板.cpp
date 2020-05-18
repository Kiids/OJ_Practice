/*
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。
返回的长度需要从小到大排列。
示例：
输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}
提示：
0 < shorter <= longer
0 <= k <= 100000
*/

// 结果是一个首项为 shorter * k ，公差为 longer - shorter ，不大于 longer * k 的等差数列 
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ret;
        if (k == 0)
            return ret;
        if (shorter == longer)
            return vector<int>(1, k * shorter);
        
        int min = shorter * k;
        int max = longer * k;
        while (min < max + 1)
        {
            ret.push_back(min);
            min += longer - shorter;
        }
        return ret;
    }
};
