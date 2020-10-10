// linked list node
struct int_node
{
    int val;
    int_node* next;
};

// a template wrapped class to fit linked list node
template <class Node>
struct node_wrap {
    Node* ptr;

    node_wrap(Node* p = 0) : ptr(p) {}
    Node& operator*() const { return *ptr; }
    Node* operator->() const { return ptr; }

    node_wrap& operator++() {
        ptr = ptr->next;
        return *this;
    }
    node_wrap& operator++(int) {
        node_wrap tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator==(const node_wrap& i) const { return ptr == i.ptr; }
    bool operator!=(const node_wrap& i) const { return ptr != i.ptr; }

};

/* so we can use find function to search val in a linked list

   it combines the old data structure (int_node linked list) and 
   the new generic algorithm (find)

eg:
   find(node_wrap<int_node>(list_head), node_wrap<int_node>(), val)

*/