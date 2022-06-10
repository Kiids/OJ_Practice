/*
����һ���ַ��� path ����ʾָ��ĳһ�ļ���Ŀ¼��?Unix ��� ����·�� ���� '/' ��ͷ�������㽫��ת��Ϊ���Ӽ��Ĺ淶·����
�� Unix �����ļ�ϵͳ�У�һ���㣨.����ʾ��ǰĿ¼�������⣬������ ��..��?��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼�������߶������Ǹ������·������ɲ��֡�������������б�ܣ�����'//'��������Ϊ����б�� '/' �� ���ڴ����⣬�κ�������ʽ�ĵ㣨���磬'...'��������Ϊ�ļ�/Ŀ¼���ơ�
��ע�⣬���ص� �淶·�� ������ѭ������ʽ��
ʼ����б�� '/' ��ͷ��
����Ŀ¼��֮�����ֻ��һ��б�� '/' ��
���һ��Ŀ¼����������ڣ����� �� '/' ��β��
���⣬·���������Ӹ�Ŀ¼��Ŀ���ļ���Ŀ¼��·���ϵ�Ŀ¼���������� '.' �� '..'����
���ؼ򻯺�õ��� �淶·�� ��
ʾ�� 1��
���룺path = "/home/"
�����"/home"
���ͣ�ע�⣬���һ��Ŀ¼������û��б�ܡ� 
ʾ�� 2��
���룺path = "/../"
�����"/"
���ͣ��Ӹ�Ŀ¼����һ���ǲ����еģ���Ϊ��Ŀ¼������Ե������߼���
ʾ�� 3��
���룺path = "/home//foo/"
�����"/home/foo"
���ͣ��ڹ淶·���У��������б����Ҫ��һ��б���滻��
ʾ�� 4��
���룺path = "/a/./b/../../c/"
�����"/c"
��ʾ��
1 <= path.length <= 3000
path ��Ӣ����ĸ�����֣�'.'��'/' �� '_' ��ɡ�
path ��һ����Ч�� Unix ������·����
*/

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss;
        ss << path;
        string readcache;
        vector<string> filename;
        while (getline(ss,readcache,'/') )
        {
            if (readcache == "" )
                continue;
            else if (readcache == "." )
                continue;
            else if (readcache == ".." )
            {
                if (filename.size() > 0 )
                    filename.pop_back();
            }
            else
                filename.push_back(readcache);
        }

        string s="";
        for (int i = 0; i < filename.size() ; i++ )
            s.append("/" + filename[i] );
        if (s == "" )
            return "/";
        return s;
    }
};
