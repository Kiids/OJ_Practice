/*
����һ����������  nums�������������� i �� j��i �� j����Χ��Ԫ�ص��ܺͣ����� i��j ���㡣
ʵ�� NumArray �ࣺ
NumArray(int[] nums) ʹ������ nums ��ʼ������
int sumRange(int i, int j) �������� nums ������ i �� j��i �� j����Χ��Ԫ�ص��ܺͣ����� i��j ���㣨Ҳ���� sum(nums[i], nums[i + 1], ... , nums[j])��
ʾ����
���룺
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
�����
[null, 1, -1, -3]
���ͣ�
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
��ʾ��
0 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= i <= j < nums.length
������ 104 �� sumRange ����
*/

class NumArray {
    int* sum;  // sum[i] Ϊ nums[0 : i-1]�ĺ�
public:
    NumArray(vector<int>& nums) {
        sum = new int[nums.size() + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i++)
            sum[i] = sum[i - 1] + nums[i - 1];
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
