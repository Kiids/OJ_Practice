/*
��Щ����������ֻ�� 3��5��7�������һ���㷨�ҳ��� k ������ע�⣬���Ǳ�������Щ�����ӣ����Ǳ��벻���������������ӡ����磬ǰ��������˳��Ӧ���� 1��3��5��7��9��15��21��
ʾ�� 1:
����: k = 5
���: 9
*/

class Solution {
public:
    int getKthMagicNumber(int k) {
        if (k <= 0)
            return 0;
        
        vector<long long int> nums(k+1, 1);  // Ϊ��ֹԽ�磬�� long long����
        int p3 = 0, p5 = 0, p7 = 0;  // ���"ĳ������"���±�
        for (int i = 1; i < k; i++)
        {
            nums[i] = min(min(3 * nums[p3], 5 * nums[p5]), 7 * nums[p7]);
            if (nums[i] == 3 * nums[p3])
                p3++; // p3++����Ϊ��p3���ڵ������������Сֵ���ʲ�������p3���ڵ����������һ����Сֵ����һ����Сֵ������3 * nums[p3+1]������p5++, p7++ͬ��
            if (nums[i] == 5 * nums[p5])
                p5++;  // ע��˴���if,������else if,��Ϊ����3 *nums[p3] == 5 * nums[p5] �� 7 * nums[p7] == 5 * nums[p5]�������ͬ��
            if (nums[i] == 7 * nums[p7])
                p7++;
        }
        return nums[k-1];
    }
};
