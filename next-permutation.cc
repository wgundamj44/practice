class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        int j = i - 1;
        //find the ascending part
        while(j >= 0 && num[j] >= num[i]) {
            j--;
            i--;
        }
        
        // this k should be next value swap into
        int k = j;
        j = j + 1;
        i = num.size() - 1;
        // reverse to descending order
        while(i > j) {
            swap(num[i], num[j]);
            i--;
            j++;
        }
        if (k < 0) return;
        // find the first element larger than 
        for(i = k + 1; i < num.size(); i++) {
            if (num[i] > num[k]) {
                swap(num[i], num[k]);
                break;
            }
        }
    }
};