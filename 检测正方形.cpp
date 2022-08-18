/*
����һ���� X-Y ƽ���ϵĵ㹹�ɵ������������һ����������Ҫ����㷨��
��� һ�����������е��µ㵽ĳ�����ݽṹ�С�������� �ظ� �ĵ㣬����������ͬ�ĵ���д���
����һ����ѯ�㣬��������ݽṹ��ѡ�������㣬ʹ��������Ͳ�ѯ��һͬ����һ�� ���Ϊ�� �� ����������� ��ͳ�� �����Ҫ��ķ�����Ŀ��
����������� ��һ�������Σ��������߳�����ͬ�⣬������ÿ���߶��� x-�� �� y-�� ƽ�л�ֱ��
ʵ�� DetectSquares �ࣺ
DetectSquares() ʹ�ÿ����ݽṹ��ʼ������
void add(int[] point) �����ݽṹ���һ���µĵ� point = [x, y]
int count(int[] point) ͳ�ư�������ʽ��� point = [x, y] ��ͬ���� ����������� �ķ�������
ʾ����
���룺
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
�����
[null, null, null, null, 1, 0, null, 2]
���ͣ�
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // ���� 1 �������ѡ��
                               //   - ��һ�����ڶ������͵�������
detectSquares.count([14, 8]);  // ���� 0 ����ѯ���޷������ݽṹ�е���Щ�㹹�������Ρ�
detectSquares.add([11, 2]);    // ��������ظ��ĵ㡣
detectSquares.count([11, 10]); // ���� 2 �������ѡ��
                               //   - ��һ�����ڶ������͵�������
                               //   - ��һ�������������͵��ĸ���
��ʾ��
point.length == 2
0 <= x, y <= 1000
���� add �� count �� �ܴ��� ���Ϊ 5000
*/

class DetectSquares {
    unordered_map<int, unordered_map<int, int>> m;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        m[x][y]++;
    }
    
    int count(vector<int> point) {
        int x0 = point[0], y0 = point[1], ret = 0;
        for (auto e : m[x0])
        {
            if (e.first == y0)
                continue;
            int x1 = x0, y1 = e.first;
            int edge = abs(y1 - y0);
            ret += e.second * (m[x0 + edge][y1] * m[x0 + edge][y0] + m[x0 - edge][y1] * m[x0 - edge][y0]);
        }
        
        return ret;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
 
 // �ҵ���������һ�������Ŀ�����ͬ�Ķ��㣬ȷ��һ���߳������ж�ʣ���������������ݼ����Ƿ���ڲ�����
