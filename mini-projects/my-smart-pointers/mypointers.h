template <class T>
class Unique_Ptr
{
public:
    Unique_Ptr(T* p) : sp(p), _sp(p) { }
    Unique_Ptr() : sp(nullptr), _sp(nullptr) { }
    Unique_Ptr(const Unique_Ptr&) = delete;
    Unique_Ptr& operator=(const Unique_Ptr&) = delete;

    Unique_Ptr(Unique_Ptr&& rhs) {
        sp = rhs.sp;
        _sp = sp;
        rhs.sp = nullptr;
    }

    ~Unique_Ptr() { delete sp; }
    T& operator* () { return *sp; }
    T* operator->() { return sp; }
    T* get() const { return sp; }

    Unique_Ptr& operator=(Unique_Ptr&& rhs) {
        sp = rhs.sp;
        _sp = sp;
        rhs.sp = nullptr;
    }

    bool operator==(T* lvalue) {
        return sp == lvalue;
    }

    void reset() {
        delete sp;
        sp = nullptr;
        _sp = nullptr;
    }

    T* release() {
        sp = nullptr;
        return _sp;
    }

private:
    T* sp;
    T* _sp;
};

template <class T>
class Shared_Ptr
{
public:
    Shared_Ptr() : sp(nullptr), count_(nullptr) { }
    Shared_Ptr(T* p) : sp(p), count_(new int(1)) { }
    Shared_Ptr(const Shared_Ptr& rhs) {
        sp = rhs.sp;
        count_  = rhs.count_;
        if (count_) {
            (*count_)++;
        }
    }

    void reset() {
        if (count_) {
            (*count_)--;
            if (*count_ == 0) {
                delete sp;
                delete count_;
            }
        }
    }

    Shared_Ptr& operator=(const Shared_Ptr& rhs) {
        if (this == &rhs) {
            return *this;
        }
        reset();
        sp = rhs.sp;
        count_ = rhs.count_;
        if (count_) {
            (*count_)++;
        }
        return *this;
    }

    T& operator*() { return *sp; }
    T* operator->() { return sp; }

    bool operator==(const Shared_Ptr& rhs) {
        return sp == rhs.sp;
    }

    T* get() const { return sp;  }

    int count() const {
        if (count_ == nullptr) {
            return 0;
        }
        else {
            return *count_;
        }
    }

    ~Shared_Ptr() { reset(); }
private:
    T* sp;
    int* count_;
};