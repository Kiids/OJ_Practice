/*
����һ���������� arr ����ʹ�� �����ת ��ɶ����������
һ�μ����ת��ִ�й������£�
ѡ��һ������ k ��1 <= k <= arr.length
��ת������ arr[0...k-1]���±�� 0 ��ʼ��
���磬arr = [3,2,1,4] ��ѡ�� k = 3 ����һ�μ����ת����ת������ [3,2,1] ���õ� arr = [1,2,3,4] ��
��������ʽ������ʹ arr ����ļ����ת��������Ӧ�� k ֵ���С��κν����������ҷ�ת������?10 * arr.length ��Χ�ڵ���Ч�𰸶������ж�Ϊ��ȷ��
ʾ�� 1��
���룺[3,2,4,1]
�����[4,2,4,3]
���ͣ�
����ִ�� 4 �μ����ת��k ֵ�ֱ�Ϊ 4��2��4���� 3��
��ʼ״̬ arr = [3, 2, 4, 1]
��һ�η�ת��k = 4����arr = [1, 4, 2, 3]
�ڶ��η�ת��k = 2����arr = [4, 1, 2, 3]
�����η�ת��k = 4����arr = [3, 2, 1, 4]
���Ĵη�ת��k = 3����arr = [1, 2, 3, 4]����ʱ��������� 
ʾ�� 2��
���룺[1,2,3]
�����[]
���ͣ�
�����Ѿ�������˲���Ҫ��ת�κ����ݡ�
��ע�⣬�������ܵĴ𰸣��� [3��3] ��Ҳ�����ж�Ϊ��ȷ��
��ʾ��
1 <= arr.length <= 100
1 <= arr[i] <= arr.length
arr �е���������������ͬ������arr �Ǵ� 1 �� arr.length ������һ�����У�
*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> v;
        for (int i = arr.size() - 1; i > 0; i--)
        {
            int j = max_element(arr.begin(), arr.begin() + i + 1) - arr.begin();
            if (j > 0)
            {
                reverse(arr.begin(), arr.begin() + j + 1);
                v.push_back(j + 1);
            }
            reverse(arr.begin(), arr.begin() + i + 1);
            v.push_back(i + 1);
        }
        return v;
    }
};

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> v;
        for (int i = arr.size() - 1; i > 0; i--)
        {
            int max_i = max_element(arr.begin(), arr.begin() + i + 1) - arr.begin();
            if (max_i == i)
                continue;
            reverse(arr.begin(), arr.begin() + max_i + 1);
            reverse(arr.begin(), arr.begin() + i + 1);
            v.push_back(max_i + 1);
            v.push_back(i + 1);
        }
        return v;
    }
};
