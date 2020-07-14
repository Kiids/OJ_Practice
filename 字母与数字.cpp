/*
给定一个放有字符和数字的数组，找到最长的子数组，且包含的字符和数字的个数相同。
返回该子数组，若存在多个最长子数组，返回左端点最小的。若不存在这样的数组，返回一个空数组。
示例 1:
输入: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
示例 2:
输入: ["A","A"]
输出: []
提示：
array.length <= 100000
*/

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int num[100005];
	    //数字+1，字母-1保存在num,num从1下标开始存
	    map<int,int> m;
	    for (int i = 0; i < array.size(); i++)
	    {
		    if (isdigit(array[i][0]))
                num[i + 1] = num[i] + 1;
    		else
                num[i + 1] = num[i] - 1;
    	}
	    int ans = 0;
	    int start = 0;
	    int end = 0;
	    for (int i = 1; i <= array.size(); i++)  //查看num
	    {
		    if (num[i] != 0 && m[num[i]] == 0)
                m[num[i]] = i;  //记录数字第一次出现的地方 如果num[i]=0 就说明是从头第一个字符开始的，m[0]=0；
		    else  //num[i]之前已经出现过，或者num[i]=0
		    {
			    if (ans < i-m[num[i]])
			    {
    				ans = i - m[num[i]];
				    start = m[num[i]] + 1;  //是从第一次出现的后面那个位置开始的
				    end = i;
			    }
		    }
        }
        //num是从1开始记录的所以把start和end都往前挪一挪
        start--;
        end--;
        vector<string> ret;
        if (start == end)
            return ret;
        for (int i = start; i <= end; i++)
            ret.push_back(array[i]);
        return ret;
    }
};
/*
首先建立一个num数组，如果array[i][0]是数字，就+1，如果是字母，-1。这样子我们就可以得到一个前缀和数组，
比如[0,1,2,3,1,2,0]。两个相同的数字之间就是字母和数字个数相等的长度（因为+1,-1抵消，
就会变成之前出现的原来那个一样的数）
建立map<int,int>哈希表记录map[0]第一次出现的位置
如果map[i]==0而num[i]又不等于0，就说明这是num[i]第一次出现的位置
如果map[i]=0.说明是从头第一个字符开始往后计算
然后用i-map[num[i]]和子数组最长长度作比较，i是当前num[i]所在位置，map[num[i]]是num[i]第一次出现的位置
*/
