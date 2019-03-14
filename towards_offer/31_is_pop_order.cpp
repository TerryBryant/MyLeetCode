// 问题：给定一个栈的入栈顺序，判断某个出栈的序列是不是来自该栈
// 思路：自己很容易就想明白是怎么回事了，但是无法用代码或者数学表达式来写出，真是没救了
//


bool IsPopOrder(const int* pPush, const int* pPop, int nLength){
    bool bPossible = false;

    if(pPush != nullptr && pPop != nullptr && nLength > 0){
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        std::stack<int> stackData;

        while (pNextPop - pPop < nLength){
            // 当辅助栈的栈顶元素不是要弹出的元素时，先压入一些元素
            while (stackData.empty() || stackData.top() != *pNextPop) {
                // 如果所有数字都入辅助栈了，则退出循环
                if(pNextPush - pPush == nLength) break;

                stackData.push(*pNextPush);
                pNextPush++;
            }

            if(stackData.top() != *pNextPop) break;

            stackData.pop();
            pNextPop++;
        }

        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }

    return bPossible;
}
