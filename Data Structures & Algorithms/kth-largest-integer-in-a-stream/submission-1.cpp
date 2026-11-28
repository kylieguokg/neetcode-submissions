class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> order;
    int k;

    void ensureKSize(){
        while (order.size() > k){
            order.pop();
        }
    }

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums){
            order.push(num);
            ensureKSize();
        }
    }
    
    int add(int val) {
        order.push(val);
        ensureKSize();
        return order.top();
    }
};
