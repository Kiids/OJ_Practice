/*
����һ���ǵݼ��� ���� �������飬��֪���������ǡ����һ�����������ĳ��ִ�����������Ԫ�������� 25%��
�����ҵ��������������
ʾ����
���룺arr = [1,2,2,6,6,6,6,7,10]
�����6
��ʾ��
1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
            if (arr[i + arr.size() / 4] == arr[i])
                return arr[i];
        return 0;
    }
};
