/*
����һ������Ϊ n ���������� nums������ n > 1������������� output ������ output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻���
ʾ��:
����: [1,2,3,4]
���: [24,12,8,6]
��ʾ����Ŀ���ݱ�֤����֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺���������������飩�ĳ˻����� 32 λ������Χ�ڡ�
˵��: �벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
���ף�
������ڳ����ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size(), 1);
        int l = 1, r = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            v[i] = r;
            r *= nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            v[i] = v[i] * l;
            l *= nums[i];
        }
        return v;
    }
};
