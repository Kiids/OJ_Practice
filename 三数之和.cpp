/*
����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ����
�㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣
ʾ�� 1��
���룺nums = [-1,0,1,2,-1,-4]
�����[[-1,-1,2],[-1,0,1]]
���ͣ�
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 ��
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 ��
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 ��
��ͬ����Ԫ���� [-1,0,1] �� [-1,-1,2] ��
ע�⣬�����˳�����Ԫ���˳�򲢲���Ҫ��
ʾ�� 2��
���룺nums = [0,1,1]
�����[]
���ͣ�Ψһ���ܵ���Ԫ��Ͳ�Ϊ 0 ��
ʾ�� 3��
���룺nums = [0,0,0]
�����[[0,0,0]]
���ͣ�Ψһ���ܵ���Ԫ���Ϊ 0 ��
��ʾ��
3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        for (int i = 0; i < n - 1; i++)                      // ���������鵹����������
        {
            if (nums[i] == 0)
            {
                if (nums[i + 2] == 0)
                    v.push_back({0, 0, 0});
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])             // ȥ�أ�ÿ��ѭ����һ������ͬ
                continue;

            int l = i + 1, r = n;
            while (l < r)
            {
                if (nums[l] + nums[r] < -nums[i])
                    l++;
                else if (nums[l] + nums[r] > -nums[i])
                    r--;
                else
                {
                    v.push_back({nums[i], nums[l], nums[r]});
                    if (nums[l] == nums[r])                  // ȥ�أ���������ͬ����ѭ��
                        break;
                    while (l < r && nums[l + 1] == nums[l])  // �ҵ���һ����l�����
                        l++;
                    l++;
                    while (l < r && nums[r - 1] == nums[r])  // �ҵ���һ����rС����
                        r--;
                    r--;
                }
            }
        }
        return v;
    }
};
