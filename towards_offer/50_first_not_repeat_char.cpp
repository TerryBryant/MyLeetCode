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


// 更新，计算字符流中第一个只出现一次的字符
class CharStatistics{
public:
    CharStatistics() : index(0){
        for (int i = 0; i < 256; ++i) {
            occurrence[i] = -1;
        }
    }

    void Insert(char ch){
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        else if (occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++;
    }

    char FirstAppearingOnce(){
        char ch = '\0';
        int minIndex = std::numeric_limits<int>::max();
        for (int i = 0; i < 256; ++i) {
            if(occurrence[i] >= 0 && occurrence[i] < minIndex){
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }

        return ch;
    }

private:
    int occurrence[256];    // -1表示没发现，-2表示发现多次，>=0表示仅发现一次
    int index;
};
