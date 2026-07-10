class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int p : piles)
            hours += (p + k - 1) / k;   // ceil(p/k)

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int m = l + (r - l) / 2;

            if (canEat(piles, h, m))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};