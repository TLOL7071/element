 #include<iostream>
using namespace std;


template <typename type>
class Vector
{
public:
    type *p=NULL;
    int size;
    int capacity;
    void resever(int n);
    Vector ();
    Vector(int n);
    Vector (int n,type m);
    Vector(Vector<type> &a);
    explicit Vector(type *p1,type *p2);
    ~Vector();
    bool empty();
    int Capacity();
    int Size();
    void pop();
    void push(type a);
    type at(int i);
    Vector& operator=(const Vector<type>& vec);
    type & operator[](int i);
    Vector & operator+(const Vector<type>& vec);
    Vector & operator++(int);
    Vector & operator++();
    void free2();
    void insert(int position,type n);
    void insert (int position ,type n,int m);
    void Delete(int n);
    void Delete(int n,int m);
    void swap(Vector<type> &vec);
};
template <typename type>
istream &operator>>(istream & is,Vector<type> &vec);

template <typename type>
ostream & operator<<( ostream & os ,Vector<type> &vec);

template<typename ty>
class cao
{
public :
    cao();
    ty a;
};
