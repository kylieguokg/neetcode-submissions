class Solution {
    public int maxAreaOfIsland(int[][] grid) {

        var maxArea = 0;
        for (int r = 0; r < grid.length; r++){
            for (int c = 0; c < grid[0].length; c++){
                maxArea = Math.max(getIslandSize(grid, r, c), maxArea);
            }
        }
        return maxArea;
    }

    public static int getIslandSize(int[][] grid, int r, int c){
        var rowInbounds = r >= 0 && r < grid.length;
        var colInbounds = c >= 0 && c < grid[0].length;
        if (!rowInbounds || !colInbounds){
            return 0;
        }

        if (grid[r][c] == 0){
            return 0;
        }

        int size = 1;
        // mark cur position as seen now
        grid[r][c] = 0;

        size += getIslandSize(grid, r - 1, c);
        size += getIslandSize(grid, r + 1, c);
        size += getIslandSize(grid, r, c - 1);
        size += getIslandSize(grid, r, c + 1);
        return size;
    }
}
