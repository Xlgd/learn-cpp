# include <iostream>
# include <string>
# include <vector>

class line_iterator {
    std::istream* in;
    std::string line;
    bool is_valid;
    void read() {
        if (*in) {
            getline(*in, line);
        }
        is_valid = (*in) ? true : false;
    }

public:
    typedef std::string value_type;
    typedef ptrdiff_t difference_type;
    typedef const std::string* pointer;
    typedef const std::string& reference;

    line_iterator() : in(&std::cin), is_valid(false) {}
    line_iterator(std::istream& s) : in(&s) { read(); }
    reference operator*() const { return line; }
    pointer operator->() const { return &line; }
    line_iterator operator++() {
        read();
        return *this;
    }

    line_iterator operator++(int) {
        line_iterator tmp = *this;
        read();
        return tmp;
    }

    bool operator==(const line_iterator& i) const {
        return (in == i.in && is_valid == i.is_valid || is_valid == false && i.is_valid == false);
    }

    bool operator!=(const line_iterator& i) const {
        return !(*this == i);
    }
};

struct strtab_cmp {
    typedef std::vector<char>::iterator strtab_iterator;

    bool operator() (const std::pair<strtab_iterator, strtab_iterator>& x,
                     const std::pair<strtab_iterator, strtab_iterator>& y) const {
                         return std::lexicographical_compare(x.first, x.second, y.first, y.second);
    }
};

struct strtab_print {
    std::ostream& out;
    strtab_print(std::ostream& os) : out(os) {}

    typedef std::vector<char>::iterator strtab_iterator;
    void operator() (const std::pair<strtab_iterator, strtab_iterator>& s) const {
        std::copy(s.first, s.second, std::ostream_iterator<char>(out));
    }
};

