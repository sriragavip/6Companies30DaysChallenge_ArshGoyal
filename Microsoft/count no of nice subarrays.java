class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        return countOddSlidingWindow(nums, k) - countOddSlidingWindow(nums, k - 1);
    }

    static int countOddSlidingWindow(int[] arr, int k) {
        int n = arr.length;
        int si = 0;
        int sum = 0;
        int count = 0;
        for (int cur = 0; cur < n; cur++) {
            if (arr[cur] % 2 != 0)
                sum++;
            if (sum <= k)
                count += cur - si + 1;
            while (si <= cur && sum > k) {
                if (arr[si] % 2 != 0) {
                    sum--;
                }
                si++;
                if (sum <= k)
                    count += cur - si + 1;
            }
        }
        return count;
    }
}