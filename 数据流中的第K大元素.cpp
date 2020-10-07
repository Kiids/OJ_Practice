/*
���һ���ҵ��������е�K��Ԫ�ص��ࣨclass����ע���������ĵ�K��Ԫ�أ����ǵ�K����ͬ��Ԫ�ء�
��� KthLargest ����Ҫһ��ͬʱ�������� k ����������nums �Ĺ��������������������еĳ�ʼԪ�ء�ÿ�ε��� KthLargest.add�����ص�ǰ�������е�K���Ԫ�ء�
ʾ��:
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
˵��:
����Լ��� nums �ĳ��ȡ� k-1 ��k �� 1��
*/

// ����set�Զ�����
class KthLargest {
    int K;
    multiset<int> m;
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto e : nums)
        {
            m.insert(e);
            if (m.size() > k)
                m.erase(m.begin());
        }
        K = k;
    }
    
    int add(int val) {
        m.insert(val);
        if (m.size() > K)
            m.erase(m.begin())
        return *m.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 
// ��
// priority_queue<Type, Container, Functional>
// TypeΪ�������ͣ� ContainerΪ�������ݵ�������FunctionalΪԪ�رȽϷ�ʽ
// �����д��������������ô����Ĭ���õ���vector���ȽϷ�ʽĬ����operator<��Ҳ�������ȶ����Ǵ󶥶ѣ���ͷԪ�����
// ����ΪС����

class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }       
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};
