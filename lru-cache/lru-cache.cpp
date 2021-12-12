

    class node{
        public:
        int keyy;
        int value;
        node *next;
        node *prev;
        
        node(int _key,int _val)
        {
            keyy=_key;
            value=_val;
        }
    };
class LRUCache {
public:
    

    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    void addode(node *newnode)
    {
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    void deleten(node *dele)
    {
        node *nextt=dele->next;
        node *prevv=dele->prev;
        
        nextt->prev=prevv;
        prevv->next=nextt;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node *res=mp[key];
            int resu=res->value;
            mp.erase(key);
            deleten(res);
            addode(res);
            mp[key]=head->next;
            
            return resu;
            
        }
        else
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            node *exist=mp[key];
            mp.erase(key);
            deleten(exist);
            
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->keyy);
            deleten(tail->prev);
        }
        
        addode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */