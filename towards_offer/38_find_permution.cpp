// 问题：给出一个字符串，打印出每个字符所能排列出来的所有组合，例如输入abc，能得到abc，acb，bca等等
// 思路：此题从数学上看是排列组合问题，但是这里求的是具体的组合，而不是总数目。
// 应该将字符串分成两组，第一组只有一个字符，第二组为剩下字符，拿第一个字符和它后面的字符逐个交换，得到第一组字符所有的可能。然后求第二组
// 又分成两个组，依次递归下去


void PermutionCore(char* pStr, char* pBegin){
    if(*pBegin == '\0'){
        cout << pStr << endl;
    } else {
        for(char* pCh = pBegin; *pCh != '\0'; pCh++){
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            PermutionCore(pStr, pBegin + 1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}


void Permutation(char* pStr){
    if(pStr == nullptr) return;

    PermutionCore(pStr, pStr);
}
