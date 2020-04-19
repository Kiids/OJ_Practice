/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
ʾ����
���룺nums =?[1,2,3,4]
�����[1,3,2,4] 
ע��[3,1,2,4] Ҳ����ȷ�Ĵ�֮һ��
��ʾ��
1 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/
// ��β˫ָ��
//����ͷָ�� leftleft ��βָ�� rightright .
//leftleft һֱ�����ƣ�ֱ����ָ���ֵΪż��
//rightright һֱ�����ƣ� ֱ����ָ���ֵΪ����
//���� nums[left]nums[left] �� nums[right]nums[right] .
//�ظ�����������ֱ�� left == rightleft==right .
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if ((nums[left] & 1) != 0)
            {
                left++;
                continue;
            }
            if ((nums[right] & 1) != 1)
            {
                right--;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

// ����˫ָ��
//�������˫ָ�� fastfast �� lowlow ��fastfast ��ǰ�� lowlow �ں� .
//fastfast ����������ǰ��������λ�ã�lowlow ��������ָ����һ������Ӧ����ŵ�λ��
//fastfast ��ǰ�ƶ�����������������ʱ�������� nums[low]nums[low] ��������ʱ lowlow ��ǰ�ƶ�һ��λ�� .
//�ظ�����������ֱ�� fastfast ָ������ĩβ .
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] & 1)
            {
                swap(nums[low], nums[fast]);
                low++;
            }
            fast++;
        }
        return nums;
    }
}; 

// ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
// ���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

// ���·�����LeetCode�л���ֳ�ʱ���� 
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        int even = 0;
        int odd = 0;
         
        while (even < len)
        {
            if (array[even] % 2 != 0)
            {
                int tmp = array[even];
                for (int i = even; i > odd; i--)
                    array[i] = array[i-1];
                 
                array[odd] = tmp;
                even++;
                odd++;
            }
            else
                even++;
        }
    }
};
 
//�������±�odd,even,even�������飬����ż�����������ߣ����������ͽ�����������odd��Ӧλ�ã�
//Ȼ��odd�����ƶ����Ƚ���odd��ʼ��λ�õ�����Ԫ������Ų��һ������������Ŀ�����ܹ�����ż�����λ�ò��䣩��
//���˼·Ҳ����ʹ��oddǰ��Ķ����������������λ�ò��䣬��odd��even֮��Ķ���ż����Ȼ��even��������ͣ������
//������ŵ�oddλ�ã�����ǰ���ǽ�oddλ���ϵ�ż�����Ų����֤ż�����λ�ò��䣬������even�ߵ����ʱ��
//��ʹ��odd֮ǰ�Ķ���������odd��even֮��Ķ���ż����

