/*
�ҳ��������ظ������֡�
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
ʾ�� 1��
���룺
[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3 
���ƣ�
2 <= n <= 100000
*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> s;
        int ret = nums[0];
        for (auto e : nums)
        {
            if (s.insert(e).second == false)
            {
                ret = e;
                break;
            }
        }
        return ret;
    }
};

// ԭ���û��㷨
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(i != nums[i]) {  //���������±��Ӧ����
                if(nums[i] == nums[nums[i]])  //���׼���ƶ��������Ѿ����ڶ�Ӧλ���ϵ�������˵�������ظ�
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};

