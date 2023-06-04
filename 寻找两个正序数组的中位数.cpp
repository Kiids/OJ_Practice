/*
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��
�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��
ʾ�� 1��
���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2
ʾ�� 2��
���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5
��ʾ��
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        const int k = len / 2;   // ������ż�������ص�index����(len - 1) / 2 �� len / 2, �������������index��ȣ�ż������һǰһ��
        int i = 0, j = 0;
        double ret1 = 0, ret2 = 0;  // ��¼һǰһ��
        // push_back(INT_MAX)���Բ����ж�nums1����nums2��������
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        while (i + j <= k)
        {
            ret1 = ret2;
            ret2 = nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++];
        }
        return len % 2 == 1 ? ret2 : (ret1 + ret2) / 2;
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), k = 0, i = 0, j = 0;
        vector<int> v(m + n, 0);
        while (i < m && j < n)
            v[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        while (i < m)
            v[k++] = nums1[i++];
        while (j < n)
            v[k++] = nums2[j++];
        return k % 2 ? v[k / 2] : (v[k / 2] + v[k / 2 - 1]) / 2.0;  // �ж���ż
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0, l = 0, r = 0;
        for (int x = 0; x <= (m + n) / 2; x++)
        {
            l = r;
            if (i < m && (j >= n || nums1[i] < nums2[j]))
                r = nums1[i++];
            else
                r = nums2[j++];
        }
        return (m + n) & 1 ? r : (l + r) / 2.0;
    }
};
