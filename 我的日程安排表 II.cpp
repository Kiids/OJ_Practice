/*
ʵ��һ�� MyCalendar �����������ճ̰��š����Ҫ��ӵ�ʱ���ڲ��ᵼ������Ԥ��ʱ������Դ洢����µ��ճ̰��š�
MyCalendar ��һ�� book(int start, int end)����������ζ���� start �� end ʱ��������һ���ճ̰��ţ�ע�⣬�����ʱ���ǰ뿪���䣬�� [start, end), ʵ�� x �ķ�ΧΪ��  start <= x < end��
�������ճ̰�����һЩʱ���ϵĽ���ʱ�����������ճ̰��Ŷ���ͬһʱ���ڣ����ͻ��������Ԥ����
ÿ�ε��� MyCalendar.book����ʱ��������Խ��ճ̰��ųɹ���ӵ������ж����ᵼ������Ԥ�������� true�����򣬷��� false ���Ҳ�Ҫ�����ճ̰�����ӵ������С�
�밴�����²������MyCalendar ��: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
ʾ����
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
���ͣ� 
ǰ�����ճ̰��ſ�������������С� �������ճ̰��Żᵼ��˫��Ԥ��������������������С�
���ĸ��ճ̰��Ż��5,15����������������У���Ϊ���ᵼ������Ԥ����
������ճ̰��ţ�5,10����������������У���Ϊ��δʹ���Ѿ�˫��Ԥ����ʱ��10��
�������ճ̰��ţ�25,55����������������У���Ϊʱ�� [25,40] ���͵������ճ̰���˫��Ԥ����
ʱ�� [40,50] ������Ԥ����ʱ�� [50,55�����͵ڶ����ճ̰���˫��Ԥ����
��ʾ��
ÿ���������������� MyCalendar.book ������಻���� 1000�Ρ�
���ú��� MyCalendar.book(start, end)ʱ�� start �� end ��ȡֵ��ΧΪ [0, 10^9]��
*/

class MyCalendarTwo {
    map<int, int> m;
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        m[start]++,
        m[end]--;
        int x = 0;
        for (auto i: m)
        {
            if ((x += i.second) > 2)
            {
                m[start]--;
                m[end]++;
                return 0;
            }

        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
