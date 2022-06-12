/*
������һ��ͬʱ�洢�ļ���Ŀ¼���ļ�ϵͳ����ͼչʾ���ļ�ϵͳ��һ��ʾ����
���ｫ dir ��Ϊ��Ŀ¼�е�ΨһĿ¼��dir ����������Ŀ¼ subdir1 �� subdir2 ��subdir1 �����ļ� file1.ext ����Ŀ¼ subsubdir1��subdir2 ������Ŀ¼ subsubdir2������Ŀ¼�°����ļ� file2.ext ��
���ı���ʽ�У�������ʾ( ��ʾ�Ʊ��)��
dir
  subdir1
    file1.ext
    subsubdir1
  subdir2
    subsubdir2
      file2.ext
����Ǵ����ʾ��������ļ�ϵͳ����дΪ "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" ��'\n' �� '\t' �ֱ��ǻ��з����Ʊ����
�ļ�ϵͳ�е�ÿ���ļ����ļ��ж���һ��Ψһ�� ����·�� ��������򿪲��ܵ����ļ�/Ŀ¼����λ�õ�Ŀ¼˳������·���� '/' ���ӡ����������У�ָ�� file2.ext �� ����·�� �� "dir/subdir2/subsubdir2/file2.ext" ��ÿ��Ŀ¼������ĸ�����ֺ�/��ո���ɣ�ÿ���ļ�����ѭ name.extension �ĸ�ʽ������ name �� extension����ĸ�����ֺ�/��ո���ɡ�
����һ����������ʽ��ʾ�ļ�ϵͳ���ַ��� input �������ļ�ϵͳ�� ָ�� �ļ� �� �����·�� �ĳ��� �� ���ϵͳ��û���ļ������� 0��
ʾ�� 1��
���룺input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
�����20
���ͣ�ֻ��һ���ļ�������·��Ϊ "dir/subdir2/file.ext" ��·������ 20
ʾ�� 2��
���룺input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
�����32
���ͣ����������ļ���
"dir/subdir1/file1.ext" ��·������ 21
"dir/subdir2/subsubdir2/file2.ext" ��·������ 32
���� 32 ����Ϊ�������·��
ʾ�� 3��
���룺input = "a"
�����0
���ͣ��������κ��ļ�
ʾ�� 4��
���룺input = "file1.txt\nfile2.txt\nlongfile.txt"
�����12
���ͣ���Ŀ¼���� 3 ���ļ���
��Ϊ��Ŀ¼���κζ����ľ���·��ֻ�����Ʊ������Դ��� "longfile.txt" ��·������Ϊ 12
��ʾ��
1 <= input.length <= 10^4
input ���ܰ���Сд���д��Ӣ����ĸ��һ�����з� '\n'��һ���Ʊ�� '\t'��һ���� '.'��һ���ո� ' '�������֡�
*/

class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';           // �����ڱ�
        vector<int> file(1, 0);  // �����ڱ� ������ֿ�ջ��� ջ��Ԫ�ر�ʾ��ǰ����·������(���� '/')
        auto p1 = input.begin(), p2 = find(p1, input.end(), '\n');
        int ret = 0, depth = 0;
        while (p1 != input.end())
        {
            depth = count(p1, p2, '\t');  // ��ǰ�ļ��в㼶 �ж����Ʊ�����Ƕ��ٲ�
            file.resize(depth + 1);       // �ͷŲ���Ҫ�Ĳ㼶 ��Ϊǰ����һ���ڱ����Ա�������+1
            file.push_back(file.at(depth) + p2 - p1 - depth);  //·������
            if (find(p1 + depth, p2, '.') != p2)      // ͨ������.�ж��Ƿ���һ���ļ�
                ret = max(ret, file.back() + depth);  // ���� '/'������
            p1 = p2 + 1;  // �������
            p2 = find(p1, input.end(), '\n');
        }
        return ret;
    }
};
