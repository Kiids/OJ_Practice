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

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        stack<int> s;
        vector<int> v;
        while(label > 1)
        {
            s.push(label);
            label /= 2;                                     // ��label�ڱ�׼��ȫ�������ĸ����
            if(label == 1)
                break;
                
            int h = log2(label) + 1;                        // ��label���ڵ����ߵĸ߶�h
            int mid = (pow(2, h - 1) + pow(2, h) - 1) / 2;  // ��h����м���
            if(label <= mid)                                // ��label��֮���ζ������ĸ����
                label = mid + (mid - label) + 1;
            else
                label = mid - (label - mid) + 1;
        }
        s.push(1);
        while (!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
