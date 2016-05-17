class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for(auto token: tokens) {
      if (token == "+" || token == "-" || token == "*" || token =="/") {
        auto op1 = stk.top();
        stk.pop();
        auto op2 = stk.top();
        stk.pop();
        if (token == "+") stk.push(op1 + op2);
        else if (token == "-") stk.push(op2 - op1);
        else if (token == "*") stk.push(op1 * op2);
        else stk.push((int)(op2 / op1));
      } else {
        stk.push(stoi(token));
      }
    }
    return stk.top();
  }
};
