class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<>();
        if (digits.length() == 0)
            return res;
        HashMap<String, String> map = new HashMap<>();
        map.put("2", "abc");
        map.put("3", "def");
        map.put("4", "ghi");
        map.put("5", "jkl");
        map.put("6", "mno");
        map.put("7", "pqrs");
        map.put("8", "tuv");
        map.put("9", "wxyz");

        Deque<String> dq = new ArrayDeque();
        dq.add("");
        for (int i = 0; i < digits.length(); i++) {
            String d = digits.substring(i, i + 1);
            String fromMap = map.get(d);
            int n = dq.size();
            for (int j = 0; j < n; j++) {
                String pull = dq.pollFirst();
                for (int k = 0; k < fromMap.length(); k++) {
                    String temp = pull.concat(fromMap.charAt(k) + "");
                    dq.add(temp);
                }

            }

        }
        while (!dq.isEmpty()) {
            res.add(dq.poll());
        }
        return res;
    }
}