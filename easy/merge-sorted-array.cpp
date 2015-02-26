class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *C = new int[m + n];
        int i = 0, j = 0, k = 0;
        while(true) {
            if (i >= m || j >= n) break;
            if (A[i] <= B[j]) {
                C[k++] = A[i++];
            } else {
                C[k++] = B[j++];
            }
        }
        if (i >= m) {
            while(j < n) {
                C[k++] = B[j++];
            }
        }
        if (j >= n) {
            while(i < m) {
                C[k++] = A[i++];
            }
        }
        memcpy(&A[0], &C[0], sizeof(int) * (m+n));
    }
};
