#ifndef ARRAY_H
#define ARRAY_H
#include "ostream"

class Empty {
 public:
  Empty() {
    // segnala errore
  }
};

template <class T>
class Array;
template <class T>
std::ostream& operator<<(std::ostream&, const Array<T>&);
template <class T>
class Array {
  friend std::ostream& operator<<<>(std::ostream&, const Array<T>&);

 private:
  T* x;
  int size, capacity;

  static T* copia(T* t, int sz, int cap) {
    T* a = new T[cap];
    for (int i = 0; i < sz; ++i)
      a[i] = t[i];
    return a;
  }

 public:
  // costruttore
  Array(int k = 0, const T& t = T()) : x(0), size(k), capacity(k * 2) {
    if (k) {
      x = new T[k * 2];
      for (int i = 0; i < size; i++)
        x[i] = t;
    }
  }
  // costruttore di copia
  Array(const Array& t)
      : x(copia(t.x, t.size, t.capacity)), size(t.size), capacity(t.capacity) {}
  // costruttore assegnazione
  Array& operator=(const Array& t) {
    if (this != t) {
      delete[] x;
      x = copia(t, t.size, t.capacity);
      size = t.size;
      capacity = t.capacity;
    }
    return *this;
  }
  // distruttore
  ~Array() { delete[] x; }

  bool operator==(const Array& a) {
    if (size != a.size)
      return false;
    for (int i = 0; i < size; i++)
      if (x[i] != a[i])
        return false;
    return true;
  }

  class const_iterator;
  class iterator {
    friend class const_iterator;

   private:
    T* i;

   public:
    iterator(typename T::iterator it) : i(it) {}
    T operator*() { return *i; }
    iterator& operator++() {
      ++i;
      return *this;
    }
    iterator operator++(int) {
      typename T::iterator tmp = i;
      operator++();
      return tmp;
    }
    iterator& operator=(iterator i2) {
      i = i2.i;
      return *this;
    }
    bool operator==(iterator i2) { return i == i2.i; }
    bool operator!=(iterator i2) { return i != i2.i; }
  };
  class const_iterator {
   private:
    const T* i;

   public:
    const_iterator(typename T::const_iterator it) : i(it) {}
    // conversione da iteratore a const_iteratore
    const_iterator(iterator it) : i(it.i) {}
    const T operator*() { return *i; }
    const_iterator& operator++() {
      ++i;
      return *this;
    }
    const_iterator operator++(int) {
      typename T::const_iterator tmp = i;
      operator++();
      return tmp;
    }
    const_iterator& operator=(const_iterator i2) {
      i = i2.i;
      return *this;
    }
    bool operator==(const_iterator i2) { return i == i2.i; }
    bool operator!=(const_iterator i2) { return i != i2.i; }
  };

  //****ITERATORS****

  const_iterator begin() const { return x[0]; }

  const_iterator end() const { return nullptr; }

  //****CAPACITY****

  // size  Returns the number of elements in the vector.

  // max_size Returns the maximum number of elements that the vector can hold.

  // resize Change size (public member function )
  /*Change size
Resizes the container so that it contains n elements.
If n is smaller than the current container size, the content is reduced to its
first n elements, removing those beyond (and destroying them).
If n is greater than the current container size, the content is expanded by
inserting at the end as many elements as needed to reach a size of n. If val is
specified, the new elements are initialized as copies of val, otherwise, they
are value-initialized.
If n is also greater than the current container capacity, an automatic
reallocation of the allocated storage space takes place.
Notice that this function changes the actual content of the container by
inserting or erasing elements from it.
*/

  // capacity Return size of allocated storage capacity (public member function
  // )

  // empty Test whether vector is empty (public member function )

  //****ELEMENT ACCESS****

  // operator[] Access element (public member function ) const e non

  // front Access first element (public member function ) const e non
  /*Access first element
Returns a reference to the first element in the vector.
Unlike member vector::begin, which returns an iterator to this same element,
this function returns a direct reference.
Calling this function on an empty container causes undefined behavior.*/

  // back Access last element (public member function )
  /*
Returns a reference to the last element in the vector.
Unlike member vector::end, which returns an iterator just past this element,
this function returns a direct reference.
Calling this function on an empty container causes undefined behavior*/

  //****MODIFIERS****

  // push_back Add element at the end
  void push_back(const T& t) {
    if (size == capacity) {
      x = copia(x, size, capacity * 2);
      capacity = capacity * 2;
      x[size] = t;
      size++;
    } else {
      x[size] = t;
      size++;
    }
  }

  // pop_back Delete last element (public member function )
  T pop_back() {
    if (x) {
      T aux = x[size - 1];
      delete x[size - 1];
      size--;
      return aux;
    } else
      throw Empty();  // TODO: gestire con una eccezione ?
  }

  // insert Insert elements (public member function )
  // TODO: iterator insert (iterator position, const value_type& val);

  // erase Erase elements (public member function )
  // iterator erase (iterator position);
  // iterator erase (iterator first, iterator last);
  // attenzione metodo inefficiente perché bisogna riallocare gli elementi
  // ancora presenti

  // clear Clear content (public member function )
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a) {
  for (int i = 0; i < a.size; i++) {
    os << (a.x)[i] << " ";
  }
  return os;
}

#endif  // ARRAY_H
