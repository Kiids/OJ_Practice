/*
��������������ͬ���������� target �� arr ��
ÿһ���У������ѡ�� arr ������ �ǿ������� ��������ת�������ִ�д˹�������Ρ�
��������� arr ����� target ��ͬ������ True�����򣬷��� False ��
ʾ�� 1��
���룺target = [1,2,3,4], arr = [2,4,1,3]
�����true
���ͣ�����԰������²���ʹ arr ��� target��
1- ��ת������ [2,4,1] ��arr ��� [1,4,2,3]
2- ��ת������ [4,2] ��arr ��� [1,2,4,3]
3- ��ת������ [4,3] ��arr ��� [1,2,3,4]
��������������Ψһ�ģ������ڶ��ֽ� arr ��� target �ķ�����
ʾ�� 2��
���룺target = [7], arr = [7]
�����true
���ͣ�arr ����Ҫ���κη�ת�Ѿ��� target ��ȡ�
ʾ�� 3��
���룺target = [1,12], arr = [12,1]
�����true
ʾ�� 4��
���룺target = [3,7,9], arr = [3,7,11]
�����false
���ͣ�arr û������ 9 �������������Ҳ�޷���� target ��
ʾ�� 5��
���룺target = [1,1,1,1,1], arr = [1,1,1,1,1]
�����true
��ʾ��
target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000
*/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
