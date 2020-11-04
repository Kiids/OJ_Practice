/*
����һ��������·ͼ������·ͼ�е�������·������ paths ��ʾ������ paths[i] = [cityAi, cityBi] ��ʾ����·����� cityAi ֱ��ǰ�� cityBi �������ҳ�������е��յ�վ����û���κο���ͨ���������е���·�ĳ��С�
��Ŀ���ݱ�֤��·ͼ���γ�һ��������ѭ������·�����ֻ����һ�������յ�վ��
ʾ�� 1��
���룺paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
�����"Sao Paulo" 
���ͣ��� "London" ���������ִ��յ�վ "Sao Paulo" ���������е�·���� "London" -> "New York" -> "Lima" -> "Sao Paulo" ��
ʾ�� 2��
���룺paths = [["B","C"],["D","B"],["C","A"]]
�����"A"
���ͣ����п��ܵ���·�ǣ�
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
��Ȼ�������յ�վ�� "A" ��
ʾ�� 3��
���룺paths = [["A","Z"]]
�����"Z"
��ʾ��
1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
�����ַ������ɴ�СдӢ����ĸ�Ϳո��ַ���ɡ�
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>  m;
        for (auto e : paths)
        {
            m[e[0]] += 1;
            m[e[1]] += 0;
        }
        for (auto e : m)
            if (e.second == 0)
                return e.first;
        return "";
    }
};
// �������Ϊ0�Ľڵ�
