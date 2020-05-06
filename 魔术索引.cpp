/*
ħ�������� ������A[0...n-1]�У�����ν��ħ����������������A[i] = i������һ�������������飬��дһ�ַ����ҳ�ħ�����������еĻ���������A���ҳ�һ��ħ�����������û�У��򷵻�-1�����ж��ħ����������������ֵ��С��һ����
ʾ��1:
 ���룺nums = [0, 2, 3, 4, 5]
 �����0
 ˵��: 0�±��Ԫ��Ϊ0
ʾ��2:
 ���룺nums = [1, 1, 1]
 �����1
��ʾ:
nums������[1, 1000000]֮��
*/

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == i)
                return i;
        return -1;
    }
};

// ���ַ�
class Solution {
private:
    void binary_search(vector<int>& nums, int left, int right, int& ret){
        // ��֦
        if (ret != -1 && ret < left)
			return;
        if (left <= right)
		{
            int mid = left + (right - left) / 2;
            // ����ҵ�Ŀ�����������Ҫ�����ܷ��ҵ���С������ֵ
            if (nums[mid] == mid)
			{
                if (ret == -1)
					ret = mid;
                else if (mid < ret)
					ret = mid;
                binary_search(nums, left, mid - 1, ret);
            }
            // ���mid������Ҫ������Ҫ��mid���߼�������
			else
			{
                binary_search(nums, left, mid - 1, ret);
                binary_search(nums, mid + 1, right, ret);
            }
        }
    }
public:
    int findMagicIndex(vector<int>& nums) {
        int ret = -1;
        binary_search(nums, 0, nums.size()-1, ret);
        return ret;
    }
};
