class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        
        int j = 1;
        int last = 0, pre = A[last];
        while(j != n) {
            if(A[j] != pre) {
                pre = A[j];
                last++;
                A[last] = A[j];
                j++;
            } else {
                j++;
            }
        }
        
        return last + 1;
    }
};
