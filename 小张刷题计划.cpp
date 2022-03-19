/*
Ϊ������Լ��Ĵ���������С���ƶ��� LeetCode ˢ��ƻ�����ѡ���� LeetCode ����е� n ���⣬��Ŵ� 0 �� n-1�����ƻ��� m ���ڰ�����Ŀ���˳��ˢ�����е���Ŀ��ע�⣬С�Ų����ö������ͬһ�⣩��
��С��ˢ��ƻ��У�С����Ҫ�� time[i] ��ʱ����ɱ�� i ����Ŀ�����⣬С�Ż�����ʹ�ó����������ܣ�ͨ��ѯ�����ĺ�����С����Ŀ�Ľⷨ������ʡȥ���������ʱ�䡣Ϊ�˷�ֹ��С��ˢ��ƻ�����ɡ�С��ˢ��ƻ�����С��ÿ�����ʹ��һ��������
���Ƕ��� m ��������ʱ������һ���ʱΪ T��С����ɵ���Ŀ������������ʱ�䣩�������С�������С�� T�Ƕ��١�
ʾ�� 1��
���룺time = [1,2,3,3], m = 2
�����3
���ͣ���һ��С�����ǰ���⣬���е�������С���æ���ڶ�����ɵ����⣬������С���æ����������ʱ������һ�컨���� 3 ��ʱ�䣬�������ֵ����С�ġ�
ʾ�� 2��
���룺time = [999,999,999], m = 4
�����0
���ͣ���ǰ�����У�С��ÿ������С��һ�Σ�������������������������е���Ŀ�������κ�ʱ�䡣
���ƣ�
1 <= time.length <= 10^5
1 <= time[i] <= 10000
1 <= m <= 1000
*/

class Solution {
    bool canSplit(vector<int>& time, int m, int split_sum)
    {
        int cnt = 0, sum = 0, maxT = 0;
        for (auto& t : time)
        {
            sum += t;
            maxT = max(maxT, t);
            if (sum - maxT > split_sum)
            {
                if (++cnt == m)
                    return false;
                sum = t;
                maxT = t;
            }
        }
        return true;
    }
public:
    int minTime(vector<int>& time, int m) {
        if (time.size() <= m)
            return 0;
        int l = 0, r = INT_MAX;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (canSplit(time, m, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};

//�ҵ�һ������������Ϊ�ָ�����������ĺ͵����ֵ
//����������ֵ���ָ����飬ʹÿ��������ĺͶ�������������ֵ
//	��������˳�����������
//ʹ�ö��ֲ�����ȷ�����ֵ
//	int l = 0, int r = INT_MAX; ���ֵ�п��ܱȵ�һһ��ֵ����
//	������ܽ��������������ֶ��ָ�������飬���ʾ������ֵ������
//	�����ǰ�ָ����ˣ�˵�����ֵȡ��̫����


bool check(vector<int>& a, int t, int m)                   // ÿ���ۼӺ���<=t������� �ܷ���m���ڷ���
{
    int cnt = 1, rest = t, maxx = -1;                      // cntΪ�ֵ������� restΪ��ǰ����ʣ������
    bool flag = true;                                      //��������
    for (int i = 0; i < a.size(); i++)
	{
        maxx = max(maxx, a[i]);                            // ά����ǰ������ֵ
        if (rest >= a[i])                                  // ��װ��ʱ��ֱ��װ
			rest -= a[i];
        else if (flag)
			flag = false, rest += maxx, i--;               // װ�����ҿ�������ʱ���ѵ�ǰ�����ʱ���Ǹ���ȥ����
        else
			cnt++, maxx = -1, flag = true, rest = t, i--;  // װ�������޷�����ʱ���ӵڶ��쿪ʼ(��ʼ��һ��)
    }
    return cnt <= m;                                       // m�����ܷ��꼴��(=m�����ܿ���)
}
int minTime(vector<int>& time, int m) {
    int n = time.size();
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)                            // ��ȡһ������ʱ�Ƕ���
		r += time[i];
    while (l < r)                                          // ���� l<= T <=r
	{
        int T = l + r >> 1;
        if (check(time, T, m))
			r = T;                                         // �ж��ڵ�ǰT���������ܷ���m���ڿ��� ������Ծͼ�СT �� r = T
        else
			l = T + 1;
    }
    return r;
}


