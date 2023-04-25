/* 
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours. 
*/

class Solution {
public:

    //helper function to see if Koko can eat all banans at a given speed
    bool canEatAll(vector<int>& piles, int speed, int h) {
        int time = 0;
        for (int i = 0; i < piles.size() && time <= h; i++) 
            time += (piles[i]-1) / speed + 1;
        return time <= h;
    }

    //Find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid,
            right = *max_element(piles.begin(), piles.end()), //max speed
            left = max(1, right/h); //min speed
            

        //Binary search to find the min speed
        while (left < right) {
            mid = (left + right) / 2;
            if (canEatAll(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
