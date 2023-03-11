/*
����һ���ǿ��������飬�ҵ�ʹ��������Ԫ������������С�ƶ���������ÿ���ƶ��ɽ�ѡ����һ��Ԫ�ؼ�1���1�� �����Լ�������ĳ������Ϊ10000��
����:
����:
[1,2,3]
���:
2
˵����
ֻ�����������Ǳ�Ҫ�ģ��ǵ�ÿһ������ʹ����һ��Ԫ�ؼ�1���1���� 
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ret = 0, i = 0, j = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (i < j)
            ret += nums[j--] - nums[i++];
        return ret;
    }
};

// ˫ָ�� 
// ת��Ϊ��������n���㵽ĳ�������͵���Сֵ�����ҵ����ʹ�������С�ĵ㡪��λ�� 
// ��������ߵ��м䣬����������䳤�ȣ�ֱ��û�����ɼ�Ϊֹ��

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int mid = nums[N / 2], ret = 0;
        for (int n : nums)
            ret += abs(n - mid);
        return ret;
    }
};

// ����
// ȡ��λ��
// ���㽫���������ƶ�����λ����Ҫ�ƶ����ٴΣ����ۼ�

