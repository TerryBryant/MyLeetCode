// 问题1:翻转单词顺序，"I am a student"-->"student a am I"
// 思路：第一遍整体翻转，第二遍仅翻转单词
//

// 翻转整个句子
void Reverse(char* pBegin, char* pEnd){
    if(pBegin == nullptr || pEnd == nullptr) return;

    while(pBegin < pEnd){
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++;
        pEnd--;
    }
}


char* ReverseSentence(char* pData){
    if(pData == nullptr) return nullptr;

    char* pBegin = pData;
    char* pEnd = pData;
    while (*pEnd != '\0')
        pEnd++;
    pEnd--;

    Reverse(pBegin, pEnd);

    //翻转每个单词
    pBegin = pEnd = pData;
    while (*pBegin != '\0'){
        if(*pBegin == ' '){
            pBegin++;   // 两者一起进入下一个单词
            pEnd++;
        } else if(*pEnd == ' ' || *pEnd == '\0'){
            Reverse(pBegin, --pEnd);  // 走到了空格处，pEnd回退一步
            pBegin = ++pEnd;    // 单词翻转完之后，两者都走到空格处
        } else
            pEnd++; // 一开始pEnd向前走
    }

    return pData;
}


// 问题2：旋转字符串，"abcdefg"-->"cdefgab"，反正两个单词
// 思路："abcdefg"-->"bagfedc"-->"cdefgab"，即分两步进行翻转
// 一定要注意边界条件

char* LeftRotateString(char* pStr, int n){
    if(pStr != nullptr){
        int nLength = static_cast<int>(strlen(pStr));

        if(nLength > 0 && n > 0 && n < nLength){
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;

            // 翻转前n个字符
            Reverse(pFirstStart, pFirstEnd);
            // 翻转后面的字符
            Reverse(pSecondStart, pSecondEnd);
            // 整体翻转
            Reverse(pFirstStart, pSecondEnd);
        }
    }

    return pStr;
}

