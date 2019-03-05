// 问题：寻找第一个只出现一次的字符
// 思路：涉及到有限个字符的情况，一般都可以借助哈希表来解决，使得算法复杂度为O(n)
// 此题用一个长度为256的数组即可装下所有字符，然后遍历数组，第一个值为1的字符即为所求

char FirstNotRepeatingChar(char* pString){
    if(pString == nullptr) return '\0';

    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i=0; i<tableSize; i++) hashTable[i] = 0;

    char* pHashkey = pString;
    while (*(pHashkey) != '\0')
        hashTable[*(pHashkey++)]++;

    pHashkey = pString;
    while (*pHashkey != '\0') {
        if(hashTable[*pHashkey] == 1) return *pHashkey;
        pHashkey++;
    }

    return '\0';
}
