/*
�������� [1,2,3,...,n]��������Ԫ�ع��� n! �����С�
����С˳���г����������������һһ��ǣ��� n = 3 ʱ, �����������£�
"123"
"132"
"213"
"231"
"312"
"321"
���� n �� k�����ص� k �����С�
ʾ�� 1��
���룺n = 3, k = 3
�����"213"
ʾ�� 2��
���룺n = 4, k = 9
�����"2314"
ʾ�� 3��
���룺n = 3, k = 1
�����"123"
��ʾ��
1 <= n <= 9
1 <= k <= n!
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        v[0] = 1;
        for(int i = 1; i < n; i++)
            v[i] = i * v[i - 1];
            
        k--;
        string s;
        vector<int> nums;
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        for (int i = 1; i <= n; i++)
        {
            int order = k / v[n - i];
            s.push_back(nums[order] + '0');
            for (int j = order; j < n - i; j++)
                nums[j] = nums[j + 1];
            k %= v[n - i];
        }
        return s;
    }
};
