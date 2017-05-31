class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(int i = 0; i < words.size(); i++) {
            int len = 0;
            int j;
            for(j = i; j < words.size(); j++) {
                len += words[j].length();
                if (len + (j-i) > maxWidth) {
                    break;
                }
            }
            string tmp = "";
            if (j == words.size()) {
                for(int k = i; k < j; k++) {
                    tmp += words[k];
                    if (k != j - 1) tmp += " ";
                    else tmp += string(maxWidth - tmp.size(), ' ');
                }
            } else {
                len -= words[j].length();
                int count = j - i;
                if (count == 1) {
                    tmp += words[j-1];
                    tmp += string(maxWidth - tmp.size(), ' ');
                } else {
                    int remain = (maxWidth - len) % (count - 1);
                    int space = (maxWidth - len) / (count - 1);
                    for(int k = i; k < j; k++) {
                        tmp += words[k];
                        if (remain) {
                            tmp += string(space + 1, ' ');
                            remain--;
                        } else {
                            if (k != j - 1) tmp += string(space , ' ');
                        }
                    }
                }
            }
            res.push_back(tmp);
            i = j - 1;
        }
        return res;
    }
};
