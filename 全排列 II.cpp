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

    void fun(vector<int>& nums)  // ˳�����
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

// ÿ�ΰ��ֵ�˳���쵱ǰ�����һ�����У�����һ���������һ�����ʱ�˳���
// ʱ�䣺O(n*n!);
// �ռ䣺O(n!);


class Solution {
    void backtrace(vector<int>& a, vector<vector<int>>& v, int level)
    {
        if (level == a.size())
        {
            v.push_back(a);
            return;
        }
        
        unordered_set<int> uniq;  
        for (int i = level; i < a.size(); i++)
        {
            if (uniq.count(a[i]))        // ö�ٵ�ʱ��ȥ��
                continue;
            swap(a[i], a[level]);
            backtrace(a, v, level + 1);  // ����
            swap(a[i], a[level]);
            uniq.insert(a[i]);           // ����ȥ��
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        backtrace(nums, v, 0);
        return v;
    }
};

// ����ö��ʱ��ȥ��

