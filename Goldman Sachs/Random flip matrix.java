class Solution {
    int i = 0, j = 0;
    int m = 0;
    int n = 0;

    public Solution(int m, int n) {
        this.m = m;
        this.n = n;
    }

    public int[] flip() {
        j++;
        if (j == n) {
            j = 0;
            i++;
        }
        if (i == m) {
            i = 0;
            j = 0;
        }

        return new int[] { i, j };

    }

    public void reset() {

    }
}