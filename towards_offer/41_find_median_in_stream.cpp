// 问题：找到数据流的中位数，注意数据流，也就是元素的个数会增多
// 思路：此题分析对比了数组、链表、二叉树、堆的优缺点，值得深入思考
// 最终采用的是最大/小堆来实现，因为它的插入数据时间复杂度为O(logn)，查找中位数的时间复杂度为O(1)，相对所有方法最好
// 具体思路就是，维护一个最大堆和一个最小堆，两者元素数目差不超过1，也就是均分了所有元素，其中最大堆的所有元素都小于最小堆，那么中位数就在两个堆顶之间了
// 最大最小堆可以借助stl中的vector来实现


template<typename T> class DynamicArray{
public:
    void Insert(T num){
        if(((min.size() + max.size()) & 1)  == 0 ){     // 要分别在两个堆里面插入，确保两个堆的元素差别不超过1
            if(max.size() > 0 && num < max[0]){
                max.push_back(num);
                std::push_heap(max.begin(), max.end(), std::less<T>());

                num = max[0];
                std::pop_heap(max.begin(), max.end(), std::less<T>());
                max.pop_back();
            }

            // 此时的num比最大堆的堆顶还大，那么直接进入最小堆
            min.push_back(num);
            std::push_heap(min.begin(), min.end(), std::greater<T>());
        }
        else {
            if(min.size() > 0 && min[0] < num){
                min.push_back(num);
                std::push_heap(min.begin(), min.end(), std::greater<T>());

                num = min[0];
                std::pop_heap(min.begin(), min.end(), std::greater<T>());
                min.pop_back();
            }

            max.push_back(num);
            std::push_heap(max.begin(), max.end(), std::less<T>());
        }
    }

    T GetMedian(){
        auto size = min.size() + max.size();
        if(size == 0){
            cout<<"No numbers are available";
            return -1;
        }

        T median = 0;
        if((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0]) / 2;

        return median;
    }

private:
    vector<T> min;  // 最小堆
    vector<T> max;  // 最大堆
};
