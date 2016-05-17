class Solution {
public:
  //check
  string fractionToDecimal(int numerator, int denominator) {
    long num = numerator, deno = denominator;
    bool minus = false;
    if ((num < 0 && deno > 0) || (num > 0 && deno <0)) {
      minus = true;
      num = abs(num);
      deno = abs(deno);
    }
    string integer = (minus ? "-" : "") + to_string((long)(num / deno));
    if (num % deno == 0) return integer;
    long remain = num % deno;
    string decimal = "";
    map<int, int> loop;
    int i = 0;
    loop[remain] = i;
    i++;
    while(true) {
      remain *= 10;
      if (remain % deno == 0) {
        decimal += to_string((long)(remain / deno));
        return integer + "." + decimal;
      }else {
        string r = to_string((long)(remain / deno));
        remain = remain % deno;
        decimal += r;
        if (loop.find(remain) != loop.end()) {
          int j = loop[remain];
          decimal = decimal.substr(0, j) + "(" + decimal.substr(j) + ")";
          return integer + "." + decimal;
        }
        loop[remain] = i;
        i++;
      }
    }
  }
};
