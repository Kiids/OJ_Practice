/*
����һ���������� arr�������ж��������Ƿ������������Ԫ�ض��������������������ڣ��뷵�� true �����򣬷��� false ��
ʾ�� 1��
���룺arr = [2,6,4,1]
�����false
���ͣ���������������Ԫ�ض��������������
ʾ�� 2��
���룺arr = [1,2,34,3,4,5,7,23,12]
�����true
���ͣ�������������Ԫ�ض���������������� [5,7,23] ��
��ʾ��
1 <= arr.length <= 1000
1 <= arr[i] <= 1000
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool flag = false;
        int counter = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 == 1)
                counter++;
            else
                counter = 0;

            if (counter == 3)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
};
