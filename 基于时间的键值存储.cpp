/*
���һ������ʱ��ļ�ֵ���ݽṹ���ýṹ�����ڲ�ͬʱ����洢��Ӧͬһ�����Ķ��ֵ��������ض�ʱ�����������Ӧ��ֵ��
ʵ�� TimeMap �ࣺ
TimeMap() ��ʼ�����ݽṹ����
void set(String key, String value, int timestamp) �洢�� key��ֵ value���Լ�������ʱ��� timestamp��
String get(String key, int timestamp)
������ǰ���� set(key, value, timestamp_prev) ���洢��ֵ������ timestamp_prev <= timestamp ��
����ж��������ֵ���򷵻ض�Ӧ����  timestamp_prev ���Ǹ�ֵ��
���û��ֵ���򷵻ؿ��ַ�����""����
ʾ����
���룺
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
�����
[null, null, "bar", "bar", null, "bar2", "bar2"]
���ͣ�
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // �洢�� "foo" ��ֵ "bar" ��ʱ��� timestamp = 1   
timeMap.get("foo", 1);         // ���� "bar"
timeMap.get("foo", 3);         // ���� "bar", ��Ϊ��ʱ��� 3 ��ʱ��� 2 ��û�ж�Ӧ "foo" ��ֵ������Ψһ��ֵλ��ʱ��� 1 ������ "bar"�� ��
timeMap.set("foo", "bar2", 4); // �洢�� "foo" ��ֵ "bar2" ��ʱ��� timestamp = 4  
timeMap.get("foo", 4);         // ���� "bar2"
timeMap.get("foo", 5);         // ���� "bar2"
��ʾ��
1 <= key.length, value.length <= 100
key �� value ��СдӢ����ĸ���������
1 <= timestamp <= 10^7
set �����е�ʱ��� timestamp �����ϸ������
������ set �� get ���� 2 * 10^5 ��
*/

class TimeMap {
    unordered_map<string, vector<pair<string, int>>> m;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& t = m[key];
        int l = 0, r = t.size(), ret = -1;
        while (l < r)
        {
            int m = (r - l) / 2 + l;
            if (t[m].second <= timestamp)
            {
                ret = m;
                l = m + 1;
            }
            else
                r = m;
        }
        return ret == -1 ? "" : t[ret].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
