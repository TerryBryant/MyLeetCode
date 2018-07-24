// 问题：此题其实还是很有趣的，但是题目的描述太坑爹了，这里详细解释下
// 当输入为1时，输出为“1”，表示只有一个1
// 当输入为2时，它是基于前面一种情况的输出，由于前面的输出为1，这里的输出为“11”，表示1个1
// 当输入为3时，根据“11”，这里的输出为“21”，表示2个1
// 当输入为4时，根据“21”，输出为“1211”，表示1个2，1个1
// 当输入为5时，根据“1211”，输出为“111221”
// ...依此类推，当输出为n时，求输出的字符串

// 思路：此题类似于Fibonacci数列，后一个输出依赖前一个输入，可以用递归来处理
// 但是之前看过动态规划的bottom up算法，可以不用迭代来进行实现，下面给出相应的代码
//
//


// 代码：
string countAndSay(int n) {
    if (n == 1) return "1";

    vector<string> str(n, ""); // 从1到n得到的结果都会存放在这个vector中
    str[0] = "1";

    for (int i = 1; i<n; i++) {
        char begin = str[i - 1][0]; //起始字符，每次遇到新的字符，则更新为新的字符，注意这里的i-1，即当前的结果依赖上一次的结果
        string tmp = "";  // 用于存放每个结果string
        int cnt = 1;      // 用于计数，即一个数字重复了多少次

        for (int j = 1; j<str[i - 1].size(); j++) {
            if (str[i - 1][j] == begin) {
                cnt++;
            }
            else {
                tmp.append(to_string(cnt));
                tmp.append(string(1, begin));   // 将单个char转为string
                begin = str[i - 1][j];          // 出现了新的字符，begin更新
                cnt = 1;                        // 相应的cnt置为1
            }
        }

        tmp.append(to_string(cnt));    // 将最后一段接上来
        tmp.append(string(1, begin));

        str[i] = tmp;
    }

    return str[n-1];
}
