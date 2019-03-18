// 问题：给定一个数字，将它翻译成字符串，求一共多少种翻译方法。例如1225可以是1, 12, 22, 2等等
// 思路：翻译1225可以分解成两个子问题，1和225，以及12和25，然后继续下去，可以用递归来解决
// 但是递归会存在大量的重复子问题，此时可以采用自下而上的方法


int GetTranslationCount(const std::string& number){
    int length = number.length();
    int* counts = new int[length];
    int count = 0;

    for (int i = length - 1; i >= 0; i--) {
        count = 0;
        if(i < length - 1)
            count = counts[i+1];
        else
            count = 1;

        if(i < length - 1){
            int digit1 = number[i] - '\0';
            int digit2 = number[i+1] - '\0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25){
                if(i < length - 2)
                    count += counts[i+2];
                else
                    count += 1;
            }
        }

        counts[i] = count;
    }

    count = counts[0];
    delete[] counts;

    return count;
}



int GetTranslationCount(int number){
    if(number < 0) return 0;

    std::string str = std::to_string(number);
    return GetTranslationCount(str);
}
