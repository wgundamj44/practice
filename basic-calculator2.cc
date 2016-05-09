class Solution {
public:
  //check
  int calculate(string s) {
    stack<int> operands;
    stack<char> operators;
    for(int i = s.length() - 1; i >= 0; i--) {
      if (s[i] >= '0' && s[i] <= '9') {
        int j = i;
        for(; j >= 0; j--) {
          if (!(s[j] >= '0' && s[j] <= '9')) break;
        }
        int num = stoi(s.substr(j + 1, i - j));
        operands.push(num);
        i = j + 1;
      } else if (s[i] == '+' || s[i] == '-') {
        while(!operators.empty() && (operators.top() != '+' && operators.top() != '-')) {
          operands.push(calc(operands, operators));
        }
        operators.push(s[i]);
      } else if (s[i] == '*' || s[i] == '/') {
        operators.push(s[i]);
      }
    }
    while(!operators.empty()) {
      operands.push(calc(operands, operators));
    }
    return operands.top();
  }
  int calc(stack<int>& operands, stack<char>& operators) {
    char op = operators.top();
    operators.pop();
    int v1 = operands.top();
    operands.pop();
    int v2 = operands.top();
    operands.pop();
    if (op == '+') return v1 + v2;
    else if (op == '-') return v1 - v2;
    else if (op == '*') return v1 * v2;
    else if (op == '/') return v1 / v2;
  }
};
