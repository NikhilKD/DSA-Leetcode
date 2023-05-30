class MyHashSet {
public:
    int n=1e6;
    vector<int> v;
    MyHashSet() {
        for(int i=0;i<n;i++){
            v.push_back(0);
        }
    }
    
    void add(int key) {
        v[key]=1;
    }
    
    void remove(int key) {
        v[key]=0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */