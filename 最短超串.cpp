/*
���������������飬һ����һ���̣��̵�Ԫ�ؾ�����ͬ���ҵ��������а������������е�Ԫ�ص���������飬�����˳���޹ؽ�Ҫ��
����������������˵���Ҷ˵㣬���ж�����������������飬������˵���С��һ�����������ڣ����ؿ����顣
ʾ�� 1:
����:
big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7]
small = [1,5,9]
���: [7,10]
ʾ�� 2:
����:
big = [1,2,3]
small = [4]
���: []
��ʾ��
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
