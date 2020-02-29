/*
��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ�
���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������
ʾ�� 1��
����: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
���: ["i", "love"]
����: "i" �� "love" Ϊ���ִ��������������ʣ���Ϊ2�Ρ�
    ע�⣬����ĸ˳�� "i" �� "love" ֮ǰ��
ʾ�� 2��
����: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
���: ["the", "is", "sunny", "day"]
����: "the", "is", "sunny" �� "day" �ǳ��ִ��������ĸ����ʣ����ִ�������Ϊ 4, 3, 2 �� 1 �Ρ�
ע�⣺
�ٶ� k ��Ϊ��Чֵ�� 1 �� k �� ����Ԫ������
����ĵ��ʾ���Сд��ĸ��ɡ�
��չ��ϰ��
������ O(n log k) ʱ�临�ӶȺ� O(n) �ռ临�ӶȽ����
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (auto& w : words)
            m[w]++;
        multimap<int, string, greater<int>> mm;  // mapĬ�ϱȽ���lessС�ڣ�greater<int>����
        for (auto& i : m)
            mm.insert(make_pair(i.second, i.first));
        vector<string> ret;
        auto it = mm.begin();
        while (it != mm.end())
        {
            if (k > 0)
            {
                ret.push_back(it->second);
                k--;
            }
            else
                break;
            it++;
        }
        return ret;
    }
};
