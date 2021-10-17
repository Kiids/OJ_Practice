/*
����һ���������� nums ������㷨������һ��û���ظ�Ԫ�ص����顣
ʵ�� Solution class:
Solution(int[] nums) ʹ���������� nums ��ʼ������
int[] reset() �������鵽���ĳ�ʼ״̬������
int[] shuffle() ��������������Һ�Ľ��
ʾ����
����
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
���
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
����
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // �������� [1,2,3] �����ؽ�����κ� [1,2,3]�����з��صĸ���Ӧ����ͬ�����磬���� [3, 1, 2]
solution.reset();      // �������鵽���ĳ�ʼ״̬ [1, 2, 3] ������ [1, 2, 3]
solution.shuffle();    // ����������� [1, 2, 3] ���Һ�Ľ�������磬���� [1, 3, 2]
��ʾ��
1 <= nums.length <= 200
-10^6 <= nums[i] <= 10^6
nums �е�����Ԫ�ض��� Ψһ��
�����Ե��� 5 * 10^4 �� reset �� shuffle
*/

class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> v = vector<int>(nums);
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int pos = rand() % (n - i) + i;
            swap(v, i, pos);
        }
        return v;
    }

     void swap(vector<int>& v, int i, int j){
        int t = v[i];
        v[i] = v[j];
        v[j] = t;
     }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
