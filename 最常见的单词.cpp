/*
����һ������ (paragraph) ��һ�����õ����б� (banned)�����س��ִ�����࣬ͬʱ���ڽ����б��еĵ��ʡ�
��Ŀ��֤������һ���ʲ��ڽ����б��У����Ҵ�Ψһ��
�����б��еĵ�����Сд��ĸ��ʾ�����������š������еĵ��ʲ����ִ�Сд���𰸶���Сд��ĸ��
ʾ����
����: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
���: "ball"
����: 
"hit" ������3�Σ�������һ�����õĵ��ʡ�
"ball" ������2�� (ͬʱû���������ʳ���2��)���������Ƕ�������ִ������ģ��Ҳ��ڽ����б��еĵ��ʡ� 
ע�⣬������Щ�����ڶ����ﲻ���ִ�Сд����������Ҫ���ԣ���ʹ�ǽ����ŵ���Ҳ���ԣ� ���� "ball,"���� 
"hit"�������յĴ𰸣���Ȼ�����ִ������࣬�����ڽ��õ����б��С�
��ʾ��
1 <= ���䳤�� <= 1000
0 <= ���õ��ʸ��� <= 100
1 <= ���õ��ʳ��� <= 10
����Ψһ��, �Ҷ���Сд��ĸ?(��ʹ�� paragraph ���Ǵ�д�ģ���ʹ��һЩ�ض������ʣ��𰸶���Сд�ġ�)
paragraph ֻ������ĸ���ո�����б�����!?',;.
������û�����ַ����ߴ������ַ��ĵ��ʡ�
������ֻ������ĸ���������ʡ�ԺŻ������������š�
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> s;
        for (auto& e : banned)
            s.insert(e);

        int maxcnt = 0;
        string ret;

        for (auto& c : paragraph)
            c = isalpha(c) ? c : ' ';
        stringstream ss(paragraph);
        string t;
        while (ss >> t)
        {
            for (auto& c : t)
                c = tolower(c);
            if (s.count(t) != 0)
                continue;
            m[t]++;
            if (m[t] > maxcnt)
            {
                maxcnt = m[t];
                ret = t;
            }
        }
        return ret;
    }
};
