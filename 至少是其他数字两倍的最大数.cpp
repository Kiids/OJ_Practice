/*
����һ���������� nums ���������Ǵ��� Ψһ�� һ��������� ��
�����ҳ������е����Ԫ�ز�������Ƿ� ������������ÿ���������ֵ����� ������ǣ��򷵻� ���Ԫ�ص��±� �����򷵻� -1 ��
ʾ�� 1��
���룺nums = [3,6,1,0]
�����1
���ͣ�6 ���������������������е�����������6 ��������������Ԫ�ص�������6 ���±��� 1 �����Է��� 1 ��
ʾ�� 2��
���룺nums = [1,2,3,4]
�����-1
���ͣ�4 û�г��� 3 �����������Է��� -1 ��
ʾ�� 3��
���룺nums = [1]
�����0
���ͣ���Ϊ�������������֣�������Ϊ�������� 1 �������������ֵ�������
��ʾ��
1 <= nums.length <= 50
0 <= nums[i] <= 100
nums �е����Ԫ����Ψһ��
*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int first = INT_MIN, second = INT_MIN, index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > first)
            {
                second = first;
                first = nums[i];
                index = i;
            }
            else if (nums[i] > second)
                second = nums[i];
        }
        if (first < 2 * second)
            return -1;
        return index;
    }
};
