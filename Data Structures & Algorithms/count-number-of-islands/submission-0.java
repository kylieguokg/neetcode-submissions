class Solution {
    public int numIslands(char[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int count = 0;

        for (int row = 0; row < grid.length; row++){
            for (int col = 0; col < grid[0].length; col++){
                if (visited[row][col]){
                    continue;
                }
                if (grid[row][col] == '0'){
                    continue;
                }
                exploreIsland(grid, row, col, visited);
                count += 1;
            }
        }
        return count;
    }

    public void exploreIsland(char[][] grid, int startRow, int startCol, boolean[][] visited){
        if (visited[startRow][startCol] ||
            grid[startRow][startCol] == '0'){
            return;
        }
        visited[startRow][startCol] = true;

        // explore in all directions
        if (startRow - 1 >= 0){
            exploreIsland(grid, startRow - 1, startCol, visited);
        }

        if (startRow + 1 < grid.length){
            exploreIsland(grid, startRow + 1, startCol, visited);
        }

        if (startCol - 1 >= 0){
            exploreIsland(grid, startRow, startCol - 1, visited);
        }

        if (startCol + 1 < grid[0].length){
            exploreIsland(grid, startRow, startCol + 1, visited);
        }


    }
}
