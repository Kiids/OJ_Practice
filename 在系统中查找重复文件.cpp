/*
����һ��Ŀ¼��Ϣ�б�����Ŀ¼·�����Լ���Ŀ¼�е����а������ݵ��ļ�������Ҫ�ҵ��ļ�ϵͳ�е������ظ��ļ����·����һ���ظ����ļ����ٰ�������������ȫ��ͬ���ݵ��ļ���
�����б��еĵ���Ŀ¼��Ϣ�ַ����ĸ�ʽ���£�
"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
����ζ���� n ���ļ���f1.txt, f2.txt ... fn.txt �����ݷֱ��� f1_content, f2_content ... fn_content����Ŀ¼ root/d1/d2/.../dm �¡�ע�⣺n>=1 �� m>=0����� m=0�����ʾ��Ŀ¼�Ǹ�Ŀ¼��
��������ظ��ļ�·������б�����ÿ���飬������������ͬ���ݵ��ļ��������ļ�·�����ļ�·���Ǿ������и�ʽ���ַ�����
"directory_path/file_name.txt"
ʾ�� 1��
���룺
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
�����  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
ע��
�����������Ҫ˳��
�����Լ���Ŀ¼�����ļ������ļ�����ֻ����ĸ�����֣������ļ����ݵĳ����� [1��50] �ķ�Χ�ڡ�
�������ļ������� [1��20000] ����Χ�ڡ�
�����Լ�����ͬһĿ¼��û���κ��ļ���Ŀ¼������ͬ�����ơ�
�����Լ���ÿ��������Ŀ¼��Ϣ����һ��Ψһ��Ŀ¼��Ŀ¼·�����ļ���Ϣ��һ���ո�ָ���
��Խ�����ĺ����ж���
��������һ���������ļ�ϵͳ��������������ļ�������������ǿ��������
����ļ����ݷǳ���GB���𣩣���������޸����Ľ��������
���ÿ��ֻ�ܶ�ȡ 1 kb ���ļ�����������޸Ľ��������
�޸ĺ�Ľ��������ʱ�临�Ӷ��Ƕ��٣��������ʱ�Ĳ��ֺ������ڴ�Ĳ�����ʲô������Ż���
���ȷ�������ֵ��ظ��ļ������󱨣�
*/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (auto path : paths)
        {
            istringstream iss(path);
            string dir, file;
            iss >> dir;
            while (!iss.eof())
            {
                iss >> file;
                int index = file.find('(');
                string content = file.substr(index + 1, file.size() - 1);
                m[content].push_back(dir + "/" + file.substr(0, index));
            }
        }
        vector<vector<string>> ret;
        for (auto t : m)
            if ((int)t.second.size() > 1)
                ret.push_back(t.second);
        return ret;
    }
};
