//check
class MinStack {
  stack<int> stk;
  stack<int> min;
public:
  void push(int x) {
    stk.push(x);
    if (min.empty() || x <= min.top()) {
      min.push(x);
    }
  }

  void pop() {
    int i = stk.top();
    stk.pop();
    if (i == min.top()) {
      min.pop();
    }
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return min.top();
  }
};
