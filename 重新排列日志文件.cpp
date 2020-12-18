/*
����һ����־���� logs��ÿ����־�����Կո�ָ����ִ���
����ÿ����־�����һ����Ϊ��ĸ�����ֻ�ϵ� ��ʶ�� ������ʶ��֮���������Ϊ��һ����־�� ���� ��
����ʶ��֮�⣬�����־���Сд��ĸ��ɵģ���Ϊ ��ĸ��־
����ʶ��֮�⣬�����־���������ɵģ���Ϊ ������־
��Ŀ�������ݱ�֤ÿ����־�����ʶ������������һ���֡�
�밴����������־��������
���� ��ĸ��־ ������ ������־ ֮ǰ��
��ĸ��־ �����ݲ�ͬʱ�����Ա�ʶ���󣬰�������ĸ˳��������������ͬʱ������ʶ������
������־ Ӧ�ð�ԭ����˳�����С�
������־������˳��
ʾ�� ��
���룺["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
�����["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
��ʾ��
0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] ��֤��һ����ʶ�������ұ�ʶ��������һ���֡�
*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp_stable);
        return logs;
    }

    static bool cmp_stable(const string &a, const string &b)
    {
        int pa = 0;
        int pb = 0;
        while (a[pa++] != ' ');
        while (b[pb++] != ' ');
        bool aIsNumberLog = a[pa] >= '0' && a[pa] <= '9';
        bool bIsNumberLog = b[pb] >= '0' && b[pb] <= '9';
        
        if (!aIsNumberLog && bIsNumberLog)
            return true;
        if (aIsNumberLog && !bIsNumberLog)
            return false;
        if (aIsNumberLog && bIsNumberLog)
            return false;
        // return false �Ļ�����a��b����������־����ȣ���ô���ǽ��ᱣ��ԭ����˳��

        int cmp = a.compare(pa, -1, b, pb, -1);
        if (cmp == 0)
            return a.compare(0, pa, b, 0, pb) <= 0;
        else if (cmp < 0)
            return true; // a is lower
        else
            return false;
    }
};
