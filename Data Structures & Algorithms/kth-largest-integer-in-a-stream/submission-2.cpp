class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> order;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        order.push(val);
        if (order.size() > k){
            order.pop();
        }
        return order.top();
    }
};
