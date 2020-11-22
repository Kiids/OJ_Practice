/*
�������� û���ظ�Ԫ�� ������ nums1 �� nums2 ������nums1 �� nums2 ���Ӽ����ҵ� nums1 ��ÿ��Ԫ���� nums2 �е���һ��������ֵ��
nums1 ������ x ����һ������Ԫ����ָ x �� nums2 �ж�Ӧλ�õ��ұߵĵ�һ���� x ���Ԫ�ء���������ڣ���Ӧλ����� -1 ��
ʾ�� 1:
����: nums1 = [4,1,2], nums2 = [1,3,4,2].
���: [-1,3,-1]
����:
    ����num1�е�����4�����޷��ڵڶ����������ҵ���һ����������֣������� -1��
    ����num1�е�����1���ڶ�������������1�ұߵ���һ���ϴ������� 3��
    ����num1�е�����2���ڶ���������û����һ����������֣������� -1��
ʾ�� 2:
����: nums1 = [2,4], nums2 = [1,2,3,4].
���: [3,-1]
����:
    ���� num1 �е����� 2 ���ڶ��������е���һ���ϴ������� 3 ��
    ���� num1 �е����� 4 ���ڶ���������û����һ����������֣������� -1 ��
��ʾ��
nums1��nums2������Ԫ����Ψһ�ġ�
nums1��nums2 �������С��������1000��
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;

        // �����һ����x����� 
        for (auto num2 : nums2)
        {
            while (!s.empty() && num2 > s.top())
            {
                m[s.top()] = num2;
                s.pop();
            }
            s.emplace(num2);
        }

        // û�и������
        while (!s.empty())
        {
            m[s.top()] = -1;
            s.pop();
        }

        vector<int> v;
        for (auto num1 : nums1)
            v.emplace_back(m[num1]);
        return v;
    }
};
