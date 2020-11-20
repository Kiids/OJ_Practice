/*
�� n �� (id, value) �ԣ����� id �� 1 �� n ֮���һ��������value ��һ���ַ����������� id ��ͬ������ (id, value) �ԡ�
���һ�������� ���� ˳���ȡ n �� (id, value) �ԣ����ڶ�ε���ʱ �� id ������˳�� ����һЩֵ��
ʵ�� OrderedStream �ࣺ
OrderedStream(int n) ����һ���ܽ��� n ��ֵ������������ǰָ�� ptr ��Ϊ 1 ��
String[] insert(int id, String value) �����д洢�µ� (id, value) �ԡ��洢��
������洢�� id = ptr �� (id, value) �ԣ����ҳ��� id = ptr ��ʼ�� � id ������������ ���� ��˳�� ��������Щ id ������ֵ���б�Ȼ�󣬽� ptr ����Ϊ����Ǹ�  id + 1 ��
���򣬷���һ�����б�
ʾ����
����
["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
���
[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]
����
OrderedStream os= new OrderedStream(5);
os.insert(3, "ccccc"); // ���� (3, "ccccc")������ []
os.insert(1, "aaaaa"); // ���� (1, "aaaaa")������ ["aaaaa"]
os.insert(2, "bbbbb"); // ���� (2, "bbbbb")������ ["bbbbb", "ccccc"]
os.insert(5, "eeeee"); // ���� (5, "eeeee")������ []
os.insert(4, "ddddd"); // ���� (4, "ddddd")������ ["ddddd", "eeeee"]
��ʾ��
1 <= n <= 1000
1 <= id <= n
value.length == 5
value ����Сд��ĸ���
ÿ�ε��� insert ����ʹ��һ��Ψһ�� id
ǡ�õ��� n �� insert
*/

class OrderedStream {
public:
    int ptr;
    vector<string> v;
    OrderedStream(int n) {
        ptr = 1;
        for (int i = 0; i < n + 2; i++)
            v.push_back("");
    }
    
    vector<string> insert(int id, string value) {
        v[id] = value;
        vector<string> ret;
        while (v[ptr] != "")
        {
            ret.push_back(v[ptr]);
            ptr++;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
