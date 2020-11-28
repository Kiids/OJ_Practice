/*
һ����վ��������"discuss.leetcode.com"�������˶������������Ϊ�������������õ���"com"����һ������"leetcode.com"����͵�һ��Ϊ"discuss.leetcode.com"�������Ƿ�������"discuss.leetcode.com"ʱ��Ҳͬʱ�������丸����"leetcode.com"�Լ��������� "com"��
����һ�������ʴ�������������ϣ�Ҫ��ֱ����ÿ�����������ʵĴ��������ʽΪ���ʴ���+�ո�+��ַ�����磺"9001 discuss.leetcode.com"��
�����������һ����ʴ�����������ϵ��б�cpdomains ��Ҫ����������������ķ��ʴ����������ʽ�������ʽ��ͬ�����޶��Ⱥ�˳��
ʾ�� 1:
����: 
["9001 discuss.leetcode.com"]
���: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
˵��: 
�����н�����һ����վ������"discuss.leetcode.com"������ǰ�ļ��裬������"leetcode.com"��"com"���ᱻ���ʣ��������Ƕ���������9001�Ρ�
ʾ�� 2
����: 
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
���: 
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
˵��: 
���ռ��裬�����"google.mail.com" 900�Σ�"yahoo.com" 50�Σ�"intel.mail.com" 1�Σ�"wiki.org" 5�Ρ�
�����ڸ������������"mail.com" 900+1 = 901�Σ�"com" 900 + 50 + 1 = 951�Σ��� "org" 5 �Ρ�
ע�����
 cpdomains �ĳ���С�� 100��
ÿ�������ĳ���С��100��
ÿ��������ַ����һ��������"."���š�
����������һ�������ķ��ʴ�����С��10000��
*/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ret;
        unordered_map<string, int> m;
        for (auto& word : cpdomains)
        {
            int index = word.find(' ');
            int num = stoi(word.substr(0, index));
            string dmName = word.substr(index + 1);
            while (index > 0)
            {
                m[dmName] += num;
                index = dmName.find('.');
                dmName = dmName.substr(index + 1);
            }
        }
        for (auto& c : m)
            ret.push_back(to_string(c.second) + " " + c.first);
        return ret;
    }
};
