/*
��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
���磬
[2,3,4] ����λ���� 3
[2,3] ����λ���� (2 + 3) / 2 = 2.5
���һ��֧���������ֲ��������ݽṹ��
void addNum(int num) - �������������һ�����������ݽṹ�С�
double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
ʾ�� 1��
���룺
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
�����[null,null,null,1.50000,null,2.00000]
ʾ�� 2��
���룺
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
�����[null,null,2.00000,null,2.50000]
���ƣ�
����� addNum��findMedia���� 50000 �ε��á�
*/

//ʱ�临�Ӷȣ�O(logn)���Ѳ����ɾ����Ҫ O(logn)��������λ����Ҫ O(1)��
//�ռ临�Ӷȣ�O(n)��
class MedianFinder {
    priority_queue<int> l;  // �󶥶ѣ������λ����߽�С��һ������
    priority_queue<int, vector<int>, greater<int>> h;  // С���ѣ������λ���ұ߽ϴ��һ������
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        l.push(num);  // ��� 
        h.push(l.top());  // ƽ�� 
        l.pop();
        if (l.size() < h.size())  // ����������Ԫ�ظ��� 
        {
            l.push(h.top());
            h.pop();
        }
    }
    
    double findMedian() {
        return l.size() > h.size() ? (double)l.top() : (l.top() + h.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

