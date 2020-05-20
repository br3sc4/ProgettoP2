#ifndef ARRAY_H
#define ARRAY_H
#include "ostream"

class Empty{
public:
  Empty(){
      //segnala errore
  }
};

template <class T> class Array;
template <class T> std::ostream& operator<<(std::ostream&, const Array<T>&);
template <class T>
class Array {
  friend std::ostream& operator<< <>(std::ostream&, const Array<T>&);
private:
  T* x;
  int size, capacity;

  static T* copia(T* t, int sz, int cap){
    T* a = new T[cap];
    for(int i=0; i<sz; ++i)
      a[i]=t[i];
    return a;
  }

public:
  Array(int k=0, const T& t = T()): x(0), size(k), capacity(k*2){
    if (k) {
        x=new T[k*2];
        for(int i=0; i<size; i++)
          x[i]=t;
      }
  }
  //richiamo copia sull'oggetto di invocazione e gli passo i parametri di t
  Array(const Array& t):x(copia(t.x,t.size,t.capacity)),size(t.size),capacity(t.capacity){}
  ~Array(){delete[] x;}
  Array& operator=(const Array& t){
    if(this != t){
        delete[] x;
        x=copia(t,t.size,t.capacity);
        size=t.size;
        capacity=t.capacity;
      }
    return *this;
  }

  void pushBack(const T& t){
    if (size==capacity) {
        x=copia(x, size, capacity*2);
        capacity=capacity*2;
        x[size]=t;
        size++;
      }
    else {
        x[size]=t;
        size++;
      }
  }

  T popBack(){
    if(x){
        T aux = x[size-1];  //T SENZA *
        delete x[size-1];
        size--;   //RICORDATI
        return aux;
      }else throw Empty();
  }

  bool operator==(const Array& a){
    if(size != a.size) return false;
    for(int i=0; i<size; i++) if(x[i]!=a[i]) return false;
    return true;
  }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a){
  for (int i=0; i<a.size; i++) {
      os << (a.x)[i] << " ";
    }
  return os;
}

#endif // ARRAY_H
