/*
����һ���� n ��������ɵ�����?nums ����һ��Ŀ��ֵ target �������ҳ���������������ȫ�������Ҳ��ظ�����Ԫ��?[nums[a], nums[b], nums[c], nums[d]] ����������Ԫ��Ԫ��һһ��Ӧ������Ϊ������Ԫ���ظ�����
0 <= a, b, c, d < n
a��b��c �� d ������ͬ
nums[a] + nums[b] + nums[c] + nums[d] == target
����԰� ����˳�� ���ش� ��
ʾ�� 1��
���룺nums = [1,0,-1,0,-2,2], target = 0
�����[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
ʾ�� 2��
���룺nums = [2,2,2,2,2], target = 8
�����[[2,2,2,2]]
��ʾ��
1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > target && nums[k] >= 0)  // ��֦
            	break;
            if (k > 0 && nums[k] == nums[k - 1])  // ��nums[k]ȥ��
                continue;
            for (int i = k + 1; i < nums.size(); i++)
            {
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)  // ��֦
                    break;
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;

                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;
                    else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target)
                        left++;
                    else
                    {
                        v.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1])  // ��nums[right]ȥ��
                            right--;
                        while (right > left && nums[left] == nums[left + 1])    // ��nums[left]ȥ��
                            left++;
                        // �ҵ���ʱ��˫ָ������
                        right--;
                        left++;
                    }
                }
            }
        }
        return v;
    }
};

// ����֮�ͣ�������֮�Ͷ�ʹ��˫ָ�뷨, �����ⷨ������֮�͵Ļ���������һ��forѭ��
