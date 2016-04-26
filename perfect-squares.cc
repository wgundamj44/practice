class Solution {
public:
  int numSquares(int n) {
    vector<int> sol(n + 1, n);
    for(int i = 1; i <= (int)sqrt(n); i++) {
      sol[i * i] = 1;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= (int)sqrt(n); j++) {
        if (n - j * j >= i) {
          sol[j * j + i] = min(1 + sol[i], sol[j * j + i]);
        }
      }
    }
    return sol[n];
  }
};
