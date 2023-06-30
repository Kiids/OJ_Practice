/*
������Ʋ�ʵ��һ������  LRU (�������ʹ��) ���� Լ�������ݽṹ��
ʵ�� LRUCache �ࣺ
LRUCache(int capacity) �� ������ ��Ϊ���� capacity ��ʼ�� LRU ����
int get(int key) ����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� -1 ��
void put(int key, int value) ����ؼ��� key �Ѿ����ڣ�����������ֵ value ����������ڣ����򻺴��в������ key-value ���������������¹ؼ����������� capacity ����Ӧ�� ��� ���δʹ�õĹؼ��֡�
���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�
ʾ����
����
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
���
[null, null, null, 1, null, -1, null, -1, 3, 4]
����
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // ������ {1=1}
lRUCache.put(2, 2); // ������ {1=1, 2=2}
lRUCache.get(1);    // ���� 1
lRUCache.put(3, 3); // �ò�����ʹ�ùؼ��� 2 ���ϣ������� {1=1, 3=3}
lRUCache.get(2);    // ���� -1 (δ�ҵ�)
lRUCache.put(4, 4); // �ò�����ʹ�ùؼ��� 1 ���ϣ������� {4=4, 3=3}
lRUCache.get(1);    // ���� -1 (δ�ҵ�)
lRUCache.get(3);    // ���� 3
lRUCache.get(4);    // ���� 4
��ʾ��
1 <= capacity <= 3000
0 <= key <= 10000
0 <= value <= 10^5
������ 2 * 10^5 �� get �� put
*/

class LRUCache {
public:
    struct Node {
        int key, value;
        Node *left ,*right;
        Node(int _key,int _value): key(_key), value(_value), left(NULL), right(NULL) {}
    }*L,*R;  // ˫����ڵ� 

    int n;
    unordered_map<int, Node*> hash;  // ��ϣ 

    void remove(Node* p)
    {
        p->right->left = p->left;
        p->left->right = p->right;
    }

    void insert(Node *p)
    {
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
    }
    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->right = R;
        R->left = L;
    }
    
    int get(int key) {  // ʱ�临�Ӷ�O(1)
        if (hash.count(key) == 0)
            return -1;
        auto p = hash[key];
        remove(p);
        insert(p);
        return p->value;
    }
    
    void put(int key, int value) {  // ʱ�临�Ӷ�O(1)
        if (hash.count(key))
        {
            auto p = hash[key];
            p->value = value;
            remove(p);
            insert(p);
        }
        else 
        {
            if (hash.size() == n)
            {
                auto p = R->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            
            auto p = new Node(key,value);
            hash[key] = p;
            insert(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
