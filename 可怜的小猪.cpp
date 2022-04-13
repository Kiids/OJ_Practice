/*
有 buckets 桶液体，其中 正好有一桶 含有毒药，其余装的都是水。它们从外观看起来都一样。为了弄清楚哪只水桶含有毒药，你可以喂一些猪喝，通过观察猪是否会死进行判断。不幸的是，你只有 minutesToTest 分钟时间来确定哪桶液体是有毒的。
喂猪的规则如下：
选择若干活猪进行喂养
可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。
小猪喝完水后，必须有 minutesToDie 分钟的冷却时间。在这段时间里，你只能观察，而不允许继续喂猪。
过了 minutesToDie 分钟后，所有喝到毒药的猪都会死去，其他所有猪都会活下来。
重复这一过程，直到时间用完。
给你桶的数目 buckets ，minutesToDie 和 minutesToTest ，返回 在规定时间内判断哪个桶有毒所需的 最小 猪数 。
示例 1：
输入：buckets = 1000, minutesToDie = 15, minutesToTest = 60
输出：5
示例 2：
输入：buckets = 4, minutesToDie = 15, minutesToTest = 15
输出：2
示例 3：
输入：buckets = 4, minutesToDie = 15, minutesToTest = 30
输出：2
提示：
1 <= buckets <= 1000
1 <= minutesToDie <= minutesToTest <= 100
*/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(base));
    }
};

//数字进制表示
//最简单的情况，buckets = 1000, minutesToDie = 15, minutesToTest = 15，此时每只小猪都只能喝1次液体，
//每个小猪喝完若干瓶液体后只能出现两种状态，要么死亡，要么存活.
//1000 瓶液体分别标上一个唯一编号 0-999，每瓶对应唯一长度为10的二进制. 需要10只小猪，每个小猪负责一个二进制位即可
//一般的情况，buckets = 1000, minutesToDie = 15, minutesToTest = 60，此时每只小猪可以喝4次液体，
//在时间限制范围内，小猪可能出现的状态共有5种，分别为：喝完第1次后死亡、喝完第2次后死亡、喝完第3次后死亡、
//喝完第4次后死亡、喝完4次后依然存活. 每只小猪表示5种状态，将瓶子的编号转换成五进制数考虑.
//1000 瓶液体分别标上一个唯一编号 0-999，每瓶液体对应唯一长度为5的五进制串. 只需要5只小猪，每个小猪负责一个五进制位. 
//例第一只小猪负责五进制串的最低位，那么它第一次先喝掉五进制最低位为1的液体，
//第二次喝掉五进制最低位为2的液体，第三次喝掉五进制最低位为3的液体，第四次喝掉五进制最低位为4的液体. 
//这一过程中，如果这只小猪某次喝完后死亡，可以立马确定有毒液体五进制的最低位取值，如果喝完四次后仍存活，
//说明有毒液体五进制的最低位为0. 一只小猪确定一个五进制位的取值，使用5只小猪就能完全确定有毒液体的编号.
//抽象成更一般的数学公式：
//base=|minutesToDie/minutesToTest|+1
//base^ans>=buckets
//base 表示对应几进制数，将第二个式子左右两端同时取对数，即可得到答案：
//ans>=log{base}buckets=log{2}base/log{2}buckets
