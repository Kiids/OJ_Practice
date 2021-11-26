/*
����ϲ�����㽶�������� N ���㽶���� i ������ piles[i] ���㽶�������Ѿ��뿪�ˣ����� H Сʱ�������
������Ծ��������㽶���ٶ� K ����λ����/Сʱ����ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� K �����������㽶���� K ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶��  
����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��
������������ H Сʱ�ڳԵ������㽶����С�ٶ� K��K Ϊ��������
ʾ�� 1��
����: piles = [3,6,7,11], H = 8
���: 4
ʾ�� 2��
����: piles = [30,11,23,4,20], H = 5
���: 30
ʾ�� 3��
����: piles = [30,11,23,4,20], H = 6
���: 23
��ʾ��
1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (fun(mid, piles, h) == true)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool fun(int speed, vector<int> & piles, int h)
    {
        int cnt = 0;
        for (int p : piles)
            cnt += ceil((double)p / speed);
        return cnt <= h;
    }
};
