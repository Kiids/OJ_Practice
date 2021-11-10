/*
�����ÿ�� ���� �б� temperatures ���������ÿһ����Ҫ�ȼ���Ż��и��ߵ��¶ȡ������������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
ʾ�� 1:
����: temperatures = [73,74,75,71,69,72,76,73]
���: [1,1,4,2,1,1,0,0]
ʾ�� 2:
����: temperatures = [30,40,50,60]
���: [1,1,1,0]
ʾ�� 3:
����: temperatures = [30,60,90]
���: [1,1,0]
��ʾ��
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size(), 0);
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int prev = s.top();
                s.pop();
                v[prev] = i - prev;
            }
            s.push(i);
        }
        return v;
    }
};
