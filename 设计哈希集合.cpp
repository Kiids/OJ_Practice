/*
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣ����
�����˵��������Ӧ�ð������µĹ���
add(value)�����ϣ�����в���һ��ֵ��
contains(value) �����ع�ϣ�������Ƿ�������ֵ��
remove(value)��������ֵ�ӹ�ϣ������ɾ���������ϣ������û�����ֵ��ʲôҲ������
ʾ��:
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // ���� true
hashSet.contains(3);    // ���� false (δ�ҵ�)
hashSet.add(2);          
hashSet.contains(2);    // ���� true
hashSet.remove(2);          
hashSet.contains(2);    // ����  false (�Ѿ���ɾ��)
ע�⣺
���е�ֵ���� [0, 1000000]�ķ�Χ�ڡ�
����������Ŀ��[1, 10000]��Χ�ڡ�
��Ҫʹ���ڽ��Ĺ�ϣ���Ͽ⡣
*/

class MyHashSet {
    vector<unsigned> v;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        v = vector<unsigned >(1000000 / 32,0);
    }
    
    void add(int key) {
        v[key / 31] |= 1 << (key % 31);
    }
    
    void remove(int key) {
        v[key / 31] &= ~(1 << (key % 31));
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return  v[key / 31] & (1 << (key % 31));
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// ��λ��ʾ��λ���߼�ֵΪ1���ʾhash���д��ڡ�
// һ���޷��ŵ��������Ա�ʾhash ���е� 32 ����������������Ϊ 1000000/32 ��Ͱ������ÿ��ͰΪ32 ������
// �ж�key��ֵ �Ƿ���ھ�ȥ ͰΪ k/32 �� k%32 λ�� k/32 �ȼ��� k>>5(���ƣ� k%32 �ȼ��� k&31.���߼���)
// ��ĳһλ ���0 ��->&0����ĳһλ ���1 ��->|1,��ĳһλ��ɶ��->& ��
