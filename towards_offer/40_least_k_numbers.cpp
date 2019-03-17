// 问题：求数组的最小k个数
// 思路：维护一个含有k个元素的最大堆，然后继续遍历数组，比最大堆的堆顶大，那么删掉堆顶，插入该数
// 要具备现场建堆的能力，如果不行，就借助stl中的set/multiset来实现，因为这两种结构都是基于红黑树的
// 注意这里可能设计到频繁的删除和插入，所以用红黑树比AVL树性能更好


typedef std::multiset<int, std::greater<int> > intset;

void GetLeastNumbers(const vector<int>& data, intset& leastNumbers, int k){
    leastNumbers.clear();

    if(k < 1 || data.size() < k)
        return;

    for (auto iter = data.begin(); iter != data.end(); ++iter) {
        if(leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else{
            auto iterGreatest = leastNumbers.begin();

            if(*iter < *(leastNumbers.begin())){
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}
