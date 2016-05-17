#include "TreeNode.h"
#include<list>
using namespace std;

class LRUCache{
  int _capacity;
  list<pair<int, int>> data;
  map<int, list<pair<int, int>>::iterator> m;
public:
  LRUCache(int capacity) {
    _capacity = capacity;
  }

  int get(int key) {
    if (m.find(key) == m.end()) {
      return -1;
    } else {
      auto it = m[key];
      int val = it->second;
      data.erase(it);
      data.push_front({key, it->second});
      m[key] = data.begin();
      return val;
    }
  }

  void set(int key, int value) {
    if (m.find(key) != m.end()) {
      auto it = m[key];
      data.erase(it);
    } else if (data.size() == _capacity) {
      auto p = data.back();
      m.erase(p.first);
      data.pop_back();
    }
    data.push_front({key, value});
    m[key] = data.begin();
  }
};

int main() {
  LRUCache c(2);
  c.set(2, 1);
  c.set(1, 1);
  c.set(2, 3);
  c.set(4, 1);
  cout << c.get(1) << endl;
  cout << c.get(2) << endl;
}
