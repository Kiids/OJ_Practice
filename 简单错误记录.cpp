/*
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
����
1�� ��¼���8�������¼��ѭ����¼������˵���ֻ��������ֵİ��������¼��������ͬ�Ĵ����¼�����ļ����ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�
2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����
��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ��� �������� ��Ŀ��һ���ո�������磺
ʾ��1
����
E:\V1R2\product\fpgadrive.c   1325
���
fpgadrive.c 1325 1
*/

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

//�ָ��ַ���
vector<string> split(string str, string delim) 
{
    vector<string> ret;
    if (str == "")
        return ret;
    
    //string����ת��Ϊchar*����
    char* strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());
    
    char* d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    
    // char *strtok(char s[], const char *delim);
    // �ֽ��ַ���Ϊһ���ַ�����sΪҪ�ֽ���ַ�����delimΪ�ָ����ַ�����
    char* p = strtok(strs, d);
    while (p != NULL)
    {
        string s = p;  // �ָ�õ����ַ���ת��Ϊstring����
        ret.push_back(s);  // ����������
        p = strtok(NULL, d);
    }
    return ret;
}
int main()
{
    vector<string> allname;
    vector<string> allhang;
    vector<string> filename;
    vector<int> filehang;
    vector<int> number;
    string a,b;
    while (cin >> a >> b)
    {
        allname.push_back(a);
        allhang.push_back(b);
    }
    int t = 0;
    for (; t < allname.size();t++)
    {
        string input = allname[t] + " " + allhang[t];
        string name;
        int hang;
        vector<string> a1 = split(input, " ");
        if (a1.size() == 2) 
        {
            hang = atoi(a1[1].c_str());
            vector<string> a2 = split(a1[0], "\\");
            // ��֤���16���ļ����ַ�����ɾ��·���������ļ���
            if (a2[a2.size() - 1].length() > 16)
                name = a2[a2.size() - 1].substr(a2[a2.size() - 1].length() - 16, 16);
			else
                name = a2[a2.size() - 1];
            
            // ѭ����¼�������Ƿ����ظ�
            if (filename.size() == 0)
            {
                filename.push_back(name);
                filehang.push_back(hang);
                number.push_back(1);
            }
            else
            {
                int tmp = 0;
                int i = 0;
                for (; i < filename.size(); i++)
                {
                    if (filename[i].compare(name) == 0 && filehang[i] == hang)
                    {
                        tmp = 1;
                        break;
                    }
                }
                if (tmp == 1)
                    number[i]++;
                else
                {
                    filename.push_back(name);
                    filehang.push_back(hang);
                    number.push_back(1);
                }
            }
        }
    }
    if (filename.size() <= 8)
    {
        for (int z = 0; z < filename.size(); z++)
         cout << filename[z] << " " << filehang[z] << " " << number[z] << endl;
    }
    else
    {
       for (int z = filename.size()-8; z < filename.size(); z++)
         cout << filename[z] << " " << filehang[z] << " " << number[z] << endl;
    }
    return 0;
}
