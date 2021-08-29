/*
�����ĸ����������������б� A , B , C , D ,�����ж��ٸ�Ԫ�� (i, j, k, l) ��ʹ�� A[i] + B[j] + C[k] + D[l] = 0��
Ϊ��ʹ����򵥻������е� A, B, C, D ������ͬ�ĳ��� N���� 0 �� N �� 500 �����������ķ�Χ�� -2^28 �� 2^28 - 1 ֮�䣬���ս�����ᳬ�� 2^31 - 1 ��
����:
����:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
���:
2
����:
����Ԫ������:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        for (int a : nums1)
            for (int b : nums2)
                m[a + b]++;
        int count = 0; 
        for (int c : nums3)
            for (int d : nums4)
                if (m.find(0 - (c + d)) != m.end())
                    count += m[0 - (c + d)];
        return count;
    }
};
