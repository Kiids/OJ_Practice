/*
���죬����ϰ���һ�ҵ������Ӫҵ customers.length ���ӡ�ÿ���Ӷ���һЩ�˿ͣ�customers[i]���������꣬������Щ�˿Ͷ�������һ���ӽ������뿪��
��ĳЩʱ������ϰ�������� �������ϰ��ڵ� i ������������ô grumpy[i] = 1������ grumpy[i] = 0�� ������ϰ�����ʱ����һ���ӵĹ˿;ͻ᲻���⣬������������������ġ�
����ϰ�֪��һ�����ܼ��ɣ��������Լ����������������Լ����� X ���Ӳ���������ȴֻ��ʹ��һ�Ρ�
���㷵����һ��Ӫҵ����������ж��ٿͻ��ܹ��е����⡣
ʾ����
���룺customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
�����16
���ͣ�
����ϰ������ 3 ���ӱ����侲��
�е���������ͻ����� = 1 + 1 + 1 + 1 + 7 + 5 = 16.
��ʾ��
1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0, right = minutes, sum = 0;
        for (int i = left; i < right; i++)
            if (grumpy[i])
                sum += customers[i];
        
        int ret = sum;
        while (right < grumpy.size())
        {
            right++;
            if (grumpy[right - 1])
                sum += customers[right - 1];
            if (grumpy[left])
                sum -= customers[left];
            left++;
            ret = max(ret, sum);
        }
        for (int i = 0; i < grumpy.size(); i++)
            if (!grumpy[i])
                ret += customers[i];
        return ret;
    }
};
