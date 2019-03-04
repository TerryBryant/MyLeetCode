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
