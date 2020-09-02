/*
�����������飬arr1 �� arr2��
arr2 �е�Ԫ�ظ�����ͬ
arr2 �е�ÿ��Ԫ�ض������� arr1 ��
�� arr1 �е�Ԫ�ؽ�������ʹ arr1 ��������˳��� arr2 �е����˳����ͬ��δ�� arr2 �г��ֹ���Ԫ����Ҫ����������� arr1 ��ĩβ��
ʾ����
���룺arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
�����[2,2,2,1,4,3,3,9,6,7,19]
��ʾ��
arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 �е�Ԫ�� arr2[i] ������ͬ
arr2 �е�ÿ��Ԫ�� arr2[i] �������� arr1 ��
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001);
	    for (int i = 0; i < arr1.size(); i++)
		    count[arr1[i]]++;
            
	    int k = 0;
	    for (int i = 0; i < arr2.size(); i++)
		    while (count[arr2[i]] > 0)
		    {
			    arr1[k++] = arr2[i];
			    count[arr2[i]]--;
		    }
            
	    for (int i = 0; i < count.size(); i++)
		    while (count[i] >0)
		    {
			    arr1[k++] = i;
			    count[i]--;
		    }
	    return arr1;
    }
};
