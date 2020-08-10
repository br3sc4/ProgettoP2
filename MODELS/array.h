#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "EXCEPTIONS/emptyexception.h"
#include "EXCEPTIONS/outofboundsexception.h"

template <class T> class Array;
template <class T> std::ostream& operator<< (std::ostream&, const Array<T>&);

template <class T>
class Array {
    friend std::ostream& operator<<<T>(std::ostream&, const Array<T>&);

private:
    T* x;
    int _size, _capacity;

    static T* copia(T* t, int sz, int cap);

public:
    // costruttore
    Array(const T& t = T(), int k = 0);

    // costruttore di copia
    Array(const Array& t);

    // costruttore assegnazione
    Array& operator=(const Array& t);

    // distruttore
    ~Array();

    // operatore di uguaglianza
    bool operator==(const Array& a) const;

    //===== CAPACITY =====

    // Returns the number of elements in the vector.
    int size() const;

    // Return size of allocated storage capacity
    int capacity() const;

    // Test whether vector is empty
    bool empty() const;

    // Test whether vector is full
    bool full() const;

    // Double the vector capacity
    void resize();

    class iterator {
        friend class Array<T>;

    private:
        T* i;
        bool isPastTheEnd;

        // convertitore da T* => iterator
        iterator(T* e, bool pte = false);

    public:
        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;

        iterator();
        iterator& operator=(iterator it);

        reference operator*() const;
        pointer operator->() const;

        // Forward category
        iterator& operator++();
        iterator operator++(int);

        // Bidirectional category
        iterator& operator--();
        iterator operator--(int);

        // Random access category
        iterator operator+(int n) const;
        iterator operator-(int n) const;
        difference_type operator-(const iterator& it) const;
        iterator& operator+=(int n);
        iterator& operator-=(int n);
        bool operator<(iterator it) const;
        bool operator>(iterator it) const;
        bool operator<=(iterator it) const;
        bool operator>=(iterator it) const;
        bool operator==(iterator it) const;
        bool operator!=(iterator it) const;
        reference operator[](int n) const;
    };

    class const_iterator {
        friend class Array<T>;

    private:
        T* i;
        bool isPastTheEnd;

        // convertitore da T* => const_iterator
        const_iterator(T* e, bool pte = false);

    public:
        const_iterator();
        const_iterator& operator=(const_iterator it);

        const T& operator*() const;
        const T* operator->() const;

        // Forward category
        const_iterator& operator++();
        const_iterator operator++(int);

        const_iterator operator+(int n) const;

        bool operator==(const_iterator it) const;
        bool operator!=(const_iterator it) const;
    };

    //===== ITERATORS =====
    iterator begin() const;

    iterator end() const;

    const_iterator cbegin() const;

    const_iterator cend() const;

    //===== ELEMENT ACCESS =====

    // Access element
    const T& operator[] (int pos) const;

    T& operator[] (int pos);

    const T& operator[] (Array::const_iterator pos) const;

    T& operator[] (Array::iterator pos) const;

    // Returns a reference to the first element in the vector.
    const T& front() const;

    T& front();

    // Returns a reference to the last element in the vector.
    const T& back() const;

    T& back();

    //===== MODIFIERS =====

    // Add element at the end
    void push_back(const T& t);

    // Delete last element
    void pop_back();

    // Erase elements (public member function )
    T erase(iterator position);

    // Clear content (public member function )
    void clear();
};

template <class T>
std::ostream& operator<< (std::ostream& os, const Array<T>& a) {
    for (typename Array<T>::const_iterator it = a.cbegin(); it != a.cend(); it++) {
        os << *it << " ";
    }
    return os;
}

template<class T>
T* Array<T>::copia(T *t, int sz, int cap) {
    T* a = new T[cap];
    for (int i = 0; i < sz; ++i)
        a[i] = t[i];
    return a;
}

template<class T>
Array<T>::Array(const T &t, int k) : x(k == 0 ? nullptr : new T[k * 2]), _size(k), _capacity(k * 2) {
    for (int i = 0; i < _size; i++)
        x[i] = t;
}

template<class T>
Array<T>::Array(const Array &t): x(copia(t.x, t._size, t._capacity)), _size(t._size), _capacity(t._capacity) {}

template<class T>
Array<T>& Array<T>::operator=(const Array &t) {
    if (this != &t) {
        delete[] x;
        x = copia(t, t._size, t._capacity);
        _size = t._size;
        _capacity = t._capacity;
    }
    return *this;
}

template<class T>
Array<T>::~Array() {
    delete[] x;
}

template<class T>
bool Array<T>::operator==(const Array &a) const {
    if (this == &a) return true;
    if (_size != a._size) return false;
    for (int i = 0; i < _size; i++)
        if (x[i] != a[i])
            return false;
    return true;
}

template<class T>
int Array<T>::size() const {
    return _size;
}

template<class T>
int Array<T>::capacity() const {
    return _capacity;
}

template<class T>
bool Array<T>::empty() const {
    return _size == 0; // anche x==nullptr ?
}

template<class T>
bool Array<T>::full() const {
    return _size == _capacity;
}

template<class T>
void Array<T>::resize() {
    if (_capacity == 0) ++_capacity;
    x = copia(x, _size, _capacity * 2);
    _capacity = _capacity * 2;
}

template<class T>
Array<T>::iterator::iterator(T *e, bool pte): i(e), isPastTheEnd(pte) {}

template<class T>
Array<T>::iterator::iterator(): i(nullptr), isPastTheEnd(false) {}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator=(Array::iterator it) {
    i = it.i;
    return *this;
}

template<class T>
T& Array<T>::iterator::operator*() const {
    return *i;
}

template<class T>
T* Array<T>::iterator::operator->() const {
    return i;
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator++() {
    if (i) {
        if (!isPastTheEnd) {
            if (i + sizeof(T) == nullptr) {++i; isPastTheEnd = true;}
            else ++i;
        }
    }
    return *this;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator++(int) {
    iterator tmp = i;
    ++i;
    return tmp;
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator--() {
    if (i) {
        if (isPastTheEnd) {--i; isPastTheEnd = false;}
        else --i;
    }
    return *this;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator--(int) {
    iterator tmp = i;
    --i;
    return tmp;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator+(int n) const {
    iterator tmp = i;
    if (tmp.i) {
        if (!tmp.isPastTheEnd) {
            if (i + n * sizeof (T) == nullptr) {tmp.i += n; tmp.isPastTheEnd = true; }
            else tmp.i += n;
        }
    }
    return tmp;
}

template<class T>
typename Array<T>::iterator Array<T>::iterator::operator-(int n) const {
    iterator tmp = i;
    if (tmp.i) {
        if (tmp.isPastTheEnd) {tmp.i -= n; tmp.isPastTheEnd = false;}
        else tmp.i -= n;
    }
    return tmp;
}

template<class T>
typename Array<T>::iterator::difference_type Array<T>::iterator::operator-(const Array::iterator& it) const {
    return i - it.i;
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator+=(int n) {
    if (i) {
        if (!isPastTheEnd) {
            if (i + n * sizeof (T) == nullptr) {i += n; isPastTheEnd = true; }
            else i += n;
        }
    }
    return *this;
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator-=(int n) {
    if (i) {
        if (isPastTheEnd) {i -= n; isPastTheEnd = false;}
        else i -= n;
    }
    return *this;
}

template<class T>
bool Array<T>::iterator::operator<(Array::iterator it) const {
    return i < it.i;
}

template<class T>
bool Array<T>::iterator::operator>(Array::iterator it) const {
    return i > it.i;
}

template<class T>
bool Array<T>::iterator::operator<=(Array::iterator it) const {
    return i <= it.i;
}

template<class T>
bool Array<T>::iterator::operator>=(Array::iterator it) const {
    return i >= it.i;
}

template<class T>
bool Array<T>::iterator::operator==(Array::iterator it) const {
    return i == it.i;
}

template<class T>
bool Array<T>::iterator::operator!=(Array::iterator it) const {
    return i != it.i;
}

template<class T>
typename Array<T>::iterator::reference Array<T>::iterator::operator[](int n) const {
    if (i + n * sizeof (T) == nullptr) throw OutOfBoundsException();
    return *i;
}

template<class T>
Array<T>::const_iterator::const_iterator(T *e, bool pte): i(e), isPastTheEnd(pte) {}

template<class T>
Array<T>::const_iterator::const_iterator(): i(nullptr), isPastTheEnd(false) {}

template<class T>
const T& Array<T>::const_iterator::operator*() const {
    return *i;
}

template<class T>
const T* Array<T>::const_iterator::operator->() const {
    return &(i);
}

template<class T>
typename Array<T>::const_iterator& Array<T>::const_iterator::operator++() {
    if(i) {
        if(!isPastTheEnd) {
            if(i + sizeof(T) == nullptr) {++i; isPastTheEnd=true;}
            else ++i;
        }
    }
    return *this;
}

template<class T>
typename Array<T>::const_iterator Array<T>::const_iterator::operator++(int) {
    const_iterator tmp = i;
    ++i;
    return tmp;
}

template<class T>
typename Array<T>::const_iterator Array<T>::const_iterator::operator+(int n) const {
    return i + n;
}

template<class T>
typename Array<T>::const_iterator& Array<T>::const_iterator::operator=(Array::const_iterator it) {
    i = it.i;
    return *this;
}

template<class T>
bool Array<T>::const_iterator::operator==(Array::const_iterator it) const {
    return i == it.i;
}

template<class T>
bool Array<T>::const_iterator::operator!=(Array::const_iterator it) const {
    return i != it.i;
}

template<class T>
typename Array<T>::iterator Array<T>::begin() const {
    if (empty()) return nullptr;
    return &x[0];
}

template<class T>
typename Array<T>::iterator Array<T>::end() const {
    if (empty()) return nullptr;
    return iterator(&x[_size], true);
}

template<class T>
typename Array<T>::const_iterator Array<T>::cbegin() const {
    if (empty()) return nullptr;
    return &x[0];
}

template<class T>
typename Array<T>::const_iterator Array<T>::cend() const {
    if (empty()) return nullptr;
    return const_iterator(&x[_size], true);
}

template<class T>
const T& Array<T>::operator[](int pos) const {
    if (pos < 0 || pos >= _size) throw OutOfBoundsException();
    return x[pos];
}

template<class T>
T& Array<T>::operator[](int pos) {
    if (pos < 0 || pos >= _size) throw OutOfBoundsException();
    return x[pos];
}

template<class T>
const T& Array<T>::operator[](Array::const_iterator pos) const {
    return *(pos.i);
}

template<class T>
T& Array<T>::operator[](Array::iterator pos) const {
    return *(pos.i);
}

template<class T>
const T& Array<T>::front() const {
    if(empty())
        throw new EmptyException();    //undefined behavior
    else
        return x[0];
}

template<class T>
T& Array<T>::front() {
    if(empty())
        throw new EmptyException();    //undefined behavior
    else
        return x[0];
}

template<class T>
const T& Array<T>::back() const {
    if(empty())
        throw new EmptyException();    //undefined behavior
    else
        return x[_size - 1];
}

template<class T>
T& Array<T>::back() {
    if(empty())
        throw new EmptyException();    //undefined behavior
    else
        return x[_size - 1];
}

template<class T>
void Array<T>::push_back(const T &t) {
    if (full()) resize();
    x[_size] = t;
    _size++;
}

template<class T>
void Array<T>::pop_back() {
    if (!empty()) {
        x[_size - 1] = x[_size];
        _size--;
    } else
        throw new EmptyException();
}

template<class T>
T Array<T>::erase(Array::iterator position) {
    T aux = *position;

    for (; position != end(); position++) {
        *position = *(position + 1);
    }

    --_size;
    return aux;
}

template<class T>
void Array<T>::clear() {
    delete[] x;
    x = new T[_capacity];
    _size = 0;
}

#endif  // ARRAY_H
