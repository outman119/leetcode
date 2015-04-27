typedef struct node{
    int key;
    int val;
    struct node* next;
    struct node* prev;
}node_t;
class LRUCache{
public:
    int size;
    int count;
    node_t* head;
    node_t *tail;
    map<int, node_t*>mm;
    LRUCache(int capacity) {
        size = capacity;
        count = 0;
        head = new node_t;
        tail = new node_t;
        head->next = tail;
        tail->prev = head;
        mm.clear();
    }

    int get(int key) {
        if (mm.count(key) == 0)
        {
            return -1;
        }
        auto ll = mm[key];
        auto pp = ll->prev;
        auto nn = ll->next;
        pp->next = nn;
        nn->prev = pp;
        auto hh = head->next;
        head->next = ll;
        ll->next = hh;
        hh->prev = ll;
        ll->prev = head;
        return ll->val;
    }

    void set(int key, int value) {
        if (mm.count(key) != 0)
        {
            auto ll = mm[key];
            ll->val = value;
            auto pp = ll->prev;
            auto nn = ll->next;
            pp->next = nn;
            nn->prev = pp;
            auto hh = head->next;
            head->next = ll;
            ll->next = hh;
            hh->prev = ll;
            ll->prev = head;
            return;
        }
        if (count != size)
        {
            count++;
            node_t *nn = new node_t;
            nn->key = key;
            nn->val = value;
            auto hh = head->next;
            head->next = nn;
            nn->next = hh;
            hh->prev = nn;
            nn->prev = head;
            mm[key] = nn;
            return;
        }
        else
        {
            auto ll = tail->prev;
            auto np = ll->prev;
            np->next = tail;
            tail->prev = np;
            auto nk = ll->key;
            auto pos = mm.find(nk);
            if (pos != mm.end())
            {
                mm.erase(pos);
            }
            ll->key = key;
            ll->val = value;
            mm[key] = ll;
            auto hh = head->next;
            head->next = ll;
            ll->next = hh;
            hh->prev = ll;
            ll->prev = head;
            return;
        }
    }
};
