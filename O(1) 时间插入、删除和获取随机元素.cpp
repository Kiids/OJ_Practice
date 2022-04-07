/*
ʵ��RandomizedSet �ࣺ
RandomizedSet() ��ʼ�� RandomizedSet ����
bool insert(int val) ��Ԫ�� val ������ʱ���򼯺��в����������� true �����򣬷��� false ��
bool remove(int val) ��Ԫ�� val ����ʱ���Ӽ������Ƴ���������� true �����򣬷��� false ��
int getRandom() ����������м����е�һ�����������֤���ô˷���ʱ���������ٴ���һ��Ԫ�أ���ÿ��Ԫ��Ӧ���� ��ͬ�ĸ��� �����ء�
�����ʵ��������к�����������ÿ�������� ƽ�� ʱ�临�Ӷ�Ϊ O(1) ��
ʾ����
����
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
���
[null, true, false, true, 2, true, false, 2]
����
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // �򼯺��в��� 1 ������ true ��ʾ 1 ���ɹ��ز��롣
randomizedSet.remove(2); // ���� false ����ʾ�����в����� 2 ��
randomizedSet.insert(2); // �򼯺��в��� 2 ������ true ���������ڰ��� [1,2] ��
randomizedSet.getRandom(); // getRandom Ӧ������� 1 �� 2 ��
randomizedSet.remove(1); // �Ӽ������Ƴ� 1 ������ true ���������ڰ��� [2] ��
randomizedSet.insert(2); // 2 ���ڼ����У����Է��� false ��
randomizedSet.getRandom(); // ���� 2 �Ǽ�����Ψһ�����֣�getRandom ���Ƿ��� 2 ��
��ʾ��
-2^31 <= val <= 2^31 - 1
������ insert��remove �� getRandom ���� 2 * 10^5 ��
�ڵ��� getRandom ����ʱ�����ݽṹ�� ���ٴ���һ�� Ԫ�ء�
*/

class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (m.count(val))
            return 0;
        m[val] = v.size();
        v.push_back(val);
        return 1;
    }
    
    bool remove(int val) {
        if (!m.count(val))
            return 0;
        m[v.back()] = m[val];
        v[m[val]] = v.back();
        m.erase(val);
        v.pop_back();
        return 1;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
