/*
 n ��ʿ��վ��һ�š�ÿ��ʿ������һ�� ��һ�޶� ������ rating ��
ÿ 3 ��ʿ���������һ����ս��λ������������£�
�Ӷ�����ѡ���±�ֱ�Ϊ i��j��k �� 3 ��ʿ�������ǵ����ֱַ�Ϊ rating[i]��rating[j]��rating[k]
��ս��λ�����㣺 rating[i] < rating[j] < rating[k] ���� rating[i] > rating[j] > rating[k] ������  0 <= i < j < k < n
���㷵�ذ��������������齨����ս��λ������ÿ��ʿ���������Ƕ����ս��λ��һ���֡�
ʾ�� 1��
���룺rating = [2,5,3,4,1]
�����3
���ͣ����ǿ����齨������ս��λ (2,3,4)��(5,4,1)��(5,3,1) ��
ʾ�� 2��
���룺rating = [2,1,3]
�����0
���ͣ�������Ŀ�����������޷��齨��ս��λ��
ʾ�� 3��
���룺rating = [1,2,3,4]
�����4
��ʾ��
n == rating.length
3 <= n <= 1000
1 <= rating[i] <= 10^5
rating �е�Ԫ�ض���Ψһ��
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3)
            return 0;
        int ret = 0;
        for (int j = 1; j < n - 1; j++)
        {
            int smaller_cnt_l = 0;
            int bigger_cnt_l = 0;
            int smaller_cnt_r = 0;
            int bigger_cnt_r = 0;
            for (int i = 0; i < j; i++)
            {
                if(rating[i] < rating[j])
                    smaller_cnt_l++;
                else
                    bigger_cnt_l++;
            }
            for (int k = j + 1; k < n; k++)
            {
                if(rating[k] < rating[j])
                    smaller_cnt_r++;
                else
                    bigger_cnt_r++;
            }
            ret += smaller_cnt_l * bigger_cnt_r + bigger_cnt_l * smaller_cnt_r;
        }
        return ret;
    }
};
