/*
�����ļҾӳǴ������������һֱ���ǵĿɵ�����ܣ�������Լ����鶼�����µ�����ϡ�
���Ҫ�ڷŵ��� books ������ã�����һ�����������£��� i ����ĺ��Ϊ books[i][0]���߶�Ϊ books[i][1]��
��˳�� ����Щ��ڷŵ��ܿ��Ϊ shelf_width ������ϡ�
��ѡ�������������ϣ����ǵĺ��֮��С�ڵ�����ܵĿ�� shelf_width����Ȼ���ٽ�һ����ܡ��ظ�������̣�ֱ�������е��鶼��������ϡ�
��Ҫע����ǣ����������̵�ÿ�������У��ڷ����˳����������õ�˳����ͬ�� ���磬��������� 5 ���飬��ô���ܵ�һ�ְڷ�����ǣ���һ�͵ڶ�������ڵ�һ������ϣ�����������ڵڶ�������ϣ����ĺ͵��屾��������һ������ϡ�
ÿһ�����ڷŵ�������߶Ⱦ�����һ����ܵĲ�ߣ��������ĸ߶�Ϊ�����֮�͡�
�����ַ�ʽ������ܣ��������������ܵ���С�߶ȡ�
ʾ����
���룺books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
�����6
���ͣ�
3 ����ܵĸ߶Ⱥ�Ϊ 1 + 3 + 2 = 6 ��
�� 2 ���鲻�ط��ڵ�һ������ϡ�
��ʾ��
1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000
*/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size() + 1, INT_MAX);
        dp[books.size()] = 0;
        for (int i = books.size() - 1; i >= 0; i--)
        {
            int max_book_height = 0, left_width = shelfWidth;
            for (int j = i; j < books.size() && left_width >= books[j][0]; j++)
            {
                max_book_height = max(max_book_height, books[j][1]);
                dp[i] = min(dp[i], max_book_height + dp[j+1]);
                left_width -= books[j][0];
            }
        }
        return dp[0];
    }
};
