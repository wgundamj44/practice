// class Solution {
// public:
//   int maxProfit(vector<int>& prices) {
//     if (prices.size() <= 1) return 0;
//     int ret = 0;
//     vector<int> res1 = vector<int>(prices.size(), 0);
//     vector<int> res2 = vector<int>(prices.size(), 0);
//     int buyPrice, sellPrice;
//     int maxProf = 0;
//     for(int i = 0; i < prices.size(); i++) {
//       if (i == 0) buyPrice = prices[i];
//       else {
//         if (prices[i] > buyPrice) {
//           if (prices[i] - buyPrice > maxProf) {
//             maxProf = prices[i] - buyPrice;
//           }
//         } else if (prices[i] < buyPrice) {
//           buyPrice = prices[i];
//         }
//         res1[i] = maxProf;
//       }
//     }
//     maxProf = 0;
//     for(int i = prices.size() - 1; i >= 0; i--) {
//       if (i == prices.size() - 1) sellPrice = prices[i];
//       else {
//         if (prices[i] < sellPrice) {
//           if (sellPrice - prices[i] > maxProf) {
//             maxProf = sellPrice - prices[i];
//           }
//         } else if (prices[i] > sellPrice) {
//           sellPrice = prices[i];
//         }
//       }
//       res2[i] = maxProf;
//     }
//     for(int i = 0; i < prices.size(); i++) {
//       if (res1[i] + res2[i] > ret) ret = res1[i] + res2[i];
//     }
//     return ret;
//   }
// };

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int buy1, sell1, buy2, sell2;
    for(int i = 0; i < prices.size(); i++) {
      if (i == 0) {
        buy1 = - 1 * prices[i];
        sell1 = buy2 = sell2 = buy1;
      } else {
        buy1 = max(-1 * prices[i], buy1);
        buy2 = max(sell1 - prices[i], buy2);
        sell1 = max(buy1 + prices[i], sell1);
        sell2 = max(buy2 + prices[i], sell2);
      }
    }
    return max(0, max(sell1, sell2));
  }
};
