/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理：
1、 记录最多8条错误记录，循环记录（或者说最后只输出最后出现的八条错误记录），对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。
输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
示例1
输入
E:\V1R2\product\fpgadrive.c   1325
输出
fpgadrive.c 1325 1
*/

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

//分割字符串
vector<string> split(string str, string delim) 
{
    vector<string> ret;
    if (str == "")
        return ret;
    
    //string类型转换为char*类型
    char* strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());
    
    char* d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());
    
    // char *strtok(char s[], const char *delim);
    // 分解字符串为一组字符串。s为要分解的字符串，delim为分隔符字符串。
    char* p = strtok(strs, d);
    while (p != NULL)
    {
        string s = p;  // 分割得到的字符串转换为string类型
        ret.push_back(s);  // 存入结果数组
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
            // 保证最多16个文件名字符，并删除路径，保留文件名
            if (a2[a2.size() - 1].length() > 16)
                name = a2[a2.size() - 1].substr(a2[a2.size() - 1].length() - 16, 16);
			else
                name = a2[a2.size() - 1];
            
            // 循环记录，检验是否有重复
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
