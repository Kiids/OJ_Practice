/*
��һ�����޵Ķ������ϣ�ÿ���ڵ㶼�������ӽڵ㣬���еĽڵ� ���� ���ΰ� ��֮�� ���ν��б�ǡ�
����ͼ��ʾ���������У�������һ�С������С������С������У��������ҵ�˳����б�ǣ�
��ż���У������ڶ��С������С������С������У������ҵ����˳����б�ǡ�
��������ĳһ���ڵ�ı�� label�����㷵�شӸ��ڵ㵽�ñ��Ϊ label �ڵ��·������·������;���Ľڵ�������ɵġ�
ʾ�� 1��
���룺label = 14
�����[1,3,4,14]
ʾ�� 2��
���룺label = 26
�����[1,2,6,10,26]
��ʾ��
1 <= label <= 10^6
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int deep = log2(label), n = deep + 1;
        vector<int> v(n, 1);
        while(label != 1)
        {
            v[--n] = label;
            int up = deep % 2 ? ceil((pow(2, deep + 1) - label) / 2) : pow(2, deep - 1) + 1 - ceil((pow(2, deep + 1) - label) / 2);
            label = (--deep) % 2 ? pow(2, deep + 1) - up : pow(2, deep) + up - 1;
        }
        return v;
    }
};

// double ceil(double x); ���ش��ڻ��ߵ���ָ�����ʽ����С���� 
// resβ�����label
// �ж�label������
// �ҵ�label���׽ڵ�����λ�ã���->�ң�
// ����labelΪ���׽ڵ���ֵ

