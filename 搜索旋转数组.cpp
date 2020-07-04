/*
������ת���顣����һ�����������飬����n������������������ѱ���ת���ܶ���ˣ��������ꡣ���д�����ҳ������е�ĳ��Ԫ�أ���������Ԫ��ԭ���ǰ��������еġ����ж����ͬԪ�أ���������ֵ��С��һ����
ʾ��1:
 ����: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 5
 ���: 8��Ԫ��5�ڸ������е�������
ʾ��2:
 ���룺arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 11
 �����-1 ��û���ҵ���
��ʾ:
arr ���ȷ�Χ��[1, 1000000]֮��
*/

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        if (right == -1)
            return -1;
        while (left < right)                                           // ѭ����������left==right
        {
            int mid = left + (right - left) / 2;
            if (arr[left] < arr[mid])                                  // �����ֵС����ֵ��˵�������������
            {
                if (arr[left] <= target && target <= arr[mid])         // ���Ŀ������ߵ����������У��ұ߽��ƶ���mid
                    right = mid;                                       
                else                                                   // ����Ŀ�����Ұ�ߣ���߽��ƶ���mid+1
                    left = mid + 1;
            }
            else if (arr[left] > arr[mid])                             // �����ֵ������ֵ��˵����߲��������Ұ������
            {
                if (arr[left] <= target || target <= arr[mid])         // ���Ŀ������ߣ��ұ߽��ƶ���mid
                    right = mid;                                       
                else                                                   // ����Ŀ�����Ұ�ߣ���߽��ƶ���mid+1
                    left = mid + 1;
            }
            else if (arr[left] == arr[mid])                            // �����ֵ������ֵ���������Ѿ��ҵ���Ŀ�꣬Ҳ�������������ظ�ֵ
            {
                if (arr[left] != target)                               // �����ֵ������Ŀ�꣬˵����û�ҵ�����Ҫ��һ�����ظ�ֵ��
                    left++;
                else                                                   // �����ֵ����Ŀ�꣬˵���Ѿ��ҵ�����ߵ�Ŀ��ֵ 
                    right = left;                                      // ���ұ߽��ƶ���left��ѭ������
            }
        }
        return (arr[left] == target) ? left : -1;                      // ����left������-1
    }
};
