class Solution {

    record RowCol(int r, int c, int length){
    }

    public void islandsAndTreasure(int[][] grid) {

        // for each cell, find the nearest chest and record dist
        for (int r = 0; r < grid.length; r++){
            for (int c = 0; c < grid[0].length; c++){
                if (grid[r][c] > 0){
                    grid[r][c] = findDistance(grid, r, c);
                }
            }
        }
        
    }

    public int findDistance(int[][] grid, int row, int col){
        // BFS for shortest distance
        Queue<RowCol> queue = new LinkedList<RowCol>();
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        queue.add(new RowCol(row, col, 0));

        while (!queue.isEmpty()){
            var cur = queue.poll();

            var r = cur.r;
            var c = cur.c;
            if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length){
                continue;
            }

            if (grid[r][c] == -1){
                continue;
            }

            if (visited[r][c]){
                continue;
            }

            // found treasure
            if (grid[r][c] == 0){
                return cur.length;
            }
            visited[r][c] = true;

            queue.add(new RowCol(r - 1, c, cur.length + 1));
            queue.add(new RowCol(r + 1, c, cur.length + 1));
            queue.add(new RowCol(r, c - 1, cur.length + 1));
            queue.add(new RowCol(r, c + 1, cur.length + 1));
        }

        return grid[row][col];
    }
}
