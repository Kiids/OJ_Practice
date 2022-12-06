/*
����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�
ʾ�� 1��
���룺nums = [1,1,2]
�����
[[1,1,2],
 [1,2,1],
 [2,1,1]]
ʾ�� 2��
���룺nums = [1,2,3]
�����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
��ʾ��
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        while(true)
        {
        	v.push_back(nums);
        	fun(nums);
            if (nums == v[0])
            	break;
        }
        return v;	
    }

    void fun(vector<int>& nums)
    {
		int i = nums.size() - 2, k;
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
		for(k = i + 1; k <= (nums.size() + i) / 2; k++)
        	swap(nums[k], nums[nums.size() - (k - i)]);
        k = i + 1;
        while(i >= 0 && k < nums.size() && nums[k] <= nums[i])
            k++;
		if(i >= 0 && k < nums.size())
			swap(nums[i], nums[k]);
    }
};

//ÿ�ΰ��ֵ�˳���쵱ǰ�����һ�����У�����һ���������һ�����ʱ�˳���
//ʱ�䣺O(n*n!);
//�ռ䣺O(n!);

