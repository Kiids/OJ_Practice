/*
附近的家居城促销，你买回了一直心仪的可调节书架，打算把自己的书都整理到新的书架上。
你把要摆放的书 books 都整理好，叠成一摞：从上往下，第 i 本书的厚度为 books[i][0]，高度为 books[i][1]。
按顺序 将这些书摆放到总宽度为 shelf_width 的书架上。
先选几本书放在书架上（它们的厚度之和小于等于书架的宽度 shelf_width），然后再建一层书架。重复这个过程，直到把所有的书都放在书架上。
需要注意的是，在上述过程的每个步骤中，摆放书的顺序与你整理好的顺序相同。 例如，如果这里有 5 本书，那么可能的一种摆放情况是：第一和第二本书放在第一层书架上，第三本书放在第二层书架上，第四和第五本书放在最后一层书架上。
每一层所摆放的书的最大高度就是这一层书架的层高，书架整体的高度为各层高之和。
以这种方式布置书架，返回书架整体可能的最小高度。
示例：
输入：books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
输出：6
解释：
3 层书架的高度和为 1 + 3 + 2 = 6 。
第 2 本书不必放在第一层书架上。
提示：
1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000
*/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size() + 1, INT_MAX);
        dp[books.size()] = 0;
        // 把第 j 本书拿到第 i 本书后面
        for (int i = books.size() - 1; i >= 0; i--)                              // 倒着处理书本，数组的最后一个在整个书架的最上面
        {
            int max_book_height = 0, left_width = shelfWidth;                    // 假设这一层高度为 0，当前层剩余的宽度为 leftWidth 
            for (int j = i; j < books.size() && left_width >= books[j][0]; j++)  // 根据处理到的书以及之前出现的，尝试把之前出现的书放到当前层，看看能不能达到最小值
            {
                max_book_height = max(max_book_height, books[j][1]);
                dp[i] = min(dp[i], max_book_height + dp[j + 1]);
                left_width -= books[j][0];
            }
        }
        return dp[0];
    }
};

//不断的把第 i 本书后面的书拿到和 i 本书同层的位置（如果这一层放的下的话），计算这种情况下 dpi 形成的高度
//记第 i 本书的高度为 hi，宽度为 wi，当第 i 本书排在书架某一层第一个位置的时候，
//第 i 本到最后一本书形成的最小高度为 dpi。递推公式为：
//dpi =min{max(hi)+dp[i+1],max(hi,h[i+1])+dp[i+2],...,max(hi ,...,hj)+dp[j+1]}
//s.t. 
//j
//∑wk  <=shelf_width
//k=i

