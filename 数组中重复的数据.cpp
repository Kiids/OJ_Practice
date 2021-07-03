/*
����һ���������� a������1 �� a[i] �� n ��nΪ���鳤�ȣ�, ������ЩԪ�س������ζ�����Ԫ�س���һ�Ρ�
�ҵ����г������ε�Ԫ�ء�
����Բ��õ��κζ���ռ䲢��O(n)ʱ�临�Ӷ��ڽ�����������
ʾ����
����:
[4,3,2,7,8,2,3,1]
���:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v(nums.size()), ret;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i + 1)
                i++;
            else
            {
                int t = nums[i];
                if (nums[t - 1] == t)
                {
                    v[t - 1]++;
                    i++;
                }
                else
                    swap(nums[t - 1], nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (v[i])
                ret.push_back(i + 1);
        return ret;
    }
};
