class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = i;
        while(i < n) {
            if (A[i] != elem) {
                A[j++] = A[i];
            }
            i++;
        }
        
        return j;
    }
};