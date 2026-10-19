class CustomStack {
public:
    vector<int>ans;
    int ptr;
    CustomStack(int maxSize) {
        ans.assign(maxSize , 0); 
        ptr = 0;
    }
    
    void push(int x) {
        if(ptr < ans.size()) {
            ans[ptr] = x;
            ptr++;
        }
    }
    
    int pop() {
        if(ptr == 0) return -1;
        ptr--;
        return ans[ptr];
    }
    
    void increment(int k, int val) {
        k = min(k , ptr);
        for(int i = 0 ; i < k ; i++) ans[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */