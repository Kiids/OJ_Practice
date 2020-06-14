/*
��ƺ͹���һ�����������ʹ�á����棬�û����ɾ���������ʹ�õ���Ŀ������Ӧ�ôӼ�ӳ�䵽ֵ(���������ͼ����ض�����Ӧ��ֵ)�����ڳ�ʼ��ʱָ����������������汻����ʱ����Ӧ��ɾ���������ʹ�õ���Ŀ��
��Ӧ��֧�����²����� ��ȡ���� get �� д������ put ��
��ȡ���� get(key) - �����Կ (key) �����ڻ����У����ȡ��Կ��ֵ�����������������򷵻� -1��
д������ put(key, value) - �����Կ�����ڣ���д��������ֵ�������������ﵽ����ʱ����Ӧ����д��������֮ǰɾ���������ʹ�õ�����ֵ���Ӷ�Ϊ�µ�����ֵ�����ռ䡣
ʾ��:
LRUCache cache = new LRUCache( 2 /* �������� *//* );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // ����  1
cache.put(3, 3);    // �ò�����ʹ����Կ 2 ����
cache.get(2);       // ���� -1 (δ�ҵ�)
cache.put(4, 4);    // �ò�����ʹ����Կ 1 ����
cache.get(1);       // ���� -1 (δ�ҵ�)
cache.get(3);       // ����  3
cache.get(4);       // ����  4
*/

class LRUCache {
private:
	int cap;
	list<int> buffer;
	map<int, int> hash;
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		list<int>::iterator it = find(buffer.begin(), buffer.end(), key);
		if (it==buffer.end()) {
			return -1;
		}
		else {
			int x = *it;
			buffer.erase(it);
			buffer.push_back(x);
			return hash[x];
		}
	}

	void put(int key, int value) {
		if (hash.find(key) != hash.end()) {
			hash[key] = value;
			list<int>::iterator it=find(buffer.begin(), buffer.end(), key);
			int x = *it;
			buffer.erase(it);
			buffer.push_back(x);
		}
		else {
			if (hash.size() < cap) {
				hash[key] = value;
				buffer.push_back(key);//ģ����� 
			}
			else {
				int x = buffer.front();
				buffer.erase(buffer.begin());
				hash.erase(hash.find(x));

				hash[key] = value;
				buffer.push_back(key);
			}
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
