/*
����һ����������Ľӿڣ��ӿڰ������������� next() �� hasNext()����Ʋ�ʵ��һ��֧�� peek() �����Ķ��˵����� -- �䱾�ʾ��ǰ�ԭ��Ӧ�� next() �������ص�Ԫ�� peek() ������
ʾ��:
�������������ʼ��Ϊ�б� [1,2,3]��
���� next() ���� 1���õ��б��еĵ�һ��Ԫ�ء�
���ڵ��� peek() ���� 2����һ��Ԫ�ء��ڴ�֮����� next() ��Ȼ���� 2��
���һ�ε��� next() ���� 3��ĩβԪ�ء��ڴ�֮����� hasNext() Ӧ�÷��� false��
���ף��㽫�����չ�����ƣ�ʹ֮���ͨ�û����Ӷ���Ӧ���е����ͣ�����ֻ�������ͣ�
*/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int val;
    bool nextv;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    nextv = Iterator::hasNext();
        if (nextv)
            val = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int cur = val;
        nextv = Iterator::hasNext();
        if (nextv)
            val = Iterator::next();
        return cur;
	}
	
	bool hasNext() const {
	    return nextv;
	}
};
