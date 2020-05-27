#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

class Empty: public std::runtime_error {
public:
	Empty(): std::runtime_error("Exception: trying to remove an element from empty array.") {}
};

template <class T>
class Array;
template <class T>
std::ostream& operator<<(std::ostream&, const Array<T>&);

template <class T>
class Array {
	friend std::ostream& operator<<(std::ostream&, const Array<T>&);

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
	Array(int k = 0, const T& t = T()) : x(0), _size(k), _capacity(k * 2) {
		if (k) {
			x = new T[k * 2];
			for (int i = 0; i < _size; i++)
				x[i] = t;
		}
	}
	// costruttore di copia
	Array(const Array& t)
			: x(copia(t.x, t._size, t._capacity)), _size(t._size), _capacity(t._capacity) {}
	// costruttore assegnazione
	Array& operator=(const Array& t) {
		if (this != t) {
			delete[] x;
			x = copia(t, t._size, t._capacity);
			_size = t._size;
			_capacity = t._capacity;
		}
		return *this;
	}
	// distruttore
	~Array() { delete[] x; }
	// operatore di uguaglianza
	bool operator==(const Array& a) {
		if (_size != a._size)
			return false;
		for (int i = 0; i < _size; i++)
			if (x[i] != a[i])
				return false;
		return true;
	}

    //****CAPACITY****

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
        x = copia(x, _size, _capacity * 2);
        _capacity = _capacity * 2;
    }

	class iterator {
        friend class Array<T>;

	private:
		T* i;
		bool isPastTheEnd;

		// convertitore da T* => const_iterator
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
					if(i + sizeof(T) == nullptr) {++i; isPastTheEnd=true;}
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

        iterator& operator=(iterator it) {
			i = it.i;
			return *this;
		}

		bool operator==(iterator it) { return i == it.i; }

		bool operator!=(iterator it) { return i != it.i; }
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

		const_iterator& operator=(const_iterator it) {
			i = it.i;
			return *this;
		}

		bool operator==(const_iterator it) { return i == it.i; }

		bool operator!=(const_iterator it) { return i != it.i; }
	};

	//===== ITERATORS =====
	iterator begin() const { 
        return &x[0];
	}

	iterator end() const { 
		if (empty()) return nullptr; 
        return iterator(&x[_size], true);
	}

    const_iterator cbegin() const {
        return &x[0];
	}

    const_iterator cend() const {
		if (empty()) return nullptr; 
        return const_iterator(&x[_size], true);
	}

	//****ELEMENT ACCESS****

	// Access element
	const T& operator[] (int pos) const {
		return x[pos];
	}

	T& operator[] (int pos) {
		return x[pos];
	}

	// Returns a reference to the first element in the vector.
	T front() const {
		if(empty())
				throw Empty();    //undefined behavior
		else
			return x[0];
	}

	T front() {
		if(empty())
				throw Empty();    //undefined behavior
		else
			return x[0];
	}

	// Returns a reference to the last element in the vector.
	T back() const {
		if(empty())
				throw Empty();    //undefined behavior
		else
			return x[_size-1];
	}

	T back() {
		if(empty())
				throw Empty();    //undefined behavior
		else
			return x[_size-1];
	}

	//****MODIFIERS****

	// Add element at the end
	void push_back(const T& t) {
		if (full()) resize();
		x[_size] = t;
		_size++;
	}

	// Delete last element
	T pop_back() {
		if (x) {
			T aux = x[_size - 1];
			delete x[_size - 1];
			_size--;
			return aux;
		} else
			throw Empty();  // TODO: gestire con una eccezione
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
	for (int i = 0; i < a._size; i++) {
		os << (a.x)[i] << " ";
	}
	return os;
}

#endif  // ARRAY_H
