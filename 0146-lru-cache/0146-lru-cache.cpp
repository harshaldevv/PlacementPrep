class LRUCache {
public:
    int sz;
    //hashmap
    //double linked list
    map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> l;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            // not found
            return -1;
        }
        else{
            // found
            auto address = mp[key];
            int ans = mp[key]->second;
            l.splice(l.begin(), l, mp[key]);
            return ans;
        }   
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            // mil gyi
            auto address = mp[key];
            mp[key]->second = value; 
            l.splice(l.begin(), l, mp[key]);
        }
        else{
            if(mp.size() < sz){
                // we have space.. seedha aage laga do
                l.push_front({key, value});
                mp[key] = l.begin();
            }
            else{
                // no space left .. peeche se nikal ke .. phir naye key,value ko daalo
                auto lastKey = l.back().first;
                l.pop_back();
                mp.erase(lastKey);
                
                l.push_front({key, value});
                mp[key] = l.begin();
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */