/*
���һ����������������Ԫ����ɣ���ÿ��������Ԫ��֮��Ĳ�ֵ����ͬ����ô������о��� �Ȳ����� ������ʽ�أ����� s �ǵȲ����У�ֻ��Ҫ���㣺����ÿ����Ч�� i �� s[i+1] - s[i] == s[1] - s[0] ��������
���磬������Щ���� �Ȳ����� ��
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
��������� ���ǵȲ����� ��
1, 1, 2, 5, 7
����һ���� n ��������ɵ����� nums���������� m ��������ɵ����� l �� r�������������ʾ m �鷶Χ��ѯ�����е� i ����ѯ��Ӧ��Χ [l[i], r[i]] ������������±궼�� �� 0 ��ʼ �ġ�
���� boolean Ԫ�ع��ɵĴ��б� answer ����������� nums[l[i]], nums[l[i]+1], ... , nums[r[i]] ���� �������� �γ� �Ȳ����� ��answer[i] ��ֵ���� true������answer[i] ��ֵ���� false ��
ʾ�� 1��
���룺nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
�����[true,false,true]
���ͣ�
�� 0 ����ѯ����Ӧ������ [4,6,5] ��������������Ϊ�Ȳ����� [6,5,4] ��
�� 1 ����ѯ����Ӧ������ [4,6,5,9] ���޷����������γɵȲ����С�
�� 2 ����ѯ����Ӧ������ [5,9,3,7] ��������������Ϊ�Ȳ����� [3,5,7,9] ��
ʾ�� 2��
���룺nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
�����[false,true,false,false,true,true]
��ʾ��
n == nums.length
m == l.length
m == r.length
2 <= n <= 500
1 <= m <= 500
0 <= l[i] < r[i] < n
-10^5 <= nums[i] <= 10^5
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ret;
        for (int i = 0; i < l.size(); i++)
        {
            vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ret.push_back(isArithmetic(tmp));
        }
        return ret;
    }

    bool isArithmetic(vector<int> &v)
    {
        if (v.size() == 0 || v.size() == 1)
            return true;
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size() - 1; i++)
            if (v[i + 1] - v[i] != v[i] - v[i - 1])
                return false;
        return true;
    }
};
