/*
���������� �������� ���������� nums1 �� nums2 , �Լ�һ������ k ��
����һ��ֵ (u,v)�����е�һ��Ԫ������ nums1���ڶ���Ԫ������ nums2 ��
���ҵ�����С�� k ������ (u1,v1),  (u2,v2)  ...  (uk,vk) ��
ʾ�� 1:
����: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
���: [1,2],[1,4],[1,6]
����: ���������е�ǰ 3 ������
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
ʾ�� 2:
����: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
���: [1,1],[1,1]
����: ���������е�ǰ 2 ������
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
ʾ�� 3:
����: nums1 = [1,2], nums2 = [3], k = 3 
���: [1,3],[2,3]
����: Ҳ�������������е����Զ�������:[1,3],[2,3]
��ʾ:
1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 �� nums2 ��Ϊ��������
1 <= k <= 1000
*/

class Solution {
    bool flag = true;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        int n = nums1.size(), m = nums2.size();
        if (n > m)  // ȷ��nums1Ϊ�������г��Ƚ��ٵ��Ǹ�
        {
            swap(nums1, nums2);
            swap(m, n);
            flag = false;
        }
        auto cmp = [&](const auto& a, const auto& b){  // ����ȽϹ���
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(n, k); i++)
            q.push( {i, 0} );
        while (v.size() < k and q.size())
        {
            auto [a,b] = q.top();
            q.pop();
            flag ? v.push_back( {nums1[a], nums2[b]}) : v.push_back( {nums2[b], nums1[a]});
            if (b + 1 < m)
				q.push( {a, b + 1} );
        }
        return v;
    }
};

// ��ʼ���� n �����е���λԪ�أ���ԣ��Զ�Ԫ�� (i,j) �������ȶ��У�С���ѣ���
// ���� i Ϊ�õ���� nums1[i] ���±꣬j Ϊ�õ���� nums2[j] ���±꣬
// ʼ��ȷ�� nums1 Ϊ�������г��Ƚ��ٵ��Ǹ���Ȼ��ͨ����ʶλ����¼�Ƿ�����������
// ȷ���𰸵ĵ�˳�����ȷ�ԡ�ÿ�δ����ȶ��У��ѣ���ȡ���Ѷ�Ԫ��
// ����Ϊ��ǰδ�����뵽�𰸵����е���е���Сֵ������𰸣�
// �����õ���������е���һλ������У��������ȶ����С�
// template <class T, class Container = vector<T>,class Compare = less<typename Container::value_type> >
// class priority_queue;
// class T��T�����ȶ����д洢��Ԫ�ص����͡�
// class Container = vector<T>��Container�����ȶ��еײ�ʹ�õĴ洢�ṹ��Ĭ��vector��
// class Compare = less<typename Container::value_type> ��Compar�Ƕ������ȶ�����Ԫ�صıȽϷ�ʽ���ࡣ
// decltype�����������ڲ�ѯ���ʽ���������͡�decltype��C++11��׼�ƶ�ʱ���룬��Ҫ��Ϊ���ͱ�̶���ƣ�
// �Խ�����ͱ���У�������Щ������ģ����������������ԣ����������ܣ���ʾ֮�����⡣
// decltypeѡ�񲢷��ز��������������ͣ��ڴ˹����У��������������ʽ���õ��������ͣ�ȴ��ʵ�ʼ�����ʽ��ֵ��

class Solution {
    bool flag = true;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        auto cmp = [&nums1, &nums2] (const pair<int, int>& p, const pair<int, int>& q) {
            return nums1[p.first] + nums2[p.second] > nums1[q.first] + nums2[q.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);  // ���ȼ����У����� [index1, index2]
        for (int i = 0; i < nums1.size(); i++)  // �� nums1 ������������ӣ�nums2 ��������ʼʱ���� 0
            pq.push(make_pair(i, 0));
        while(!pq.empty() && v.size() < k)      // ��൯�� k ��
        {
            auto p = pq.top();
            pq.pop();
            v.push_back({nums1[p.first], nums2[p.second]});
            if (p.second < nums2.size() - 1)    // �� index2 �� 1 ֮��������
                pq.push(make_pair(p.first, p.second + 1));
        }
        return v;
    }
};

// �����һ�����鳤��Ϊm���ڶ�������Ϊn��ʵ���Ͼ���Ҫ���������Էֳ�m�ݣ�
// ÿ�ݶ��ǵ�һ��������ĳ�����͵ڶ���������ÿһ������϶��ɣ����ڵڶ��������ǵ������ģ�
// ������m������Ҳ�����ǵ������ġ������ת��Ϊ�˴�m�����������У�ȡ����С��k�����ԣ���·�鲢���⡣
// ��һ���ѽ�ÿһ·��С��Ԫ�ؼ�����У��Զ���Ԫ��������ѣ�ÿ��һ���ͽ��������е���һ��Ԫ�ؼ�������С�

