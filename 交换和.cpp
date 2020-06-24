/*
���������������飬�뽻��һ����ֵ��ÿ��������ȡһ����ֵ����ʹ��������������Ԫ�صĺ���ȡ�
����һ�����飬��һ��Ԫ���ǵ�һ��������Ҫ������Ԫ�أ��ڶ���Ԫ���ǵڶ���������Ҫ������Ԫ�ء����ж���𰸣���������һ�����ɡ�����������������ֵ�����ؿ����顣
ʾ��:
����: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
���: [1, 3]
ʾ��:
����: array1 = [1, 2, 3], array2 = [4, 5, 6]
���: []
��ʾ��
1 <= array1.length, array2.length <= 100000
*/


class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int diff = 0;
        unordered_map<int,int> un_map1, un_map2;
        // diff ͳ��������֮�� 
        for (int i = 0; i < array1.size(); i++)
        {   
            diff += array1[i];
            un_map1[array1[i]]++;
        }
        for (int i = 0; i < array2.size(); i++)
        {
            diff -= array2[i];
            un_map2[array2[i]]++;
        }
        // �������֮��ܱ�2���������Ҳ����ɽ�����
        if (diff & 1)
            return {};
        // Ѱ�ҿɽ���������
        int temp = 0;
        for (auto iter = un_map1.begin(); iter != un_map1.end(); iter++)
        {
            temp = iter->first - (diff >> 1);
            if(un_map2[temp] != 0)
                return {iter->first, temp};
        }
        return {};
    }
};
