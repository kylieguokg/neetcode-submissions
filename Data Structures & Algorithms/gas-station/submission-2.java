class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {

        // total 
        int totalCost = 0;
        int totalGas = 0; 
        for (int g : gas){
            totalGas += g;
        }

        for (int c : cost){
            totalCost += c;
        }

        if (totalCost > totalGas){
            return -1;
        }

        int startingPoint = 0;
        int curGas = 0;
        for (int i = 0; i < gas.length; i++){
            curGas += (gas[i] - cost[i]);
            System.out.println("i " + i + "curGas" + curGas + "start" + startingPoint);

            if (curGas < 0){
                // move starting point
                curGas = 0;
                startingPoint = i + 1;
            }
            
        }

        return startingPoint;
        
    }
}
