/*
假设你有两个数组，一个长一个短，短的元素均不相同。找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。
返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。若不存在，返回空数组。
示例 1:
输入:
big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7]
small = [1,5,9]
输出: [7,10]
示例 2:
输入:
big = [1,2,3]
small = [4]
输出: []
提示：
big.length <= 100000
1 <= small.length <= 100000
*/

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        if (big.size() < small.size() || small.size() <= 0)
            return {};

        if (small.size() == 1)
        {
            int k = 0;
            for ( ; k < (int)big.size(); k++)
            {
                if (small[0] == big[k])
                    return {k, k};
            }
            return {};
        } 
        unordered_map<int,int> hash;
        vector<int> mem;
        int n = 0, m = 0, min = 0, max = INT_MAX;

        for (auto&& a : small)
            hash.insert({a, 0});

        for (int i = 0; i < (int)big.size(); i++)
        {
            auto res = hash.find(big[i]);
            if (res == hash.end())
                continue;
            res->second++;
            mem.push_back(i);
            if (res->second == 1)
                n++;
            if (n == small.size())
            {
                for (int j = m;j < (int)mem.size(); j++)
                {
                    hash[big[mem[j]]]--;
                    if (hash[big[mem[j]]] == 0)
                    {
                        n--;
                        m = j+1;
                        if (max - min > i - mem[j])
                        {
                            max = i;
                            min = mem[j];
                        }
                        break;
                    }
                }
            }
        }
        if (max != INT_MAX)
            return {min,max};

        return {};
    }
};
