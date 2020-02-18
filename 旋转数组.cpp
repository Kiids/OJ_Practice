/*
����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
ʾ�� 1:
����: [1,2,3,4,5,6,7] �� k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]
ʾ�� 2:
����: [-1,-100,3,99] �� k = 2
���: [3,99,-1,-100]
����: 
������ת 1 ��: [99,-1,-100,3]
������ת 2 ��: [3,99,-1,-100]
˵��:
�������������Ľ�����������������ֲ�ͬ�ķ������Խ��������⡣
Ҫ��ʹ�ÿռ临�Ӷ�Ϊ O(1) �� ԭ�� �㷨��
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*int t = 0, len = nums.size();
        int l = k % len;
        for (int i = 0; i < l; i++)
        {
            t = nums[len - 1];
            for (int j = len - 2; j >= 0; j--)
                nums[j + 1] = nums[j];
            nums[0] = t;
        }  ����ʱ������
        */
        //ȷ���ƶ�����
        k %= nums.size();
        //��������������
        reserve(nums, 0, nums.size() - 1);
        //��ǰk������
        reserve(nums, 0, k-1);
        //���±�k�����鳤��֮������
        reserve(nums, k, nums.size() - 1);
    }
    void reserve(vector<int>& arr, int start, int end) 
	{
        while(start < end) 
		{
            int tmp = arr[end];
            arr[end--] = arr[start];
            arr[start++] = tmp;
        }
    }
};
