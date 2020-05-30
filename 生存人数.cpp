/*
����N���˵ĳ�����ݺ�������ݣ���i���˵ĳ������Ϊbirth[i]���������Ϊdeath[i]��ʵ��һ�������Լ�����������������ݡ�
����Լ��������˶�������1900����2000�꣨��1900��2000��֮�䡣���һ������ĳһ�������ʱ�ڶ���������״̬����ô����Ӧ�ñ�������һ���ͳ���С����磬����1908�ꡢ����1909�����Ӧ��������1908���1909��ļ�����
����ж���������������ͬ�Ҿ�Ϊ���ֵ�����������С����ݡ�
ʾ����
���룺
birth = {1900, 1901, 1950}
death = {1948, 1951, 2000}
����� 1901
��ʾ��
0 < birth.length == death.length <= 10000
birth[i] <= death[i]
*/

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> v(110, 0);
        int n = birth.size();
        for (int i = 0; i < n; i++)
        {
            v[birth[i] - 1900] += 1;
            v[death[i] + 1 - 1900] -= 1;
        }

        int ans = 0;
        //�����Ľ�Сֵ
        int ret;
        for(int i = 1; i <= 101; i++){
            v[i] += v[i-1];
            ans = max(ans, v[i]);
        }
        for(int i = 0; i <= 101; i++){
            if(ans == v[i]){
                ret = i;
                break;
            }
        }
        return ret + 1900;
    }
};
