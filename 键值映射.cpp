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
        auto b = r.first;  // bΪ��һ��ƥ���key��Ӧ�ĵ�����
        if (r.second)      // ����ǰû�У��ɹ����룩��b����
        {
            b++;
            m.erase(prefix);
        }
        (*(prefix.end() - 1)) ++;
        r = m.insert({prefix, 0});
        auto e = r.first;  // eΪ���һ��ƥ���key��Ӧ�ĵ�������һ
        if (r.second)      // ����ǰû�У��ɹ����룩��e����
        {
            e++;
            m.erase(prefix);
        }
        int ret = 0;
        while (b != e)     // �ۼ�b��e-1
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
 

//�洢�Ͳ��룬ֱ�Ӳ���map���ռ临�Ӷȿռ临�Ӷ�O(M)��insertʱ�临�Ӷ�O(logM)��MΪҪ�洢�ļ�ֵ�Ը�����
//��sum����Ϊmap������Ҫ�ۼӵ�key��map��������ֻ��Ҫȷ������������key��map�е���ʼλ�úͽ���λ�ã�֮���ۼӡ�
//��ʼλ�ã�����һ��prefix��ֵ���������ʧ�ܣ���ʾmapԭ������prefix,map::insert�������صĵ�������Ϊ��ʼλ�ã�
//�������ɹ�����ʾmapԭ��������prefix��map::insert�������صĵ���������1��Ϊ��ʼλ�á�
//����λ�ã���Ҫ�Ƚ�prefix�ַ��������һ���ַ���һ������ԭ��Ϊ"abc", ��һ���Ϊ"abd"��,�ٲ���map�У�
//λ�������һ������������key���棬��1��ȷ�����һ����������key��λ�á�
//sum������ʱ�临�Ӷ�ΪO(logM + C), MΪҪ�洢�ļ�ֵ�Ը�����CΪƥ�䵽��keyֵ������

