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

    static T* copia(T* t, int sz, int cap) {
        T* a = new T[cap];
        for (int i = 0; i < sz; ++i)
            a[i] = t[i];
        return a;
    }

public:
    // costruttore
    Array(const T& t = T(), int k = 0) : x(k == 0 ? nullptr : new T[k * 2]), _size(k), _capacity(k * 2) {
        for (int i = 0; i < _size; i++)
            x[i] = t;
    }

    // costruttore di copia
    Array(const Array& t): x(copia(t.x, t._size, t._capacity)), _size(t._size), _capacity(t._capacity) {}

    // costruttore assegnazione
    Array& operator=(const Array& t) {
        if (this != &t) {
            delete[] x;
            x = copia(t, t._size, t._capacity);
            _size = t._size;
            _capacity = t._capacity;
        }
        return *this;
    }

    // distruttore
    ~Array() {
        delete[] x;
    }

    // operatore di uguaglianza
    bool operator==(const Array& a) const {
        if (this == &a) return true;
        if (_size != a._size) return false;
        for (int i = 0; i < _size; i++)
            if (x[i] != a[i])
                return false;
        return true;
    }

    //===== CAPACITY =====

    // Returns the number of elements in the vector.
    int size() const {
        return _size;
    }

    // Return size of allocated storage capacity
    int capacity() const {
        return _capacity;
    }

    // Test whether vector is empty
    bool empty() const {
        return _size == 0; // anche x==nullptr ?
    }

    // Test whether vector is full
    bool full() const {
        return _size == _capacity;
    }

    // Double the vector capacity
    void resize() {
        if (_capacity == 0) ++_capacity;
        x = copia(x, _size, _capacity * 2);
        _capacity = _capacity * 2;
    }

    class iterator {
        friend class Array<T>;

    private:
        T* i;
        bool isPastTheEnd;

        // convertitore da T* => iterator
        iterator(T* e, bool pte = false): i(e), isPastTheEnd(pte) {}

    public:
        iterator(): i(nullptr), isPastTheEnd(false) {}

        T& operator*() const {
            return *i;
        }

        T* operator->() const {
            return &(i);
        }

        iterator& operator++() {
            if(i) {
                if(!isPastTheEnd) {
                    if(i + sizeof(T) == nullptr) {++i; isPastTheEnd = true;}
                    else ++i;
                }
            }
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = i;
            ++i;
            return tmp;
        }

        iterator operator+(int n) const {
            return i + n; // verifica che sia contiguo
        }

        iterator& operator=(iterator it) {
            i = it.i;
            return *this;
        }

        bool operator==(iterator it) const { return i == it.i; }

        bool operator!=(iterator it) const { return i != it.i; }
    };

    class const_iterator {
        friend class Array<T>;

    private:
        T* i;
        bool isPastTheEnd;

        // convertitore da T* => const_iterator
        const_iterator(T* e, bool pte = false): i(e), isPastTheEnd(pte) {}

    public:
        const_iterator(): i(nullptr), isPastTheEnd(false) {}

        const T& operator*() const {
            return *i;
        }

        const T* operator->() const {
            return &(i);
        }

        const_iterator& operator++() {
            if(i) {
                if(!isPastTheEnd) {
                    if(i + sizeof(T) == nullptr) {++i; isPastTheEnd=true;}
                    else ++i;
                }
            }
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp = i;
            ++i;
            return tmp;
        }

        const_iterator operator+(int n) const {
            return i + n;
        }

        const_iterator& operator=(const_iterator it) {
            i = it.i;
            return *this;
        }

        bool operator==(const_iterator it) const { return i == it.i; }

        bool operator!=(const_iterator it) const { return i != it.i; }
    };

    //===== ITERATORS =====
    iterator begin() const {
        if (empty()) return nullptr;
        return &x[0];
    }

    iterator end() const {
        if (empty()) return nullptr;
        return iterator(&x[_size], true);
    }

    const_iterator cbegin() const {
        if (empty()) return nullptr;
        return &x[0];
    }

    const_iterator cend() const {
        if (empty()) return nullptr;
        return const_iterator(&x[_size], true);
    }

    //===== ELEMENT ACCESS =====

    // Access element
    const T& operator[] (int pos) const {
        if (pos < 0 || pos >= _size) throw OutOfBoundsException();
        return x[pos];
    }

    T& operator[] (int pos) {
        if (pos < 0 || pos >= _size) throw OutOfBoundsException();
        return x[pos];
    }

    const T& operator[] (Array::const_iterator pos) const {
        return *(pos.i);
    }

    T& operator[] (Array::iterator pos) const {
        return *(pos.i);
    }

    // Returns a reference to the first element in the vector.
    const T& front() const {
        if(empty())
            throw new EmptyException();    //undefined behavior
        else
            return x[0];
    }

    T& front() {
        if(empty())
            throw new EmptyException();    //undefined behavior
        else
            return x[0];
    }

    // Returns a reference to the last element in the vector.
    const T& back() const {
        if(empty())
            throw new EmptyException();    //undefined behavior
        else
            return x[_size - 1];
    }

    T& back() {
        if(empty())
            throw new EmptyException();    //undefined behavior
        else
            return x[_size - 1];
    }

    //===== MODIFIERS =====

    // Add element at the end
    void push_back(const T& t) {
        if (full()) resize();
        x[_size] = t;
        _size++;
    }

    // Delete last element
    void pop_back() {
        if (!empty()) {
            x[_size - 1] = x[_size];
            _size--;
        } else
            throw new EmptyException();
    }

    // Erase elements (public member function )
    T erase(iterator position) {
        T aux = *position;

        for (; position != end(); position++) {
            *position = *(position + 1);
        }

        --_size;
        return aux;
    }

    // Clear content (public member function )
    void clear() {
        delete[] x;
        x = new T[_capacity];
        _size = 0;
    }
};

template <class T>
std::ostream& operator<< (std::ostream& os, const Array<T>& a) {
    for (typename Array<T>::const_iterator it = a.cbegin(); it != a.cend(); it++) {
        os << *it << " ";
    }
    return os;
}

#endif  // ARRAY_H
