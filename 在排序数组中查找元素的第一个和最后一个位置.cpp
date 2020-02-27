/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
��������в�����Ŀ��ֵ������ [-1, -1]��
ʾ�� 1:
����: nums = [5,7,7,8,8,10], target = 8
���: [3,4]
ʾ�� 2:
����: nums = [5,7,7,8,8,10], target = 6
���: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2);
        ret[0] = -1;
        ret[1] = -1;
        if (nums.size() == 0)
            return ret;
        int i = binarySearch(nums, target);
        if (i == -1)
            return ret;
        int l = i - 1;
        while (l >= 0 && nums[l] == target)
            l--;
        ret[0] = l + 1;
        int r = i + 1;
        while (r < nums.size() && nums[r] == target)
            r++;
        ret[1] = r - 1;
        return ret;
    }
    int binarySearch(vector<int>& n, int x)
    {
        int l = 0, r = n.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (n[mid] == x)
                return mid;
            else if (n[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
