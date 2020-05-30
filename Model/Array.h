#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "Exceptions/emptyexception.h"
#include "Exceptions/outofboundsexception.h"

template <class T>
class Array;
template <class T>
std::ostream& operator<< (std::ostream&, const Array<T>&);

template <class T>
class Array {
    friend std::ostream& operator<<<T>(std::ostream&, const Array<T>&);

private:
	T* x;
	int _size, _capacity;

    static T* copia(T* t, int sz, int cap);

public:
    // costruttore
    Array(int k = 0, const T& t = T());

	// costruttore di copia
    Array(const Array& t);

	// costruttore assegnazione
    Array& operator=(const Array& t);

	// distruttore
    ~Array();

	// operatore di uguaglianza
    bool operator==(const Array& a);

    class iterator {
        friend class Array<T>;

    private:
        T* i;
        bool isPastTheEnd;

        // convertitore da T* => const_iterator
        iterator(T* e, bool pte = false);

    public:
        iterator();

        T& operator*() const;

        T* operator->() const;

        iterator& operator++();

        iterator operator++(int);

//        iterator& operator--() {
//            if(i) {
//                if(!isPastTheEnd) {
//                    if(i - sizeof(T) != nullptr) --i;
//                    else throw OutOfBoundsException();
//                } else { --i; isPastTheEnd = false; }
//            }
//            return *this;
//        }

//        iterator operator--(int) {
//            iterator tmp = i;
//            --i;
//            return tmp;
//        }

        iterator operator+(int n);

//        iterator operator-(int n) {
//            return i - n;
//        }

        iterator& operator=(iterator it);

        bool operator==(iterator it) const;

        bool operator!=(iterator it) const;
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

        const T& operator*() const;

        const T* operator->() const;

        const_iterator& operator++();

        const_iterator operator++(int);

        const_iterator operator+(int n);

        const_iterator& operator=(const_iterator it);

        bool operator==(const_iterator it) const;

        bool operator!=(const_iterator it) const;
    };

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

	//===== ITERATORS =====
    iterator begin() const;

    iterator end() const;

    const_iterator cbegin() const;

    const_iterator cend() const;

    //===== ELEMENT ACCESS =====

	// Access element
    const T& operator[] (int pos) const;

    T& operator[] (int pos);

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

	// insert Insert elements (public member function )
//    iterator insert(iterator position, const T& val) {
//        if (position.i == nullptr) push_back(val);
//        else {
//            if (_size + 1 > _capacity) resize();
//            if (position != end()) {
//                for (iterator it = end(); it != position; it--) {
//                    *it = *(it - 1);
//                }
//            }
//            *position = val;
//            _size++;
//        }

//        return position;
//    }

	// erase Erase elements (public member function )
    iterator erase(iterator position);

	// clear Clear content (public member function )
    void clear();
};

#endif  // ARRAY_H
