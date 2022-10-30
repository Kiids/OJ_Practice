/*
���һ�� map ���������¼���:
�ַ�����ʾ����������ʾֵ
���ؾ���ǰ׺���ڸ����ַ����ļ���ֵ���ܺ�
ʵ��һ�� MapSum �ࣺ
MapSum() ��ʼ�� MapSum ����
void insert(String key, int val) ���� key-val ��ֵ�ԣ��ַ�����ʾ�� key ��������ʾֵ val ������� key �Ѿ����ڣ���ôԭ���ļ�ֵ��?key-value?����������µļ�ֵ�ԡ�
int sum(string prefix) ���������Ը�ǰ׺ prefix ��ͷ�ļ� key ��ֵ���ܺ͡�
ʾ�� 1��
���룺
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
�����
[null, null, 3, null, 5]
���ͣ�
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // ���� 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // ���� 5 (apple + app = 3 + 2 = 5)
��ʾ��
1 <= key.length, prefix.length <= 50
key �� prefix ����СдӢ����ĸ���
1 <= val <= 1000
������ 50 �� insert �� sum
*/

class MapSum {
    map<string, int> m;
public:
    MapSum() {
        m.clear();
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        auto r = m.insert({prefix, 0});
        auto b = r.first;
        if (r.second)
        {
            b++;
            m.erase(prefix);
        }
        (*(prefix.end() - 1)) ++;
        r = m.insert({prefix, 0});
        auto e = r.first;
        if (r.second)
        {
            e++;
            m.erase(prefix);
        }
        int ret = 0;
        while (b != e)
        {
            ret += b->second;
            b++;
        }
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
