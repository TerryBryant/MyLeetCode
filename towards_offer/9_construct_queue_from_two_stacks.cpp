// 问题：用两个堆栈实现一个队列
// 思路：此题思路较为简单，当数据进入一个堆栈，再从这个堆栈出来进入另一个堆栈，其实就是一个队列了
// 但是要注意，在删掉队列头的时候，要把第二个栈先删完，才能从第一个栈压入数据到第二个栈


template <typename T>class CQueue{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template <typename T> void CQueue<T>::appendTail(const T &node) {
    stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead() {
    if(stack2.size() <= 0){
        while (stack1.size() > 0){
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
        throw std::exception("queue is empty");

    T head = stack2.top();
    stack2.pop();
    return head;
}


// 拓展：用两个队列实现一个堆栈
// 思路：要实现出栈，先将数据压入第一个队列abc，a先入先出，把ab压入第二个队列（压的个数为队列的size减一），剩余c，c出栈及完成了后入先出
// 要注意的是，压入数据时应压入到一个非空的队列，否则顺序就乱了


template <typename T> class CStack{
public:
    CStack(void);
    ~CStack(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};

template <typename T>
void CStack<T>::appendTail(const T &node) {
    // 往不为空的队列里面插入数据
    if(!queue1.empty())
        queue1.push(node);
    else
        queue2.push(node);
}

template <typename T>
T CStack<T>::deleteHead() {
    T ret;
    if(!queue1.empty()){
        int num = queue1.size();
        while (num > 1){
            queue2.push(queue1.front())
            queue1.pop();
            num--;
        }

        ret = queue1.front();
        queue1.pop();
    } else{
        int num = queue2.size();
        while (num > 1){
            queue1.push(queue2.front())
            queue2.pop();
            num--;
        }

        ret = queue2.front();
        queue1.pop();
    }

    return ret;
}
