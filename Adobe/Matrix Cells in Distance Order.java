class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] result = new int[R * C][];
        result[0] = new int[] { r0, c0 }; // Add start point r0,c0 which has distance 0.
        int resultIdx = 1;
        int lim = Math.max(r0, R - r0 - 1) + Math.max(c0, C - c0 - 1);
        // lim is highest distance value.
        for (int dist = 1; dist <= lim; dist++) { // Process 'lim' diamond-shapes having distance 'dist'.
            int r = r0 - dist;
            int c = c0;
            // Diamond side: Top Left
            for (int count = dist; count > 0; count--) {
                if (r >= 0 && c >= 0)
                    result[resultIdx++] = new int[] { r, c };
                r++;
                c--;
            }

            // Diamond side: Left Bottom
            for (int count = dist; count > 0; count--) {
                if (r < R && c >= 0)
                    result[resultIdx++] = new int[] { r, c };
                r++;
                c++;
            }

            // Diamond side: Bottom Right
            for (int count = dist; count > 0; count--) {
                if (r < R && c < C)
                    result[resultIdx++] = new int[] { r, c };
                r--;
                c++;
            }

            // Diamond side: Right Top
            for (int count = dist; count > 0; count--) {
                if (r >= 0 && c < C)
                    result[resultIdx++] = new int[] { r, c };
                r--;
                c--;
            }
        }
        return result;
    }
}