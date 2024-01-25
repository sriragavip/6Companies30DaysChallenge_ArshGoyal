class Solution {
    public int countCollisions(String directions) {
        Stack<Character> stack = new Stack<>();
        int collisions = 0;

        for (char direction : directions.toCharArray()) {
            if (!stack.isEmpty() && direction == 'L' && stack.peek() != 'L') {
                int prev = stack.pop();
                collisions++;
                if (prev == 'R')
                    collisions++;
                while (!stack.isEmpty() && stack.peek() == 'R') {
                    collisions++;
                    stack.pop();
                }
                stack.push('S');
            } else if (!stack.isEmpty() && direction == 'S' && stack.peek() == 'R') {
                while (!stack.isEmpty() && stack.peek() == 'R') {
                    collisions++;
                    stack.pop();
                }
                stack.push('S');
            } else {
                stack.push(direction);
            }
        }
        return collisions;
    }
}