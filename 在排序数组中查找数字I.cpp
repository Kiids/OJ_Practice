/*
ͳ��һ�����������������г��ֵĴ�����
ʾ�� 1:
����: nums = [5,7,7,8,8,10], target = 8
���: 2
ʾ�� 2:
����: nums = [5,7,7,8,8,10], target = 6
���: 0
���ƣ�
0 <= ���鳤�� <= 50000
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int i = -1;
        while (end >= begin)
        {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] > target)
                end = mid - 1;
            else if (nums[mid] == target)
            {
                i = mid;
                break;
            }
            else
                begin = mid + 1;
        }
        if (i == -1)
            return 0;
        int left = i, right = i;
        while (left >= 0 && nums[left] == target)
            left--;
        while (right < nums.size() && nums[right] == target)
            right++;
        return right - left - 1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return count(nums.begin(), nums.end(), target);
    }
};
