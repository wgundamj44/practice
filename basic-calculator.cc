class Solution {
public:
  //check
  int calculate(string s) {
    stack<int> operands;
    stack<char> operators;
    for(int i = s.length() - 1;i >= 0;i--) {
      if (s[i] == '+' || s[i] == '-' || s[i] == ')') {
        operators.push(s[i]);
      } else if (s[i] >= '0' && s[i] <= '9') {
        int j = i;
        while(j >= 0 && (s[j] >= '0' && s[j] <= '9')) {
          j--;
        }
        operands.push(stoi(s.substr(j + 1, i - j)));
        i = j+1;
        cout << operands.top() << endl;
      } else if (s[i] == '(') {
        while(operators.top() != ')') {
          calc(operands, operators);
        }
        operators.pop();
      }
    }
    while(operands.size() != 1) {
      calc(operands, operators);
    }
    return operands.top();
  }

  void calc(stack<int>& operands, stack<char>& operators) {
    int op1 = operands.top();
    operands.pop();
    int op2 = operands.top();
    operands.pop();
    if (operators.top() == '+') operands.push(op1 + op2);
    else operands.push(op1 - op2);
    operators.pop();
  }

};
