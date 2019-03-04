// 问题：定义一个栈的数据结构，该结构包含一个能得到栈最小元素的函数
// 思路：关键是定义一个与数据栈大小一致的辅助栈，里面存放最小值，当新来一个元素时，如果元素更大，则辅助栈只会压入自己的最小值
// 套路千千万，又能记得多少种。。

template <typename T>class StackWithMin{
public:
    StackWithMin(void);
    ~StackWithMin(void);

    T push(const T& value);
    void pop();
    const T& min() const;

private:
    std::stack<T> m_data;   // 数据栈
    std::stack<T> m_min;    // 辅助栈
};

template <typename T>
void StackWithMin<T>::push(const T& value){
    m_data.push(value);

    if(m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop() {
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}

template <typename T>
const StackWithMin<T>::min() const{
    assert(m_data.size() > 0 && m_min.size() > 0);
    return m_min.top();
}
