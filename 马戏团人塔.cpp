/*
有个马戏团正在设计叠罗汉的表演节目，一个人要站在另一人的肩膀上。出于实际和美观的考虑，在上面的人要比下面的人矮一点且轻一点。已知马戏团每个人的身高和体重，请编写代码计算叠罗汉最多能叠几个人。
示例：
输入：height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
输出：6
解释：从上往下数，叠罗汉最多能叠 6 层：(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
提示：
height.length == weight.length <= 10000
*/

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>> tmp;
        for (int i = 0; i < height.size(); i++)
            tmp.push_back({height[i], weight[i]});

        sort(tmp.begin(), tmp.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });

        vector<int> dp; //长度为N的地方 最小的数字
        for (const auto &[h, w]: tmp)
        {
            auto p = lower_bound(dp.begin(), dp.end(), w);  //二分查找第一个大于等于的地方
            if (p == dp.end())
                dp.push_back(w);
            else *p = w;
        }
        return dp.size();
    }
};
