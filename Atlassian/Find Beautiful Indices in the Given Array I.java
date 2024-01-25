class Solution {
    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i <= s.length() - a.length(); ++i) {
            if (s.substring(i, i + a.length()).equals(a)) {
                for (int j = Math.max(0, i - k); j < Math.min(s.length() - b.length() + 1, i + k + 1); ++j) {
                    if (s.substring(j, j + b.length()).equals(b)) {
                        res.add(i);
                        break;
                    }
                }
            }
        }

        return res;
    }
}