/*
����һ���Ǹ��������� nums �������λ������ĵ�һ��λ�á�
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
���Ŀ����ʹ�����ٵ���Ծ����������������һ��λ�á�
���������ǿ��Ե�����������һ��λ�á�
ʾ�� 1:
����: nums = [2,3,1,1,4]
���: 2
����: �������һ��λ�õ���С��Ծ���� 2��
     ���±�Ϊ 0 �����±�Ϊ 1 ��λ�ã���?1?����Ȼ����?3?��������������һ��λ�á�
ʾ�� 2:
����: nums = [2,3,0,1,4]
���: 2
��ʾ:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0, start = 0, end = 1;
        while (end < nums.size())
        {
            int maxPos = 0;
            for (int i = start; i < end; i++)
                maxPos = max(maxPos, i + nums[i]);
            start = end;
            end = maxPos + 1;
            ret++;
        }
        return ret;
    }
};
