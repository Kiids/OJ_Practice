/*
����һ���±�� 0 ��ʼ���������� nums ��һ������ pivot �����㽫 nums �������У�ʹ������������������
����С�� pivot ��Ԫ�ض����������д��� pivot ��Ԫ�� ֮ǰ ��
���е��� pivot ��Ԫ�ض�������С�ںʹ��� pivot ��Ԫ�� �м� ��
С�� pivot ��Ԫ��֮��ʹ��� pivot ��Ԫ��֮��� ���˳�� �������ı䡣
����ʽ�ģ�����ÿһ�� pi��pj ��pi �ǳ�ʼʱλ�� i Ԫ�ص���λ�ã�pj �ǳ�ʼʱλ�� j Ԫ�ص���λ�á�����С�� pivot ��Ԫ�أ���� i < j �� nums[i] < pivot �� nums[j] < pivot ����������ô pi < pj Ҳ���������Ƶģ����ڴ��� pivot ��Ԫ�أ���� i < j �� nums[i] > pivot �� nums[j] > pivot ����������ô pi < pj ��
���㷵���������� nums �����Ľ�����顣
ʾ�� 1��
���룺nums = [9,12,5,10,14,3,10], pivot = 10
�����[9,5,3,10,10,12,14]
���ͣ�
Ԫ�� 9 ��5 �� 3 С�� pivot ���������������������ߡ�
Ԫ�� 12 �� 14 ���� pivot ��������������������ұߡ�
С�� pivot ��Ԫ�ص����λ�úʹ��� pivot ��Ԫ�ص����λ�÷ֱ�Ϊ [9, 5, 3] �� [12, 14] �������ڽ�������е����˳����Ҫ������
ʾ�� 2��
���룺nums = [-3,4,3,2], pivot = 2
�����[-3,2,4,3]
���ͣ�
Ԫ�� -3 С�� pivot �����������������ߡ�
Ԫ�� 4 �� 3 ���� pivot ��������������������ұߡ�
С�� pivot ��Ԫ�ص����λ�úʹ��� pivot ��Ԫ�ص����λ�÷ֱ�Ϊ [-3] �� [4, 3] �������ڽ�������е����˳����Ҫ������
��ʾ��
1 <= nums.length <= 10^5
-106 <= nums[i] <= 10^6
pivot ���� nums �е�һ��Ԫ�ء�
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a, b, c;

        for (int e : nums)
        {
            if (e < pivot)
                a.push_back(e);
            else if (e == pivot)
                b.push_back(e);
            else
                c.push_back(e);
        }
        a.insert(a.end(), b.begin(), b.end());
        a.insert(a.end(), c.begin(), c.end());
        return a;
    }
};
