class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int solv[len1][len2];
        
        if (len1 == 0) return len2;
        if (len2 == 0) return len1;
        solv[0][0] = word1[0] == word2[0] ? 0 : 1;
        // if we already met the same char, then the new pair should be removed even they are the same
        for(int i = 1; i < len1; i++) {
            if (solv[i-1][0] == i && word1[i] == word2[0]) {
                solv[i][0] = solv[i-1][0];
            } else {
                solv[i][0] = solv[i-1][0] + 1;
            }
        }
        for(int i = 1; i < len2; i++) {
            if (solv[0][i-1] == i && word1[0] == word2[i]) {
                solv[0][i] = solv[0][i-1];
            } else {
                solv[0][i] = solv[0][i-1] + 1;
            }
        }
        
        for(int i = 1; i < len1; i++) {
            for(int j = 1; j < len2; j++) {
                if (word1[i] == word2[j]) {
                    solv[i][j] = solv[i-1][j-1];
                } else {
                    solv[i][j] = min({solv[i - 1][j], solv[i][j - 1], solv[i-1][j-1]}) + 1;
                }
            }     
        }
        
        return solv[len1-1][len2-1];
    }
};
