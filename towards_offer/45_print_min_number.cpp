// 问题：给定一个数组，求出该数组每个数字拼接起来得到的最小值，例如{13, 45, 21}得到的最小值为132145
// 思路：分析题目即可得出，只要将数组按从小到大进行排序，即可得到所求结果，但是要注意拼接可能造成数字太大，超出int范围
//


void PrintMinNumber(const vector<int>& numbers){
    auto length = numbers.size();
    if(length <= 0) return;

    vector<std::string> strings(length, "");
    for(int i=0; i<length; i++){
        strings[i] = std::to_string(numbers[i]);
    }

    std::sort(strings.begin(), strings.end(), std::less<std::string>());

    for(auto str: strings) cout << str;
    cout << endl;
}
