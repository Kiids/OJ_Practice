/*
����һ���������飬��дһ���������ҳ�����m��n��ֻҪ����������[m,n]��Ԫ���ź������������������ġ�ע�⣺n-m������С��Ҳ����˵���ҳ�����������������С���������ֵΪ[m,n]����������������m��n��������������������ģ����뷵��[-1,-1]��
ʾ����
���룺 [1,2,4,7,10,11,7,12,6,7,16,18,19]
����� [3,9]
��ʾ��
0 <= len(array) <= 1000000
*/

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if (!array.size())
            return {-1, -1};
        vector<bool> dp(array.size(), true);
        int maxval = array[0];
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] < maxval)
                dp[i] = false;
            else
                maxval = array[i];
        }
        int minval = array[array.size()-1];
        int rmax = -1;
        int rmin = array.size();
        for (int i = array.size()-1; i >= 0; i--)
        {
            if (array[i] > minval)
                dp[i] = false;
            else
                minval = array[i];
                
            if (!dp[i])
            {
                rmax = max(rmax, i);
                rmin = min(rmin, i);
            }
        }
        if (rmax == -1)
            return {-1, -1};
        return {rmin, rmax};
    }
};
