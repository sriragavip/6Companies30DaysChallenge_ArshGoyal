class GfG {
    String encode(String str) {
        int l = 0;

        int r = 0;

        StringBuilder sb = new StringBuilder();

        while (r < str.length()) {

            l = r;

            while (r < str.length() && str.charAt(r) == str.charAt(l))
                r++;

            sb.append(str.charAt(l)).append(r - l);
        }
        return sb.toString();
    }

}