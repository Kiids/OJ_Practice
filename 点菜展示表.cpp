/*
����һ������ orders����ʾ�ͻ��ڲ�������ɵĶ�����ȷ�е�˵�� orders[i]=[customerNamei,tableNumberi,foodItemi] ������ customerNamei �ǿͻ���������tableNumberi �ǿͻ����ڲ��������ţ��� foodItemi �ǿͻ���Ĳ�Ʒ���ơ�
���㷵�ظò����� ���չʾ�� �������ű��У����е�һ��Ϊ���⣬���һ��Ϊ�������� ��Table�� ������ÿһ�ж��ǰ���ĸ˳�����еĲ�Ʒ���ơ�������ÿһ���е������ʾÿ�Ų�����������Ӧ��Ʒ��������һ��Ӧ�����Ӧ�����ţ�����������д�µ��Ĳ�Ʒ������
ע�⣺�ͻ��������ǵ��չʾ���һ���֡����⣬���е�������Ӧ�ð����������������С�
ʾ�� 1��
���룺orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
�����[["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
���ͣ�
���չʾ��������ʾ��
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
���ڲ��� 3��David ���� "Ceviche" �� "Fried Chicken"���� Rous ���� "Ceviche"
������ 5��Carla ���� "Water" �� "Ceviche"
���� 10��Corina ���� "Beef Burrito" 
ʾ�� 2��
���룺orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
�����[["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
���ͣ�
���ڲ��� 1��Adam �� Brianna ������ "Canadian Waffles"
������ 12��James, Ratesh �� Amadeus ������ "Fried Chicken"
ʾ�� 3��
���룺orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
�����[["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
��ʾ��
1 <=?orders.length <= 5 * 10^4
orders[i].length == 3
1 <= customerNamei.length, foodItemi.length <= 20
customerNamei �� foodItemi �ɴ�СдӢ����ĸ���ո��ַ� ' ' ��ɡ�
tableNumberi �� 1 �� 500 ��Χ�ڵ�������
*/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> v;
        map<int, vector<string>> m;
        set<string> s;
        for (int i = 0; i < orders.size(); i++)
        {
            m[atoi(orders[i][1].c_str())].push_back(orders[i][2]);
            s.insert(orders[i][2]);
        }
        v.resize(m.size() + 1);
        v[0].push_back("Table");
        for (set<string>::iterator it = s.begin(); it != s.end(); it++)
            v[0].push_back(*it);
        int i = 1;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            v[i].push_back(to_string(it->first));
            for (auto ite = s.begin(); ite != s.end(); ite++)
                v[i].push_back(to_string(count(it->second.begin(),it->second.end(),*ite)));
            i++;
        }
        return v;
    }
};
