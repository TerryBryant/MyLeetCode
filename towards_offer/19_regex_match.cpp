// 问题：正则匹配，'.'表示可以匹配任何字符，'*'表示前一个字符可以重复n次（包括0次）
// 思路：匹配肯定是逐个进行的，当字符串和正则一致，或者正则里面是'.'时，继续下一个匹配
// 当下一个字符为'*'时，有这么几种情况：1、下一个字符与pattern的后两个字符；2、下一个字符与当前字符；3、当前字符与pattern后两个字符


bool matchCore(char* str, char* pattern){
    if(*str == '\0' && *pattern == '\0') return true;

    if(*str != '\0' && *pattern == '\0') return false;

    if(*(pattern + 1) == '*'){
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
        else
            return matchCore(str, pattern + 2);
    }

    // 直接相等，或者pattern是'.'
    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}


bool match(char* str, char* pattern){
    if(str == nullptr || pattern == nullptr) return false;

    return matchCore(str, pattern);
}
