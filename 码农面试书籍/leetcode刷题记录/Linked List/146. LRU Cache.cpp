class LRUCache {
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k,int v):key(k),value(v){}
    };

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }

    int get(int key) {
        if(cacheMap.find(key)==cacheMap.end()) return -1;
        //把当前访问的节点移到链表的头部，并且更新map中该节点的地址
        cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
        cacheMap[key]=cacheList.begin();
        return cacheMap[key]->value;
    }

    void put(int key, int value) {
        if(cacheMap.find(key)==cacheMap.end()){
            if(cacheMap.size()==capacity){
                //删除链表尾部节点（最少访问的j节点）
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            //插入新节点到链表头部，并且在map中增加该节点
            cacheList.push_front(CacheNode(key,value));
            cacheMap[key]=cacheList.begin();
        }else{
            //更新节点的值，把当前访问的节点移动到链表的头部，并且更新map中该节点的地址
            cacheMap[key]->value=value;
            cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
            cacheMap[key]=cacheList.begin();
        }
    }

private:
    list<CacheNode> cacheList;
    unordered_map<int,list<CacheNode>::iterator> cacheMap;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
