/*
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣӳ��
�����˵��������Ӧ�ð������µĹ���
put(key, value)�����ϣӳ���в���(��,ֵ)����ֵ�ԡ��������Ӧ��ֵ�Ѿ����ڣ��������ֵ��
get(key)�����ظ����ļ�����Ӧ��ֵ�����ӳ���в����������������-1��
remove(key)�����ӳ���д����������ɾ�������ֵ�ԡ�
ʾ����
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // ���� 1
hashMap.get(3);            // ���� -1 (δ�ҵ�)
hashMap.put(2, 1);         // �������е�ֵ
hashMap.get(2);            // ���� 1 
hashMap.remove(2);         // ɾ����Ϊ2������
hashMap.get(2);            // ���� -1 (δ�ҵ�) 
ע�⣺
���е�ֵ���� [0, 1000000]�ķ�Χ�ڡ�
����������Ŀ��[1, 10000]��Χ�ڡ�
��Ҫʹ���ڽ��Ĺ�ϣ�⡣
*/

class MyHashMap {
    vector<int> v;
    const int l = 1e6;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        v = vector<int>(l, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        v[key % l] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return v[key % l];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        v[key % l] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
