class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        int k = 0;
        while(i < n) {
            int j = i;
            while(j < n && A[i] == A[j]) {
                j++;
            }
            A[k++] = A[i];
            i = j;
        }
        return k;
    }
};