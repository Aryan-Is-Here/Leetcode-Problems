class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    unordered_map<int , int> mp;
    vector<int> arr;
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            arr[mp[val]] = arr[arr.size() - 1];
            mp[arr[arr.size() - 1]] = mp[val];
            mp.erase(val);
            arr.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */