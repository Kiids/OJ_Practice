/*
����һ������ 0, 1, 2, ..., n �� n ���������У��ҳ� 0 .. n ��û�г����������е��Ǹ�����
ʾ�� 1:
����: [3,0,1]
���: 2
ʾ�� 2:
����: [9,6,4,2,3,5,7,0,1]
���: 8
˵��:
����㷨Ӧ��������ʱ�临�Ӷȡ����ܷ��ʹ�ö��ⳣ���ռ���ʵ��?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            if(i != nums[i])
                return i;
        return nums.size();
    }
};

// ���
// nums.size()�Ĵ�С��Ϊn,��0��n���,����ͬʱ���nums[0]��nums[n-1],��2n+1����,
// ��ͬ���������Ϊ0, 0 ^ a = a,�������Ľ����ȱʧ������
class Solution {
public:
    int missingNumber(vector<int>& nums) {
	    int ret = nums.size();
	    for (int i = 0; i < nums.size(); i++)
	        ret = ret ^ i ^ nums[i];            // a^b^b = a;
	    return ret ;
    }
};

// ��ѧ���
class Solution {
public:
    int missingNumber(vector<int>& nums) {
	    int sum = 0, n = nums.size();
	    for (int n : nums)   
	        sum += n;
	    return (n * (n + 1)) / 2 - sum;
    }
};

// ����
class Solution {
public:
    int missingNumber(vector<int>& nums) {
	    sort(nums.begin(), nums.end());
	    int left = 0, right = nums.size(), mid = (left + right) / 2;
	    while (left < right)
	    {
	        mid = (left + right) / 2;
	        if (nums[mid] > mid)
				right = mid;
	        else
				left = mid + 1;
	    }
	    return left;
    }
};

// ���򣨲���������������
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            if(i != nums[i])
                return i;
        return nums.size();
    }
};
