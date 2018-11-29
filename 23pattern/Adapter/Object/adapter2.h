//使用继承,类模式
class Deque  //双端队列，被适配类
{
public:
    void push_back(int x)
    {
        cout << "Deque push_back:" << x << endl;
    }
    void push_front(int x)
    {
        cout << "Deque push_front:" << x << endl;
    }
    void pop_back()
    {
        cout << "Deque pop_back" << endl;
    }
    void pop_front()
    {
        cout << "Deque pop_front" << endl;
    }
};

class Sequence  //顺序类，目标类
{
public:
    virtual void push(int x) = 0;
    virtual void pop() = 0;
};

class Stack:public Sequence, private Deque   //栈, 适配类
{
public:
    void push(int x)
    {
        push_back(x);
    }
    void pop()
    {
        pop_back();
    }
};

class Queue:public Sequence, private Deque  //队列，适配类
{
public:
    void push(int x)
    {
        push_back(x);
    }
    void pop()
    {
        pop_front();
    }
};
//END