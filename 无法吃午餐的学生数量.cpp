/*
ѧУ����������ṩԲ�κͷ��ε������Σ��ֱ������� 0 �� 1 ��ʾ������ѧ��վ��һ�������ÿ��ѧ��Ҫôϲ��Բ�ε�Ҫôϲ�����εġ�
�����������ε�������ѧ����������ͬ�����������ζ�����һ�� ջ �ÿһ�֣�
���������ǰ���ѧ�� ϲ�� ջ���������Σ���ô�� ������ ���뿪���С�
��������ѧ���� ������������� ���ص����е�β����
������̻�һֱ����������������ѧ������ϲ��ջ����������Ϊֹ��
���������������� students �� sandwiches ������ sandwiches[i] ��ջ����� i       �������ε����ͣ�i = 0 ��ջ�Ķ������� students[j] �ǳ�ʼ������� j       ��ѧ���������ε�ϲ�ã�j = 0 �Ƕ��е��ʼλ�ã������㷵���޷�����͵�ѧ��������
ʾ�� 1��
���룺students = [1,1,0,0], sandwiches = [0,1,0,1]
�����0 
���ͣ�
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [1,0,0,1]��
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [0,0,1,1]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = [0,1,1]��������ջΪ sandwiches = [1,0,1]��
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [1,1,0]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = [1,0]��������ջΪ sandwiches = [0,1]��
- ��ǰ���ѧ��������ϵ������Σ����ص����е�ĩβ��ѧ�����б�Ϊ students = [0,1]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = [1]��������ջΪ sandwiches = [1]��
- ��ǰ���ѧ��������ϵ������Σ�ʣ��ѧ������Ϊ students = []��������ջΪ sandwiches = []��
��������ѧ�����������γԡ�
ʾ�� 2��
���룺students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
�����3
��ʾ��
1 <= students.length, sandwiches.length <= 100
students.length == sandwiches.length
sandwiches[i] Ҫô�� 0 ��Ҫô�� 1 ��
students[i] Ҫô�� 0 ��Ҫô�� 1 ��
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stusum = 0;
        for (int i = 0; i < students.size(); i++)
            stusum += students[i];
        queue<int> q;
        for (int i = 0; i < students.size(); i++)
            q.push(students[i]);
        int i = 0;
        while (i < sandwiches.size())
        {
            if (q.front() == sandwiches[i])
            {
                stusum -= sandwiches[i];
                q.pop();
                i++;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
            if (q.size() == 0)
                break;
            if ((sandwiches[i] != q.front() && stusum == 0 ) || (sandwiches[i] != q.front() && stusum == q.size()))
                break;
        }
        return sandwiches.size() - i;
    }
};
