/*
�и���Ϸ��������Ƶ��޺��ı��ݽ�Ŀ��һ����Ҫվ����һ�˵ļ���ϡ�����ʵ�ʺ����۵Ŀ��ǣ����������Ҫ��������˰�һ������һ�㡣��֪��Ϸ��ÿ���˵���ߺ����أ����д���������޺�����ܵ������ˡ�
ʾ����
���룺height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
�����6
���ͣ����������������޺�����ܵ� 6 �㣺(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
��ʾ��
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

        vector<int> dp; //����ΪN�ĵط� ��С������
        for (const auto &[h, w]: tmp)
        {
            auto p = lower_bound(dp.begin(), dp.end(), w);  //���ֲ��ҵ�һ�����ڵ��ڵĵط�
            if (p == dp.end())
                dp.push_back(w);
            else *p = w;
        }
        return dp.size();
    }
};
