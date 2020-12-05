/*
����һ������������ arr ������������п��ܵ���������������ĺ͡�
������ ����Ϊԭ�����е�һ�����������С�
���㷵�� arr �� ������������������ĺ� ��
ʾ�� 1��
���룺arr = [1,4,2,5,3]
�����58
���ͣ�����������������������ǵĺ�Ϊ��
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
���ǽ�����ֵ��͵õ� 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
ʾ�� 2��
���룺arr = [1,2]
�����3
���ͣ��ܹ�ֻ�� 2 ������Ϊ�����������飬[1] �� [2]�����ǵĺ�Ϊ 3 ��
ʾ�� 3��
���룺arr = [10,11,12]
�����66
��ʾ��
1 <= arr.length <= 100
1 <= arr[i] <= 1000
*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if (arr.empty())
            return 0;
        int ret = 0;
        // sum��0��Ϊ0����i��ֵ��ǰ׺sum[i+1]
        vector<int> sum(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++)
            sum[i + 1] = sum[i] + arr[i];

        // ��ʼλ�������ƶ�
        for (int start = 0; start < arr.size(); start++)
        {
            // ÿ����ʼλ�ã����������������������ֵ���ۼӺ�
            for (int l = 1; l <= arr.size(); l += 2) {
                int end = start + l;
                if (end > arr.size())
                    break;
                else
                    ret += sum[end] - sum[start];
            }
        }
        return ret;
    }
};
