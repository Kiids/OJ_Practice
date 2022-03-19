/*
�� ��������ս���� ��Ļʽ��ѹ���Ŀ �����˻������У�ÿһ�����˻�չʾһ�ֵƹ���ɫ�� ���˻�����ͨ�����ֲ���������ɫͼ���任��
�������˻���λ�ò���
�л����˻�չʾ�ĵƹ���ɫ
����������С��Ϊ N*M �Ķ�ά���� source �� target ��ʾ���˻�������ݵ�������ɫͼ�����������˻��л��ƹ���ɫ�ĺ��ܴܺ��뷵�ش� source �� target ������Ҫ���ټ����˻��л��ƹ���ɫ��
ע�⣺ �������˻���λ�ò���ʱ���˻���λ�ÿ�������䶯��
ʾ�� 1��
���룺source = [[1,3],[5,4]], target = [[3,1],[6,5]]
�����1
���ͣ�
��ѷ���Ϊ
�� [0,1] �������˻��ƶ��� [0,0] ����
�� [0,0] �������˻��ƶ��� [0,1] ����
�� [1,0] �������˻��ƶ��� [1,1] ����
�� [1,1] �������˻��ƶ��� [1,0] ������ƹ���ɫ�л�Ϊ��ɫ���Ϊ 6 �ĵƹ⣻
��˴�source �� target ����Ҫ�����ٵƹ��л�����Ϊ 1��
ʾ�� 2��
���룺source = [[1,2,3],[3,4,5]], target = [[1,3,5],[2,3,4]]
�����0
���ͣ�
����������˻���λ�ò��֣�������ͼ���л�����˲���Ҫ���˻��л���ɫ
��ʾ��
n == source.length == target.length
m == source[i].length == target[i].length
1 <= n, m <=100
1 <= source[i][j], target[i][j] <=10^4
*/

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        unordered_map<int, int> m;
        for (auto e : source)
            for (auto x : e)
                m[x]++;
                
        for (auto e : target)
            for (auto x : e)
                m[x]--;
                
        int ret = 0;
        unordered_map<int, int>::iterator i;
        for (i = m.begin(); i != m.end(); i++)
            if (i->second > 0)
                ret += i->second;
        return ret;
    }
};
