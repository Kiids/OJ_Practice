/*
����һ���͹���Ϣ���� restaurants������  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]�������ʹ������������������������Щ�͹���Ϣ��
������ʳ���Ѻù����� veganFriendly ��ֵ����Ϊ true ���� false�����Ϊ true ����ζ����Ӧ��ֻ���� veganFriendlyi Ϊ true �Ĳ͹ݣ�Ϊ false ����ζ�ſ��԰����κβ͹ݡ����⣬���ǻ������۸� maxPrice �������� maxDistance ���������������Ƿֱ��ǲ����ļ۸����غ;������ص����ֵ��
���˺󷵻ز͹ݵ� id������ rating �Ӹߵ���������� rating ��ͬ����ô�� id �Ӹߵ������򡣼������ veganFriendlyi �� veganFriendly Ϊ true ʱȡֵΪ 1��Ϊ false ʱ��ȡֵΪ 0 ��
ʾ�� 1��
���룺restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
�����[3,1,5] 
���ͣ� 
��Щ�͹�Ϊ��
�͹� 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
�͹� 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
�͹� 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
�͹� 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
�͹� 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
�ڰ��� veganFriendly = 1, maxPrice = 50 �� maxDistance = 10 ���й��˺����ǵõ��˲͹� 3, �͹� 1 �� �͹� 5�������ִӸߵ������򣩡� 
ʾ�� 2��
���룺restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, maxDistance = 10
�����[4,3,2,1,5]
���ͣ��͹���ʾ�� 1 ��ͬ������ veganFriendly = 0 �Ĺ��������£�Ӧ�ÿ������в͹ݡ�
ʾ�� 3��
���룺restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, maxDistance = 3
�����[4,5]
��ʾ��
1 <= restaurants.length <= 10^4
restaurants[i].length == 5
1 <= idi, ratingi, pricei, distancei <= 10^5
1 <= maxPrice, maxDistance <= 10^5
veganFriendlyi �� veganFriendly ��ֵΪ 0 �� 1 ��
���� idi ������ͬ��
*/

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> v;
        for (int i = 0; i < restaurants.size(); i++)
            if ((veganFriendly == 0 || restaurants[i][2] == veganFriendly) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
                v.push_back(restaurants[i]);
                
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a[1] == b[1])
                return a[0] > b[0];
            else
                return a[1] > b[1];
        });
        
        vector<int> m;
        for (int i = 0; i < v.size(); i++)
            m.push_back(v[i][0]);
        return m;
    }
};
