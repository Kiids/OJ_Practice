/*
����һ������ 0 �� ���� ����?nums ��ÿ�� nums[i] ����ʾλ���±� i �Ľ�ɫӦ����ǰ������ƶ����±������
��� nums[i] ����������ǰ���±���������ƶ� |nums[i]| ��
��� nums[i] �Ǹ���������±�ݼ������ƶ� |nums[i]| ��
��Ϊ������ ���� �ģ����Կ��Լ�������һ��Ԫ����ǰ�ƶ�һ���ᵽ���һ��Ԫ�أ�����һ��Ԫ������ƶ�һ���ᵽ�����һ��Ԫ�ء�
�����е� ѭ�� �ɳ���Ϊ k ���±����� seq ��ʶ��
��ѭ�����ƶ����򽫵���һ���ظ��±����� seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
���� nums[seq[j]] Ӧ������ ȫ�� ���� ȫ��
k > 1
��� nums �д���ѭ�������� true �����򣬷��� false ��
ʾ�� 1��
���룺nums = [2,-1,1,2,2]
�����true
���ͣ�����ѭ�������±� 0 -> 2 -> 3 -> 0 ��ѭ������Ϊ 3 ��
ʾ�� 2��
���룺nums = [-1,2]
�����false
���ͣ����±� 1 -> 1 -> 1 ... ���˶��޷�����ѭ������Ϊѭ���ĳ���Ϊ 1 �����ݶ��壬ѭ���ĳ��ȱ������ 1 ��
ʾ�� 3:
���룺nums = [-2,1,-1,-2,-2]
�����false
���ͣ����±� 1 -> 2 -> 1 -> ... ���˶��޷�����ѭ������Ϊ nums[1] ���������� nums[2] �Ǹ�����
���� nums[seq[j]] Ӧ������ȫ������ȫ����
��ʾ��
1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
nums[i] != 0
���ף��������һ��ʱ�临�Ӷ�Ϊ O(n) �Ҷ���ռ临�Ӷ�Ϊ O(1) ���㷨��
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int x){
            return ((x + nums[x]) % n + n) % n;
        };
        auto same = [&](int &x, int y){
            return nums[x] * nums[y] > 0;
        };
        for (int i = 0; i < n; i++)
        {
            if (!nums[i])
                continue;            
            int slow = i, fast = next(i);
            while (same(slow, fast) && same(slow, next(fast)))
            {
                if (slow == fast)
                {
                    if (slow != next(slow))
                        return true;
                    else
                        break;
                }
                slow = next(slow);
                fast = next(next(fast));
            }
        }
        return false;
    }
};
