#include <stack>

using std::stack;

class MinStack
{
  public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (data.empty())
            data.push((Node){.value_ = val, .min_ = val});
        else
        {
            if (val <= data.top().min_)
                data.push((Node){.value_ = val, .min_ = val});
            else
                data.push((Node){.value_ = val, .min_ = data.top().min_});
        }
    }

    void pop()
    {
        data.pop();
    }

    int top()
    {
        if (!data.empty())
            return data.top().value_;
        else
            return 0;
    }

    int getMin()
    {
        if (!data.empty())
            return data.top().min_;
        else
            return 0;
    }

  private:
    struct Node
    {
        int value_;
        int min_;
    };
    stack<Node> data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack obj;

    int val = 3;
    obj.push(val);
    obj.pop();
    int param_3 = obj.top();
    int param_4 = obj.getMin();
}
