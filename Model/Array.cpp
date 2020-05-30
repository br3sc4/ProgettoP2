#include "array.h"

template<class T>
T* Array<T>::copia(T *t, int sz, int cap) {
    T* a = new T[cap];
    for (int i = 0; i < sz; ++i)
        a[i] = t[i];
    return a;
}

template<class T>
Array<T>::Array(int k, const T &t) : x(k == 0 ? nullptr : new T[k * 2]), _size(k), _capacity(k * 2) {
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
bool Array<T>::operator==(const Array &a) {
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
T& Array<T>::operator[](int pos) {
    if (pos < 0 || pos >= _size) throw OutOfBoundsException();
    return x[pos];
}

template<class T>
const T& Array<T>::front() const {
    if(empty())
        throw EmptyException();    //undefined behavior
    else
        return x[0];
}

template<class T>
T& Array<T>::front() {
    if(empty())
        throw EmptyException();    //undefined behavior
    else
        return x[0];
}

template<class T>
const T& Array<T>::back() const {
    if(empty())
        throw EmptyException();    //undefined behavior
    else
        return x[_size - 1];
}

template<class T>
T& Array<T>::back() {
    if(empty())
        throw EmptyException();    //undefined behavior
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
        throw EmptyException();
}

template<class T>
typename Array<T>::iterator Array<T>::erase(Array::iterator position) {
    iterator aux = position;
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

template<class T>
const T& Array<T>::operator[](int pos) const {
    if (pos < 0 || pos >= _size) throw OutOfBoundsException();
    return x[pos];
}

template<class T>
Array<T>::iterator::iterator(T *e, bool pte): i(e), isPastTheEnd(pte) {}

template<class T>
Array<T>::iterator::iterator(): i(nullptr), isPastTheEnd(false) {}

template<class T>
T& Array<T>::iterator::operator*() const {
    return *i;
}

template<class T>
T* Array<T>::iterator::operator->() const {
    return &(i);
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator++() {
    if(i) {
        if(!isPastTheEnd) {
            if(i + sizeof(T) == nullptr) {++i; isPastTheEnd = true;}
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
typename Array<T>::iterator Array<T>::iterator::operator+(int n) {
    return i + n; // verifica che sia contiguo
}

template<class T>
typename Array<T>::iterator& Array<T>::iterator::operator=(Array::iterator it) {
    i = it.i;
    return *this;
}

template<class T>
bool Array<T>::iterator::operator==(Array::iterator it) const { return i == it.i; }

template<class T>
bool Array<T>::iterator::operator!=(Array::iterator it) const { return i != it.i; }

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
typename Array<T>::const_iterator Array<T>::const_iterator::operator+(int n) {
    return i + n;
}

template<class T>
typename Array<T>::const_iterator& Array<T>::const_iterator::operator=(Array::const_iterator it) {
    i = it.i;
    return *this;
}

template<class T>
bool Array<T>::const_iterator::operator==(Array::const_iterator it) const { return i == it.i; }

template<class T>
bool Array<T>::const_iterator::operator!=(Array::const_iterator it) const { return i != it.i; }

template <class T>
std::ostream& operator<< (std::ostream& os, const Array<T>& a) {
    for (typename Array<T>::const_iterator it = a.cbegin(); it != a.cend(); it++) {
        os << *it << " ";
    }
    return os;
}
