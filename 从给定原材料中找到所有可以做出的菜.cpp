/*
���� n ����ͬ�˵���Ϣ������һ���ַ������� recipes ��һ����ά�ַ������� ingredients ���� i ���˵�����Ϊ recipes[i] ����������� ���� ��ԭ���� ingredients[i] ����ô����� ���� ����ˡ�һ���˵�ԭ���Ͽ����� ��һ�� �ˣ�Ҳ����˵ ingredients[i] ���ܰ��� recipes ����һ���ַ�����
ͬʱ����һ���ַ������� supplies �����������ʼʱӵ�е�����ԭ���ϣ�ÿһ��ԭ�����㶼�����޶ࡣ
���㷵����������������вˡ�������� ����˳�� �������ǡ�
ע�������������ǵ�ԭ�����п��ܻ��������
ʾ�� 1��
���룺recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
�����["bread"]
���ͣ�
���ǿ������� "bread" ����Ϊ������ԭ���� "yeast" �� "flour" ��
ʾ�� 2��
���룺recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
�����["bread","sandwich"]
���ͣ�
���ǿ������� "bread" ����Ϊ������ԭ���� "yeast" �� "flour" ��
���ǿ������� "sandwich" ����Ϊ������ԭ���� "meat" �ҿ�������ԭ���� "bread" ��
ʾ�� 3��
���룺recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
�����["bread","sandwich","burger"]
���ͣ�
���ǿ������� "bread" ����Ϊ������ԭ���� "yeast" �� "flour" ��
���ǿ������� "sandwich" ����Ϊ������ԭ���� "meat" �ҿ�������ԭ���� "bread" ��
���ǿ������� "burger" ����Ϊ������ԭ���� "meat" �ҿ�������ԭ���� "bread" �� "sandwich" ��
ʾ�� 4��
���룺recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast"]
�����[]
���ͣ�
����û�������κβˣ���Ϊ����ֻ��ԭ���� "yeast" ��
��ʾ��
n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j] �� supplies[k] ֻ����СдӢ����ĸ��
���� recipes �� supplies �е�ֵ������ͬ��
ingredients[i] �е��ַ���������ͬ��
*/

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = (int)recipes.size();
        vector<string> v;

        unordered_map<string, vector<string>> adjvex;
        unordered_map<string, int> indegree;
        for (int i = 0; i < n; i++)
        {
            string x = recipes[i];
            for (string y : ingredients[i])
            {
                adjvex[y].push_back(x);
                indegree[x]++;
            }
        }

        queue<string> q;
        for (string sup : supplies)
            q.push(sup);
        while (!q.empty())
        {
            string x = q.front();
            q.pop();
            for (string y : adjvex[x])
            {
                indegree[y]--;
                if (indegree[y] == 0)
                {
                    q.push(y);
                    v.push_back(y);
                }
            }
        }
        return v;
    }
};
