/*
给定 N 个无限容量且初始均空的水缸，每个水缸配有一个水桶用来打水，第 i 个水缸配备的水桶容量记作 bucket[i]。小扣有以下两种操作：
升级水桶：选择任意一个水桶，使其容量增加为 bucket[i]+1
蓄水：将全部水桶接满水，倒入各自对应的水缸
每个水缸对应最低蓄水量记作 vat[i]，返回小扣至少需要多少次操作可以完成所有水缸蓄水要求。
注意：实际蓄水量 达到或超过 最低蓄水量，即完成蓄水要求。
示例 1：
输入：bucket = [1,3], vat = [6,8]
输出：4
解释：
第 1 次操作升级 bucket[0]；
第 2 ~ 4 次操作均选择蓄水，即可完成蓄水要求。
示例 2：
输入：bucket = [9,0,1], vat = [0,2,2]
输出：3
解释：
第 1 次操作均选择升级 bucket[1]
第 2~3 次操作选择蓄水，即可完成蓄水要求。
提示：
1 <= bucket.length == vat.length <= 100
0 <= bucket[i], vat[i] <= 10^4
*/

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int maxVat = 0, ret = INT_MAX;
        for (int v : vat)
            maxVat = max(maxVat, v);
        if (maxVat == 0)
            return 0;
        for (int i = 1; i <= maxVat; i++)
        {
            int add = 0;
            for (int j = 0; j < vat.size(); j++)
            {
                int expBucket = vat[j] % i == 0 ? vat[j] / i : vat[j] / i + 1;  // 枚举蓄水次数
                add += max(expBucket - bucket[j], 0);                           // 升级次数
            }
            ret = min(ret, add + i);
        }
        return ret;
    }
};

// 显然所有「升级水桶」的操作在「蓄水」操作之前
// 枚举「蓄水」次数，倒推出每个水桶的容量，并计算出「升级水桶」的操作次数
// 枚举「蓄水」的次数 k，那么对于容量为 v 的水缸，就至少需要一个容量为 v / k 向上取整。
// 这样计算出每个水桶需要「升级」多少次

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int time = 0;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < bucket.size(); i++)
        {
            if (vat[i] == 0)
                continue;
            if (bucket[i] == 0)
            {
                time++;
                bucket[i]++;
            }
            pq.push({(vat[i] - 1) / bucket[i] + 1, bucket[i], i});
        }

        int ret = INT_MAX;
        while (!pq.empty())
        {
            auto q = pq.top();
            pq.pop();
            if (time >= ret)
                break;
            ret = min(ret, q[0] + time);

            int i = q[2];
            int x = q[1] + 1;
            pq.push({(vat[i] - 1) / x + 1, x, i});
            time++;
        }
        return ret == INT_MAX ? 0 : ret;
    }
};

// 需要升级水桶才能达到更短时间，那么在所有倒水操作之前先升级桶
// 将还需要倒几次水作为参考数量，加入优先队列
// 除法和余数的关系向上取整，使需要倒水次数最多的缸在堆顶，每次拿出来升级水桶，同时计算此时的操作次数
// 不断升级水桶，不断记录和更新最少的操作次数，最后得到答案

