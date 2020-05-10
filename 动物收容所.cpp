/*
�������������мҶ���������ֻ���ݹ���è�����ϸ����ء��Ƚ��ȳ�����ԭ�����������������Ķ���ʱ��������ֻ���������ж����С����ϡ������������������ʱ�䳤�̶������Ķ�����߿�����ѡè�򹷣�ͬʱ�����������ද���С����ϡ��ģ�������֮�������˲���������ѡ�������Ķ����봴�����������ϵͳ�����ݽṹ��ʵ�ָ��ֲ�������������enqueue��dequeueAny��dequeueDog��dequeueCat������ʹ��Java���õ�LinkedList���ݽṹ��
enqueue������һ��animal������animal[0]�������ţ�animal[1]���������࣬���� 0 ����è��1 ������
dequeue*��������һ���б�[������, ��������]����û�п��������Ķ���򷵻�[-1,-1]��
ʾ��1:
 ���룺
["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [], [], []]
 �����
[null,null,null,[0,0],[-1,-1],[1,0]]
ʾ��2:
 ���룺
["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
[[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
 �����
[null,null,null,null,[2,1],[0,0],[1,0]]
˵��:
���������������Ϊ20000
*/

class AnimalShelf {
    queue<vector<int>> _q_cat;
    queue<vector<int>> _q_dog;
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if (animal.at(1) == 0)
            _q_cat.push(animal);
        else
            _q_dog.push(animal);
    }
    
    vector<int> dequeueAny() {
        vector<int> animal;
        if (_q_cat.empty() && _q_dog.empty())
            return vector<int>{-1, -1};
        else if (!_q_cat.empty() && _q_dog.empty())
        {
            animal = _q_cat.front();
            _q_cat.pop();
        }
        else if (_q_cat.empty() && !_q_dog.empty())
        {
            animal = _q_dog.front();
            _q_dog.pop();
        }
        else
        {
            if (_q_cat.front().at(0) < _q_dog.front().at(0))
            {
                animal = _q_cat.front();
                _q_cat.pop();
            }
            else
            {
                animal = _q_dog.front();
                _q_dog.pop();
            }
        }
        return animal;
    }
    
    vector<int> dequeueDog() {
        if (_q_dog.empty())
            return vector<int>{-1, -1};

        vector<int> dog = _q_dog.front();
        _q_dog.pop();
        return dog;
    }
    
    vector<int> dequeueCat() {
        if (_q_cat.empty())
            return vector<int>{-1, -1};

        vector<int> cat = _q_cat.front();
        _q_cat.pop();
        return cat;
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
