/*
���ʵ��˫�˶��С�
ʵ�� MyCircularDeque ��:
MyCircularDeque(int k) �����캯��,˫�˶������Ϊ k ��
boolean insertFront()����һ��Ԫ����ӵ�˫�˶���ͷ���� ��������ɹ����� true �����򷵻� false ��
boolean insertLast() ����һ��Ԫ����ӵ�˫�˶���β������������ɹ����� true �����򷵻� false ��
boolean deleteFront() ����˫�˶���ͷ��ɾ��һ��Ԫ�ء� ��������ɹ����� true �����򷵻� false ��
boolean deleteLast() ����˫�˶���β��ɾ��һ��Ԫ�ء���������ɹ����� true �����򷵻� false ��
int getFront() )����˫�˶���ͷ�����һ��Ԫ�ء����˫�˶���Ϊ�գ����� -1 ��
int getRear() �����˫�˶��е����һ��Ԫ�ء� ���˫�˶���Ϊ�գ����� -1 ��
boolean isEmpty() ����˫�˶���Ϊ�գ��򷵻� true �����򷵻� false  ��
boolean isFull() ����˫�˶������ˣ��򷵻� true �����򷵻� false ��
ʾ�� 1��
����
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
���
[null, true, true, true, false, 2, true, true, true, 4]
����
MyCircularDeque circularDeque = new MycircularDeque(3); // ����������СΪ3
circularDeque.insertLast(1);			        // ���� true
circularDeque.insertLast(2);			        // ���� true
circularDeque.insertFront(3);			        // ���� true
circularDeque.insertFront(4);			        // �Ѿ����ˣ����� false
circularDeque.getRear();  				// ���� 2
circularDeque.isFull();				        // ���� true
circularDeque.deleteLast();			        // ���� true
circularDeque.insertFront(4);			        // ���� true
circularDeque.getFront();				// ���� 4
��ʾ��
1 <= k <= 1000
0 <= value <= 1000
insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull  ���ô��������� 2000 ��
*/

class MyCircularDeque {
    int rear = 0, front = 0, capacity = 0;
    vector<int> queue;
public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        queue = vector<int>(k + 1, 0);
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        front--;
        front += capacity;
        front %= capacity;
        queue[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        queue[rear] = value;
        rear++;
        rear %= capacity;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        front++; 
        front %= capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        rear--;
        rear += capacity;
        rear %= capacity;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return queue[front];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return queue[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
