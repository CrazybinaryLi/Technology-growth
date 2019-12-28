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
        //�ѵ�ǰ���ʵĽڵ��Ƶ������ͷ�������Ҹ���map�иýڵ�ĵ�ַ
        cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
        cacheMap[key]=cacheList.begin();
        return cacheMap[key]->value;
    }

    void put(int key, int value) {
        if(cacheMap.find(key)==cacheMap.end()){
            if(cacheMap.size()==capacity){
                //ɾ������β���ڵ㣨���ٷ��ʵ�j�ڵ㣩
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            //�����½ڵ㵽����ͷ����������map�����Ӹýڵ�
            cacheList.push_front(CacheNode(key,value));
            cacheMap[key]=cacheList.begin();
        }else{
            //���½ڵ��ֵ���ѵ�ǰ���ʵĽڵ��ƶ��������ͷ�������Ҹ���map�иýڵ�ĵ�ַ
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
