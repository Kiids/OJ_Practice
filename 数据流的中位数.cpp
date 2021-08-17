/*
��λ���������б��м����������б�����ż������λ�������м���������ƽ��ֵ��
���磬
[2,3,4] ����λ���� 3
[2,3] ����λ���� (2 + 3) / 2 = 2.5
���һ��֧���������ֲ��������ݽṹ��
void addNum(int num) - �������������һ�����������ݽṹ�С�
double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
ʾ����
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
����:
����������������������� 0 �� 100 ��Χ�ڣ��㽫����Ż�����㷨��
����������� 99% ���������� 0 �� 100 ��Χ�ڣ��㽫����Ż�����㷨��
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (maxheap.size() == minheap.size())
        {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else
        {
            minheap.push(num);
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        return maxheap.size() == minheap.size() ? ((maxheap.top() + minheap.top()) * 0.5) : minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
