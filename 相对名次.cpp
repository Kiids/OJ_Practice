/*
���� N ���˶�Ա�ĳɼ����ҳ����ǵ�������β�����ǰ������Ӧ�Ľ��ơ�ǰ�����˶�Ա���ᱻ�ֱ����� �����ơ��������ơ� �͡� ͭ�ơ���"Gold Medal", "Silver Medal", "Bronze Medal"����
(ע������Խ�ߵ�ѡ�֣�����Խ��ǰ��)
ʾ�� 1:
����: [5, 4, 3, 2, 1]
���: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
����: ǰ�����˶�Ա�ĳɼ�Ϊǰ���ߵģ���˽���ֱ����� �����ơ��������ơ��͡�ͭ�ơ� ("Gold Medal", "Silver Medal" and "Bronze Medal").
���µ������˶�Ա������ֻ��Ҫͨ�����ǵĳɼ����㽫��������μ��ɡ�
��ʾ:
N ��һ�����������Ҳ��ᳬ�� 10000��
�����˶�Ա�ĳɼ�������ͬ��
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> v(n);
        map<int, int> m;
        for (int i = 0; i < n; i++)
            m[nums[i]] = i;
        for (const auto &e : m)
            v[e.second] = sort(n--);
        return v;
    }

    string sort(int n)
    {
        if (n == 1)
            return "Gold Medal";
        if (n == 2)
            return "Silver Medal";
        if (n == 3)
            return "Bronze Medal";
        return to_string(n);
    }
};
