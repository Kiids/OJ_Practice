/*
������һ���Ǹ��������� arr�����ʼλ�ڸ��������ʼ�±� start ��������λ���±� i ��ʱ����������� i + arr[i] ���� i - arr[i]��
�����ж��Լ��Ƿ��ܹ�������ӦԪ��ֵΪ 0 �� ��һ �±괦��
ע�⣬������ʲô����£��㶼�޷���������֮�⡣
ʾ�� 1��
���룺arr = [4,2,3,0,3,1,2], start = 5
�����true
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 5 -> �±� 4 -> �±� 1 -> �±� 3 
�±� 5 -> �±� 6 -> �±� 4 -> �±� 1 -> �±� 3 
ʾ�� 2��
���룺arr = [4,2,3,0,3,1,2], start = 0
�����true 
���ͣ�
����ֵΪ 0 ���±� 3 �����¿��ܷ����� 
�±� 0 -> �±� 4 -> �±� 1 -> �±� 3
ʾ�� 3��
���룺arr = [3,0,2,1,2], start = 2
�����false
���ͣ��޷�����ֵΪ 0 ���±� 1 ���� 
��ʾ��
1 <= arr.length <= 5 * 10^4
0 <= arr[i] < arr.length
0 <= start < arr.length
*/

class Solution {
public:
    bool visited[50009];
    bool DFS(vector<int>& arr, int start, int n)
    {
        if (arr[start] == 0)
            return true;
        else
        {
            visited[start] = 1;
            bool flag = false;
            
            if (start + arr[start] >= 0 && arr[start] + start < n && !visited[arr[start] + start])
                flag |= DFS(arr, arr[start] + start, n);
            if (start - arr[start] >= 0 && start - arr[start] < n && !visited[start - arr[start]])
                flag |= DFS(arr, start - arr[start], n);
            return flag;
        } 
    }

    bool canReach(vector<int>& arr, int start) {
        return DFS(arr, start, arr.size());
    }
};
