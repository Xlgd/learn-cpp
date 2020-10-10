// 3.1

// Value Type


/* because of the type inference, we can get the iterator value type
 * through this method
 */

template <class I, class T>
void f_impl(I iter, T t) {
    T tmp; // T is I's value type
    //...
}

template <class T> inline void f(I iter) {
    f_impl(iter, *iter);
    //...
}

/* three methods about iterator_traits */

template <class Iterator>
struct iterator_traits {
    typedef typename Iterator::value_type value_type;
};

template <class T>
struct iterator_traits<T*> {
    typedef T value_type;
};

template <class T>
struct iterator_traits<const T*> {
    typedef T value_type;
};

// Difference Type

template <class InputIterator, class T>
typename iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const T& x) {
    typename iterator_traits<InputIterator>::difference_type n = 0;
    for (; first != last; ++first) {
        ++n;
    }
    return n;
}

//Implementation of iterator_traits
template <class Iterator>
struct iterator_traits {
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
};

template <class T>
struct iterator_traits<T*> {
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
};

template <class T>
struct iterator_traits<const T*> {
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;
};

// base class iterator
template <class Category,
          class Value,
          class Distance = ptrdiff_t,
          class Pointer = Value*,
          class Reference = Value&>
struct iterator {
    typedef Category iterator_category;
    typedef Value value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
};

// 3.2 New Components

// the complete definition of node_wrap and const_node_wrap
template <class Node, class Reference, class Pointer>
struct node_wrap_base : public iterator<forward_iterator_tag, Node, 
                                        ptrdiff_t, Pointer, Reference> {
    typedef node_wrap_base<Node, Node&, Node*> iterator;
    typedef node_wrap_base<Node, const Node&, const Node*> const_iterator;
    Pointer ptr;

    node_wrap_base(Pointer p = 0) : ptr(p) {}
    node_wrap_base(const iterator& x) : ptr(x.ptr) {}

    Reference operator*() const { return *ptr; }
    Pointer operator->() const { return ptr; }

    void incr() { ptr = ptr->next; }

    bool operator==(const node_wrap_base& x) const { return ptr == x.ptr; }
    bool operator!=(const node_wrap_base& x) const { return ptr != x.ptr; }

};

template <class Node>
struct node_wrap : public node_wrap_base<Node, Node&, Node*>
{
    typedef node_wrap_base<Node, Node&, Node*> Base;
    node_wrap(Node* p = 0) : Base(p) {}
    node_wrap(const node_wrap<Node>& x) : Base(x) {}
    node_wrap& operator++() {
        incr();
        return *this;
    }
    node_wrap operator++(int) {
        node_wrap tmp = *this;
        incr();
        return tmp;
    }
};

template <class Node>
struct const_node_wrap : public node_wrap_base<Node, const Node&, const Node*> {
    typedef node_wrap_base<Node, const Node&, const Node*> Base;
    const_node_wrap(const Node* p = 0) : Base(p) {}
    const_node_wrap(const node_wrap<Node>& x) : Base(x) {}
    const_node_wrap& operator++() {
        incr();
        return *this;
    }

    const_node_wrap operator++(int) {
        const_node_wrapo tmp = *this;
        incr();
        return tmp;
    }
};