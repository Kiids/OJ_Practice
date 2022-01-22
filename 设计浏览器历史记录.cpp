/*
����һ��ֻ֧�ֵ�����ǩҳ�� ����� ���ʼ���������ҳ�� homepage ������Է�����������վ url ��Ҳ�����������ʷ�к��� steps ����ǰ�� steps ����
����ʵ�� BrowserHistory �ࣺ
BrowserHistory(string homepage) ���� homepage ��ʼ��������ࡣ
void visit(string url) �ӵ�ǰҳ��ת���� url ��Ӧ��ҳ��  ��ִ�д˲�����������ʷǰ���ļ�¼ȫ��ɾ����
string back(int steps) �������ʷ�к��� steps ���������ֻ���������ʷ�к������� x ���� steps > x ����ô��ֻ���� x �����뷵�غ��� ���� steps ���Ժ�� url ��
string forward(int steps) �������ʷ��ǰ�� steps ���������ֻ���������ʷ��ǰ������ x ���� steps > x ����ô��ֻǰ�� x �����뷵��ǰ�� ���� steps���Ժ�� url ��
ʾ����
���룺
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
�����
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
���ͣ�
BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
browserHistory.visit("google.com");       // ��ԭ������� "leetcode.com" ������ "google.com"
browserHistory.visit("facebook.com");     // ��ԭ������� "google.com" ������ "facebook.com"
browserHistory.visit("youtube.com");      // ��ԭ������� "facebook.com" ������ "youtube.com"
browserHistory.back(1);                   // ��ԭ������� "youtube.com" �����˵� "facebook.com" ������ "facebook.com"
browserHistory.back(1);                   // ��ԭ������� "facebook.com" �����˵� "google.com" ������ "google.com"
browserHistory.forward(1);                // ��ԭ������� "google.com" ��ǰ���� "facebook.com" ������ "facebook.com"
browserHistory.visit("linkedin.com");     // ��ԭ������� "facebook.com" �� ���� "linkedin.com"
browserHistory.forward(2);                // ��ԭ������� "linkedin.com" �����޷�ǰ���κβ�����
browserHistory.back(2);                   // ��ԭ������� "linkedin.com" ���������������ȵ� "facebook.com" ��Ȼ�� "google.com" �������� "google.com"
browserHistory.back(7);                   // ��ԭ������� "google.com"�� ��ֻ�ܺ���һ���� "leetcode.com" �������� "leetcode.com"
��ʾ��
1 <= homepage.length <= 20
1 <= url.length <= 20
1 <= steps <= 100
homepage �� url ��ֻ���� '.' ����СдӢ����ĸ��
������ 5000 �� visit�� back �� forward ������
*/

class BrowserHistory {
    vector<string> s;
    int i = 0;
public:
    BrowserHistory(string homepage) {
        s.push_back(homepage);
    }
    
    void visit(string url) {
        s.erase(s.begin() + i + 1, s.end());
        s.push_back(url);
        i++;
    }
    
    string back(int steps) {
        i = max(0, i - steps);
        return s[i];
    }
    
    string forward(int steps) {
        i = min(i + steps, (int)(s.size()) - 1);
        return s[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
