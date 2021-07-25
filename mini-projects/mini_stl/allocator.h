#ifndef __MINI_ALLOCATOR__
#define __MINI_ALLOCATOR__

#include <cstddef>
#include <new>

namespace ministl {

template<class T>
class allocator {

public:
    typedef T           value_type;
    typedef T*          pointer;
    typedef const T*    const_pointer;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

    static T* allocate();
    static T* allocate(size_type n);

    static void deallocate(T* ptr);
    static void deallocate(T* ptr, size_type n);

};

template<class T>
T* allocator<T>::allocate() {
    return static_cast<T*>(::operator new(sizeof(T)));
}

template<class T>
T* allocator<T>::allocate(size_type n) {
    if (n == 0) {
        return nullptr;
    }
    return static_cast<T*>(::operator new(n * sizeof(T)));
}

template<class T>
void allocator<T>::deallocate(T* ptr) {
    if (ptr == nullptr) {
        return;
    }
    ::operator delete(ptr);
}

template<class T>
void allocator<T>::deallocate(T* ptr, size_type) {
    if (ptr == nullptr) {
        return;
    }
    ::operator delete(ptr);
}

} // namespace ministl

#endif