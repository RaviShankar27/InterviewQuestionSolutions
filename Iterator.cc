// Example program
#include<iostream>
#include<string>
template<class T>
class Vector {
    T* ptr;
    u_int size;
    u_int capacity;
    
public:
    template <class Iter>
    class Iterator {
        private:
            Vector<T> & ref;
        public:
            Iterator(Vector<T>& arg) : ref(arg){}
    };

public :

    Vector(u_int size){}
    Vector(Iterator<Vector<T> > begin, Iterator<Vector<T> > end) {}
    Vector(T* begin, T* end) {}
}
;

int main()
{
    std::string a[10];
    Vector<std::string> temp(a, a+10);
    Vector<std::string>::Iterator<Vector<std::string>> tempi(temp);
    return 0;
}