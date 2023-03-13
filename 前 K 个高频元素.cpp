/*
����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�
ʾ�� 1:
����: nums = [1,1,1,2,2,3], k = 2
���: [1,2]
ʾ�� 2:
����: nums = [1], k = 1
���: [1]
��ʾ��
1 <= nums.length <= 105
k ��ȡֵ��Χ�� [1, �����в���ͬ��Ԫ�صĸ���]
��Ŀ���ݱ�֤��Ψһ�����仰˵��������ǰ k ����ƵԪ�صļ�����Ψһ��
���ף���������㷨��ʱ�临�Ӷ� ���� ���� O(n log n) ������ n �������С��
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        vector<int> v;
        for (int e : nums)  // Ԫ�س���Ƶ��
            hashmap[e]++;

        int maxtimes = 0;   // ���Ƶ�ʴ���
        for (auto e : hashmap)
            if (e.second > maxtimes)
                maxtimes = e.second;
            
        while (k > 0)       // ��������� �������
        {
            for (auto e : hashmap)
            {
                if (e.second == maxtimes)
                {
                    v.push_back(e.first);
                    k--;
                } 
            }
            maxtimes--;
        }
        return v;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ��� hash map 
        unordered_map<int,int> m;
        for (int num : nums)
            m[num]++;

        // ���ȶ��� 
        priority_queue<pair<int, int>> q;
        // ���� m.second ʵ�ִ����
        for (auto i : m)
            q.emplace(i.second, i.first);
        
        // ���
        vector<int> ret;
        while (k)
        {
            ret.emplace_back(q.top().second);
            q.pop();
            k--;
        }
        return ret;
    }
};
