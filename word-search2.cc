class TrieNode {
public:
  TrieNode* children[26];
  bool leaf;
  // Initialize your data structure here.
  TrieNode() {
    leaf = false;
    //children = new TrieNode*[26];
    memset(children, 0, sizeof(children));
  }
};

class Trie {
public:
  //check: trie
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string word) {
    doInsert(word, 0, root);
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    return doSearch(word, 0, root, true);
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    return doSearch(prefix, 0, root, false);
  }

private:
  TrieNode* root;

  void doInsert(string word, int i, TrieNode* p) {
    while(true) {
      if (i == word.length()) {
        p->leaf = true;
        return;
      }
      if (p->children[word[i] - 'a'] != nullptr) {
        p = p->children[word[i] - 'a'];
        i += 1;
      } else {
        auto q = new TrieNode();
        p->children[word[i] - 'a'] = q;
        i += 1;
        p = q;
      }
    }
  }

  bool doSearch(string word, int i, TrieNode* p, bool final) {
    while(true) {
      if (i == word.length()) {
        if (final) {
          return p->leaf;
        } else {
          return true;
        }
      }
      if (p->children[word[i] - 'a'] == nullptr) return false;
      p = p->children[word[i] - 'a'];
      i += 1;
    }
  }
};

class Solution {
public:
  //check: use trie
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    set<string> res;
    for(auto w: words) trie.insert(w);
    int h = board.size();
    if (h == 0)  return vector<string>();
    int w = board[0].size();
    vector<vector<bool>> visit(h, vector<bool>(w, false));

    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        DFS(board, "", visit, i, j, h, w, trie, res);
      }
    }

    return vector<string>(res.begin(), res.end());
  }

  void DFS(vector<vector<char>>& board, string path, vector<vector<bool>>& visit, int i, int j, int h, int w, Trie& trie, set<string>& res) {
    if (i <0 || i >= h || j < 0 || j >= w || visit[i][j]) return;
    string newPath = path + string(1, board[i][j]);
    if (!trie.startsWith(newPath)) {
      return;
    }
    if (trie.search(newPath)) {
      res.insert(newPath);
    }

    visit[i][j] = true;
    DFS(board, newPath, visit, i - 1, j, h, w, trie, res);
    DFS(board, newPath, visit, i + 1, j, h, w, trie, res);
    DFS(board, newPath, visit, i, j - 1, h, w, trie, res);
    DFS(board, newPath, visit, i, j+1, h, w, trie, res);
    visit[i][j] = false;
  }
};
