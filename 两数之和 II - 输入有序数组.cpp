/*
����һ���Ѱ��� ��������  ���������� numbers ��������������ҳ��������������֮�͵���Ŀ���� target ��
����Ӧ���Գ���Ϊ 2 �������������ʽ���������������±�ֵ��numbers ���±� �� 1 ��ʼ���� �����Դ�����Ӧ������ 1 <= answer[0] < answer[1] <= numbers.length ��
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ�� 1��
���룺numbers = [2,7,11,15], target = 9
�����[1,2]
���ͣ�2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��
ʾ�� 2��
���룺numbers = [2,3,4], target = 6
�����[1,3]
ʾ�� 3��
���룺numbers = [-1,0], target = -1
�����[1,2]
��ʾ��
2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers �� ����˳�� ����
-1000 <= target <= 1000
������һ����Ч��
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, x = 0;
        int l, r, mid;
        vector<int> ret;
        while (i < numbers.size() -1)
        {
            x = target - numbers[i];
            l = i + 1; 
            r = numbers.size() -1 ;
            while (l < r)
            {
                mid = l + (r - l) / 2;
                if (numbers[mid] < x)
                    l = mid + 1;
                else
                    r = mid;
            }
            if (numbers[l] == x)
            {
                ret.emplace_back(i + 1);
                ret.emplace_back(l + 1);
                break;
            }
            i++;
        }
        return ret;
    }
};
