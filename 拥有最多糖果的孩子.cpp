/*
����һ������ candies ��һ������ extraCandies ������ candies[i] ����� i ������ӵ�е��ǹ���Ŀ��
��ÿһ�����ӣ�����Ƿ����һ�ַ������������ extraCandies ���ǹ������������֮�󣬴˺����� ��� ���ǹ���ע�⣬�����ж������ͬʱӵ�� ��� ���ǹ���Ŀ��
ʾ�� 1��
���룺candies = [2,3,5,1,3], extraCandies = 3
�����[true,true,true,false,true] 
���ͣ�
���� 1 �� 2 ���ǹ���������õ����ж�����ǹ���3��������ô���ܹ��� 5 ���ǹ���������Ϊӵ������ǹ��ĺ��ӡ�
���� 2 �� 3 ���ǹ���������õ����� 2 �������ǹ�����ô������Ϊӵ������ǹ��ĺ��ӡ�
���� 3 �� 5 ���ǹ������Ѿ���ӵ������ǹ��ĺ��ӡ�
���� 4 �� 1 ���ǹ�����ʹ���õ����ж�����ǹ�����Ҳֻ�� 4 ���ǹ����޷���Ϊӵ���ǹ����ĺ��ӡ�
���� 5 �� 3 ���ǹ���������õ����� 2 �������ǹ�����ô������Ϊӵ������ǹ��ĺ��ӡ�
ʾ�� 2��
���룺candies = [4,2,1,1,2], extraCandies = 1
�����[true,false,false,false,false] 
���ͣ�ֻ�� 1 �������ǹ������Բ��ܶ����ǹ���˭��ֻ�к��� 1 ���Գ�Ϊӵ���ǹ����ĺ��ӡ�
ʾ�� 3��
���룺candies = [12,1,12], extraCandies = 10
�����[true,false,true]
��ʾ��
2 <= candies.length <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = -1;
        for (int i = 0; i < candies.size(); i++)
            if (max < candies[i])
                max = candies[i];
        
        vector<bool> ret;
        for (int i = 0; i < candies.size(); i++)
            ret.push_back(extraCandies >= (max - candies[i]));
        
        return ret;
    }
};
