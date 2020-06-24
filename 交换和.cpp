/*
给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。
返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。
示例:
输入: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
输出: [1, 3]
示例:
输入: array1 = [1, 2, 3], array2 = [4, 5, 6]
输出: []
提示：
1 <= array1.length, array2.length <= 100000
*/


class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int diff = 0;
        unordered_map<int,int> un_map1, un_map2;
        // diff 统计两数字之差 
        for (int i = 0; i < array1.size(); i++)
        {   
            diff += array1[i];
            un_map1[array1[i]]++;
        }
        for (int i = 0; i < array2.size(); i++)
        {
            diff -= array2[i];
            un_map2[array2[i]]++;
        }
        // 如果数组之差不能被2整除，则找不到可交换的
        if (diff & 1)
            return {};
        // 寻找可交换的数对
        int temp = 0;
        for (auto iter = un_map1.begin(); iter != un_map1.end(); iter++)
        {
            temp = iter->first - (diff >> 1);
            if(un_map2[temp] != 0)
                return {iter->first, temp};
        }
        return {};
    }
};
