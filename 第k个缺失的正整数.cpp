/*
����һ�� �ϸ��������� ������������ arr ��һ������ k ��
�����ҵ����������� k ��ȱʧ����������
ʾ�� 1��
���룺arr = [2,3,4,7,11], k = 5
�����9
���ͣ�ȱʧ������������ [1,5,6,8,9,10,12,13,...] ���� 5 ��ȱʧ��������Ϊ 9 ��
ʾ�� 2��
���룺arr = [1,2,3,4], k = 2
�����6
���ͣ�ȱʧ������������ [5,6,7,...] ���� 2 ��ȱʧ��������Ϊ 6 ��
��ʾ��
1 <= arr.length <= 1000
1 <= arr[i] <= 1000
1 <= k <= 1000
�������� 1 <= i < j <= arr.length �� i �� j ���� arr[i] < arr[j] 
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        for (i = 0; i < arr.size(); i++)
            if (arr[i] - i - 1 >= k)
                return k + i;
        return k + i;
    }
};

// ���ֲ���
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size(), mid = 0;
        while(left<right){
            mid = left + (right-left)/2;
            if(arr[mid]-mid >= k+1){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return k + left;
    }
};
