/*
ʵ��һ�� MyCalendar �����������ճ̰��š����Ҫ��ӵ��ճ̰��Ų������ �ظ�Ԥ�� ������Դ洢����µ��ճ̰��š�
�������ճ̰�����һЩʱ���ϵĽ���ʱ�����������ճ̰��Ŷ���ͬһʱ���ڣ����ͻ���� �ظ�Ԥ�� ��
�ճ̿�����һ������ start �� end ��ʾ�������ʱ���ǰ뿪���䣬�� [start, end), ʵ�� x �ķ�ΧΪ��  start <= x < end ��
ʵ�� MyCalendar �ࣺ
MyCalendar() ��ʼ����������
boolean book(int start, int end) ������Խ��ճ̰��ųɹ���ӵ������ж����ᵼ���ظ�Ԥ�������� true �����򣬷��� false ���Ҳ�Ҫ�����ճ̰�����ӵ������С�
ʾ����
���룺
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
�����
[null, true, false, true]
���ͣ�
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False ������ճ̰��Ų�����ӵ������У���Ϊʱ�� 15 �Ѿ�����һ���ճ̰���Ԥ���ˡ�
myCalendar.book(20, 30); // return True ������ճ̰��ſ�����ӵ������У���Ϊ��һ���ճ̰���Ԥ����ÿ��ʱ�䶼С�� 20 ���Ҳ�����ʱ�� 20 ��
��ʾ��
0 <= start < end <= 10^9
ÿ���������������� book �����Ĵ�����಻���� 1000 �Ρ�
*/

class MyCalendar {
    map<int, int> m;
public:
    MyCalendar() {
        m[-1] = -1;
    }
    
    bool book(int start, int end) {
        auto it = m.lower_bound(end);
        if ((--it)->second <= start)
        {  
            m[start] = end;
            return true;
        }
        return false;   
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
