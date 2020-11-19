/*
���������������� nums �� index������Ҫ�������¹��򴴽�Ŀ�����飺
Ŀ������ target ���Ϊ�ա�
�������ҵ�˳�����ζ�ȡ nums[i] �� index[i]���� target �����е��±� index[i] ������ֵ nums[i] ��
�ظ���һ����ֱ���� nums �� index �ж�û��Ҫ��ȡ��Ԫ�ء�
���㷵��Ŀ�����顣
��Ŀ��֤���ֲ���λ�����Ǵ��ڡ�
ʾ�� 1��
���룺nums = [0,1,2,3,4], index = [0,1,2,2,1]
�����[0,4,1,3,2]
���ͣ�
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
ʾ�� 2��
���룺nums = [1,2,3,4,0], index = [0,1,2,3,0]
�����[0,1,2,3,4]
���ͣ�
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
ʾ�� 3��
���룺nums = [1], index = [0]
�����[1]
��ʾ��
1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i
*/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ret;
        for (int i = 0; i < index.size(); i++) 
            ret.insert(ret.begin() + index[i], nums[i]);
        return ret;
    }
};
