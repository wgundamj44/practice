class Solution {
public:
  //check
  vector<int> diffWaysToCompute(string input) {
    vector<string> parts = parse(input);
    vector<int> res;
    return eval(parts, 0, parts.size() - 1);
  }


  vector<int> eval(vector<string>& parts, int i, int j) {
    vector<int> res;
    if (i == j) {
      res.push_back(stoi(parts[i]));
    } else {
      for(int k = i; k <= j; k++) {
        if (parts[k] == "*" || parts[k] == "+" || parts[k] == "-") {
          for(int v1: eval(parts, i, k - 1)) {
            for(int v2: eval(parts, k + 1, j)) {
              int v;
              if (parts[k] == "*") {
                res.push_back(v1 * v2);
              } else if (parts[k] == "+") {
                res.push_back(v1 + v2);
              } else if (parts[k] == "-") {
                res.push_back(v1 - v2);
              }
            }
          }
        }
      }
    }
    return res;
  }

  vector<string> parse(string input) {
    vector<string> parts;
    for(int i = 0; i < input.size(); i++) {
      int j = i;
      if (input[i] >= '0' && input[i] <= '9') {
        for(; j < input.size(); j++) {
          if (input[j] >= '0' && input[j] <='9') {
            continue;
          } else {
            break;
          }
        }
        parts.push_back(input.substr(i, j - i));
        i = j - 1;
      } else {
        parts.push_back(input.substr(i, 1));
      }
    }
    return parts;
  }
};
