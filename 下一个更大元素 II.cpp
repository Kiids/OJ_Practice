/*
����һ��ѭ������ nums �� nums[nums.length - 1] ����һ��Ԫ���� nums[0] �������� nums ��ÿ��Ԫ�ص� ��һ������Ԫ�� ��
���� x �� ��һ�������Ԫ�� �ǰ��������˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ��������������һ�������������������ڣ������ -1 ��
ʾ�� 1:
����: nums = [1,2,1]
���: [2,-1,2]
����: ��һ�� 1 ����һ����������� 2��
���� 2 �Ҳ�����һ����������� 
�ڶ��� 1 ����һ����������Ҫѭ�����������Ҳ�� 2��
ʾ�� 2:
����: nums = [1,2,3,4,3]
���: [2,3,4,-1,4]
��ʾ:
1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
*/

class Solution {
    stack<int> s;
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1);
        for (int i = 0; i < 2 * n; i++)
        {
            while (!s.empty() && nums[i % n] > nums[s.top()])
            {
                v[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }
        return v;
    }
};
