class Solution {

    record RowCol(int row, int col, int numMins){
    }

    public int orangesRotting(int[][] grid) {
        int time = 0;

        // find rotten fruits
        int freshFruit = 0;
        Queue<RowCol> queue = new LinkedList<RowCol>();
        for (int r = 0; r < grid.length; r++){
            for (int c = 0; c < grid[0].length; c++){
                // rotten
                if (grid[r][c] == 2){
                    queue.add(new RowCol(r, c, 0));
                } else if (grid[r][c] == 1){
                   freshFruit += 1;
                }

            }
        }

        boolean[][] visited = new boolean[grid.length][grid[0].length];

        int directionCount = 0;
        var cur = queue.peek();
        while (!queue.isEmpty()){
            cur = queue.poll();
            var r = cur.row;
            var c = cur.col;

            if (r < 0 || r >= grid.length ||
                c < 0 || c >= grid[0].length){
                    continue;
                }

            if (grid[r][c] == 0 || visited[r][c]){
                continue;
            }

            // make rotten
            if (grid[r][c] == 1){
                freshFruit -= 1;
                grid[r][c] = '2';
            }
            visited[r][c] = true;

            // add neighbours
            queue.add(new RowCol(r - 1, c, cur.numMins + 1));
            queue.add(new RowCol(r + 1, c, cur.numMins + 1));
            queue.add(new RowCol(r, c - 1, cur.numMins + 1));
            queue.add(new RowCol(r, c + 1, cur.numMins + 1));
        }

        if (freshFruit > 0){
            return -1;
        }

        if (cur == null){
            return 0;
        }
        
        return cur.numMins - 1;
    }
}
