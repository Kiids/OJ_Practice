/*
���������� 0 �� 1 ��ɵ����� A�����Ƕ��� N_i���� A[0] �� A[i] �ĵ� i �������鱻����Ϊһ�������������������Чλ�������Чλ����
���ز���ֵ�б� answer��ֻ�е� N_i ���Ա� 5 ����ʱ���� answer[i] Ϊ true������Ϊ false��
ʾ�� 1��
���룺[0,1,1]
�����[true,false,false]
���ͣ�
��������Ϊ 0, 01, 011��Ҳ����ʮ�����е� 0, 1, 3 ��ֻ�е�һ�������Ա� 5 ��������� answer[0] Ϊ�档
ʾ�� 2��
���룺[1,1,1]
�����[false,false,false]
ʾ�� 3��
���룺[0,1,1,1,1,1]
�����[true,false,false,false,true,false]
ʾ�� 4��
���룺[1,1,1,0,1]
�����[false,false,false,false,false]
��ʾ��
1 <= A.length <= 30000
A[i] Ϊ 0 �� 1
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> v(nums.size());
        int num = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            num <<= 1;
            num += nums[i];
            num %= 10;
            v[i] = (num % 5 == 0);
        }
        return v;
    }
};
