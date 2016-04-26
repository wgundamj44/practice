class Solution {
public:
  vector<string> dict_one = {
    "Zero", "One", "Two","Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
  };
  vector<string> dict_ten = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
  };
  vector<string> posts = { "", "Thousand", "Million", "Billion", "Trillion" };
  string numberToWords(int num) {
    if (num == 0) return dict_one[num];
    int post_index = 0;
    string postfix = posts[post_index];
    string res = "";
    while(num > 0) {
      int remain = num % 1000;
      string s = parse(remain);
      if (s == "") {
        res = s + res;
      } else {
        if (postfix == "") {
          res = s;
        } else {
          res = s + " " + postfix + (res == "" ? res : " " + res);
        }
      }
      num = num / 1000;
      postfix = posts[++post_index];
    }
    return res;
  }

  string parse(int v) {
    string res = "";
    if (v / 100 > 0) {
      res += (dict_one[v / 100] + " " + "Hundred");
    }
    v = v % 100;
    if (v <= 19) {
      if (v == 0) return res;
      res += (res == "" ? dict_one[v] : " " + dict_one[v]);
      return res;
    } else {
      int tens = v / 10;
      res += (res == "" ? dict_ten[tens] : " " + dict_ten[tens]);
      v = v % 10;
    }
    if (v != 0) {
      res += (" " + dict_one[v]);
      return res;
    } else {
      return res;
    }
  }
};
