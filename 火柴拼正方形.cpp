/*
�㽫�õ�һ���������� matchsticks ������ matchsticks[i] �ǵ� i �������ĳ��ȡ���Ҫ�� ���еĻ��� ƴ��һ�������Ρ��� �����۶� �κ�һ��������������԰���������һ�𣬶���ÿ���������� ʹ��һ�� ��
�������ʹ��������Σ��򷵻� true �����򷵻� false ��
ʾ�� 1:
����: matchsticks = [1,1,2,2,2]
���: true
����: ��ƴ��һ���߳�Ϊ2�������Σ�ÿ���������
ʾ�� 2:
����: matchsticks = [3,3,3,3,4]
���: false
����: ���������л��ƴ��һ�������Ρ�
��ʾ:
1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 10^8
*/

class Solution {
    bool DFS(int index, vector<int>& matchsticks, int target, vector<int>& bucket)
    {
        //indexΪ��ǰ���������±꣬matchsticksΪ�߳����飬targetΪĿ��߳���bucket��ʾ��ǰÿ���ߵĳ���
        if (index >= matchsticks.size()) // ÿ���߶�����
            return (bucket[0] == bucket[1]) && (bucket[1] == target) && (bucket[2] == target);
        for (int i = 0; i < 4; i++)
        { // ����ǰ�ı߷���4��Ͱ�зֱ���
            if (bucket[i] + matchsticks[index] > target)
                continue; // ˵�������Է����������
            bucket[i] += matchsticks[index]; // �������ñߺ����dfs
            if (DFS(index + 1, matchsticks, target, bucket))
                return true;
            bucket[i] -= matchsticks[index]; // ע����ݵĻָ�״̬
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4)
            return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4)
            return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); 
        // �Ӵ�С��������ѡ�ô�ı߿�����ɹ���������췵��
        vector<int> bucket(4); // ����4���ߵ�ֵ
        return DFS(0, matchsticks, sum / 4, bucket);
    }
};
