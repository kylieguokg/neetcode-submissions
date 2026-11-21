class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxPile = 0;
        for (int pile : piles){
            maxPile = max(pile, maxPile);
        }
        int minSpeed = 1;
        int maxSpeed = maxPile;

        while (minSpeed <= maxSpeed){
            int speed = minSpeed + (maxSpeed - minSpeed)/2;

            long curH = 0;
            for (int pile : piles){
                curH += ceil((pile * 1.0)/speed);
            }

            if (curH <= h){
                // update min and max
                maxSpeed = speed - 1;
                
            } else {
                // go faster
                minSpeed = speed + 1;
            }

        }
        return minSpeed;
    }
};
