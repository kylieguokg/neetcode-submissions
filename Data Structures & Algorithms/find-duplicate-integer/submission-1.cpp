class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // find cycle entry point
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
            // cout << slow << fast << "\n";
        } while (slow != fast);

        // find duplicate
        int slow2 = 0;
        while (slow != slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
            // cout << slow << slow2 << "\n";
        }

        return slow;
    }
};

/**
[1, 2, 3, 2, 2]
s = 0
f = 0

s = 1
f = 1, f = 2

s = 2 
f = 3, f = 2

== 
s = 2
s2 = 0

s = 3
s2 = 1

s = 2
s2 = 2

**/