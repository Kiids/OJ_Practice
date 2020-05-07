/*
����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
ע�⣺�����������ԭ�������Ķ�
ʾ�� 1��
���룺[3,0,1]
�����2
ʾ�� 2��
���룺[9,6,4,2,3,5,7,0,1]
�����8
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int t = nums[i];
            while (t != n && nums[t] != t) 
            {
                int index = t;
                int x = nums[index];
                nums[index] = t;
                t = x;              
            }
        }
        
        for (int i = 0; i < n; i++)
            if (nums[i] != i)
                return i;
        
        return n;
    }
};

// ���
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int cmp = n * (n + 1) >> 1;
        return cmp - sum;
    }
}; 
