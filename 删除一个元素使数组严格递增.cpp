/*
����һ���±�� 0 ��ʼ���������� nums ����� ǡ�� ɾ�� һ�� Ԫ�غ����� �ϸ���� ����ô���㷵�� true �����򷵻� false ��������鱾���Ѿ����ϸ�����ģ�����Ҳ���� true ��
���� nums �� �ϸ���� �Ķ���Ϊ�����������±�� 1 <= i < nums.length ������ nums[i - 1] < nums[i] ��
ʾ�� 1��
���룺nums = [1,2,10,5,7]
�����true
���ͣ��� nums ��ɾ���±� 2 ���� 10 ���õ� [1,2,5,7] ��
[1,2,5,7] ���ϸ�����ģ����Է��� true ��
ʾ�� 2��
���룺nums = [2,3,1,2]
�����false
���ͣ�
[3,1,2] ��ɾ���±� 0 ��Ԫ�غ�õ��Ľ����
[2,1,2] ��ɾ���±� 1 ��Ԫ�غ�õ��Ľ����
[2,3,2] ��ɾ���±� 2 ��Ԫ�غ�õ��Ľ����
[2,3,1] ��ɾ���±� 3 ��Ԫ�غ�õ��Ľ����
û���κν���������ϸ�����ģ����Է��� false ��
ʾ�� 3��
���룺nums = [1,1,1]
�����false
���ͣ�ɾ������Ԫ�غ�Ľ������ [1,1] ��
[1,1] �����ϸ�����ģ����Է��� false ��
ʾ�� 4��
���룺nums = [1,2,3]
�����true
���ͣ�[1,2,3] �Ѿ����ϸ�����ģ����Է��� true ��
��ʾ��
2 <= nums.length <= 1000
1 <= nums[i] <= 1000
*/

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MAX);
        bool flag = 1;
        for (int i = 1; i < nums.size() - 1 ; i++)
        {
            if (nums[i - 1] >= nums[i])
                if (flag)
                {
                    if (nums[i - 1] < nums[i + 1] || nums[i] > nums[i - 2])
                        flag = 0;
                    else
                        return false;
                }
                else
                    return false;
        }
        return true;
    }
};
