// 问题：求最长不含重复字符的子字符串，假设输入的字符串范围为'a'-'z'
// 思路：这种常规方法无法解决的，一般都是要用动态规划
// 动态规划法的具体思路：定义f(i)，表示以当前第i个字符结束，对应的不包含重复字符的子字符串的最大长度
// 显然f(0)=1，从f(1)开始，就需要分情况讨论了
// 1、如果第i个字符在之前都没有出现过，那么f(i)=f(i-1)+1
// 2、如果第i个字符出现过，找出出现的位置，该位置与i的距离记为d，此时又分为d<=f(i-1)和d>f(i-1)两种情况
// d<=f(i-1)，说明这第i个字符上次出现在f(i-1)对应的字符串中，此时f(i)=d
// d>f(i-1)，说明这第i个字符跟f(i-1)无关，故此时f(i)=f(i-1)+1
// 即使想通了这些，要是写代码还是会写出一个O(n2)的结果出来，因为每次都会涉及到从第i个字符往回找相同字符的过程
// 最后还是看作者的，太优雅了

// 方法1：蛮力法
bool hasDuplication(const std::string& str, int position[]){
    for(int i=0; i<26; i++)
        position[i] = -1;
    
    for(int i=0; i<str.length(); i++){
        int index = str[i] - 'a';
        if(position[index] >= 0)
            return true;
        
        position[index] += 1;
    }
    
    return false;
}

int longestSubstringWithoutDuplication_1(const std::string& str){
    int longest = 0;
    int* position = new int[26];
    for(int start=0; start<str.length(); start++){
        for(int end=start; end<str.length(); end++){
            int count = end - start + 1;
            const std::string& substring = str.substr(start, count);
            if(!hasDuplication(substring, position)){
                if(count > longest) longest = count;
            }
            else
                break;
        }
    }
    
    delete[] position;
    return longest;
}


// 方法2：优雅的动态规划法
int longestSubstringWithoutDuplication_2(const std::string& str){
    int curLength = 0;
    int maxLength = 0;

    int* position = new int[26];
    for(int i=0; i<26; i++)
        position[i] = -1;

    for(int i=0; i<str.length(); i++){
        int index = position[str[i] - 'a'];
        
        // index<0即前面没有出现过，i - index即d，curLength即f(i-1)
        if(index < 0 || i - index > curLength)
            curLength++;
        else{
            if(curLength > maxLength)
                maxLength = curLength;

            curLength = i - index;
        }

        position[str[i] - 'a'] = i;   // 每次都要更新当前字符的位置
    }

    if(curLength > maxLength)
        maxLength = curLength;

    delete[] position;
    return maxLength;
}

