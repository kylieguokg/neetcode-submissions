class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> order;
    int k;
    vector<int> nums;

    void ensureKSize(){
        while (order.size() > k){
            order.pop();
        }
    }

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        for (int num : nums){
            order.push(num);
        }
        ensureKSize();
    }
    
    int add(int val) {
        nums.push_back(val);
        order.push(val);
        ensureKSize();
        return order.top();
    }
};
