/*
ÿ������ʼ�����һ���������ƺ�һ��������ɣ��� @ ���ŷָ���
���磬�� alice@leetcode.com�У� alice �Ǳ������ƣ��� leetcode.com ��������
����Сд��ĸ����Щ�����ʼ������ܰ��� '.' �� '+'��
����ڵ����ʼ���ַ�ı������Ʋ����е�ĳЩ�ַ�֮����Ӿ�㣨'.'��������������ʼ�����ת��������������û�е��ͬһ��ַ�����磬"alice.z@leetcode.com�� �� ��alicez@leetcode.com�� ��ת����ͬһ�����ʼ���ַ�� ����ע�⣬�˹�����������������
����ڱ�����������ӼӺţ�'+'���������Ե�һ���Ӻź�����������ݡ����������ĳЩ�����ʼ������� m.y+name@email.com ��ת���� my@email.com�� ��ͬ�����˹�����������������
����ͬʱʹ������������
���������ʼ��б� emails�����ǻ����б��е�ÿ����ַ����һ������ʼ���ʵ���յ��ʼ��Ĳ�ͬ��ַ�ж��٣�
ʾ����
���룺["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
�����2
���ͣ�ʵ���յ��ʼ����� "testemail@leetcode.com" �� "testemail@lee.tcode.com"��
��ʾ��
1 <= emails[i].length <= 100
1 <= emails.length <= 100
ÿ�� emails[i] ���������ҽ���һ�� '@' �ַ���
*/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        for_each(emails.begin(), emails.end(), deal);
        return set(emails.begin(), emails.end()).size();
    }

    static void deal(string& email)
    {
        int i = 0;
        while (i != email.find("@"))
        {
            if (email[i] == '.')
                email.erase(i, 1);
            else if (email[i] == '+')
                email.erase(i, email.find("@") - i);
            else
                i++;
        }
    }
};
