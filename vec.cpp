#include<iostream>
#include <algorithm>
#include<vector.h>
using namespace std;

template <typename type>
    Vector<type> :: Vector ( )             //���캯��1
    {
        size=0;
        capacity=15;
        p=new type[capacity]();
    }
template <typename type>
    Vector<type>::Vector(int n)           //���캯��2
    {
        size=0;
        p=new type[n*2](0);
        capacity=n*2;
    }
template <typename type>                //���캯��3
void Vector<type>:: resever(int n)
{
    if(n<=this->capacity)
        return;
    this->capacity=n;
}
template <typename type>                //���캯��4
Vector<type> :: Vector (int n,type m)
    {
        p=new type[n*2]();
        //memset(p,)
        fill(p,p+n,m);
        capacity =n*2;
        size=n;
    }
template<typename type>                 //�������캯��6
Vector<type>:: Vector(Vector<type> &a)
{
    p=new type[a.size*2]();
    copy(a.p,a.p+a.size,p);
    size=a.size;
    capacity=a.size*2;
}
template<typename type>                 //���캯��7
Vector<type>::Vector(type *p1,type *p2)
{

    if ((p2-p1)>=0)
    {
        p=new type [(p2-p1)*2]();
        size=p2-p1;
        capacity = (p2-p1)*2;
        for(int i=0;i<p2-p1;i++)
            p[i]=p1[i];
    }
    else
    {
        p=new type [(p1-p2)*2]();
        capacity = (p1-p2)*2;
        size=p1-p2;
        for (int i=0;i<p1-p2;i++)
        {
            p[i]=p2[i];
        }
    }

}
template<typename type>                 //��������
Vector<type>::~Vector()
    {
        delete []p;
    }
template<typename type>                 //�ж�vector�Ƿ�Ϊ��
bool Vector<type>::  empty()
    {
        if (size==0)
            return true;
        else
            return false;
    }
template<typename type>                 //����capacity
int Vector<type>::
    Capacity()
    {
        return capacity;
    }
template<typename type>                 //���ص�ǰ�洢����
int Vector<type>:: Size()
    {
        return this ->size;
    }
template<typename type>                 //ɾ�����һ��Ԫ������ǰvectorΪ�գ���ӡerror
void Vector<type>:: pop()
    {
        if(this->size>=1)
        {
            this->size--;
        }
        else
        {
            cout<<"error";
        }
    }
template<typename type>                 //��˳�����Ԫ�أ�
void Vector<type>:: push(type a)
    {
        if(this ->size==this->capacity)
        {
            capacity*=2;
            type *tempt=new type[this->capacity];
            for(int i=0;i<this->size;i++)
            {
                tempt[i]=this->p[i];
            }
            delete []p;
            p=tempt;
        }
        *(p+this->size)=a;
        this->size++;
    }
template<typename type>                 //����vector���±�λ��Ԫ�أ����������ޣ����� 0X16
type Vector<type>:: at(int i)
    {
        if(i>=size)
        {
            return 0x16;
        }
        return p[i-1];
    }
template<typename type>                 //��=��������أ�ʵ��vec1=vec2��ֵ
Vector<type>& Vector<type>::  operator=(const Vector<type>& vec)
    {
        if(this == &vec)
            return *this;
        type* temp = new type[vec.capacity];
        for(int i=0;i<vec.size;++i){
            temp[i] = vec.p[i];
        }
        delete [] this->p;
        p = temp;
        this->size = vec.size;
        this->capacity = vec.capacity;
        return *this;
    }
template<typename type>             //��[]���أ�ʵ��vec[i]���±�Ϊi
type & Vector<type>:: operator[](int i)
    {
        return this->p[i];
    }
template<typename type>             //��+���أ�ʵ��vec1+vec2����vec3�����и�Ԫ��Ϊ��Ӻ���
Vector<type> & Vector<type>:: operator+(const Vector<type>& vec)
    {
        if(this->capacity<vec.size)
        {
            this->capacity=vec.capacity;
            type *tempt=new type[this->capacity]();
            for(int i=0;i<this->size;i++)
            {
                tempt[i]=this->p[i];
            }
            delete []this->p;
            p=tempt;
            this->size=vec.size;
        }
        for(int i=0;i<vec.size;i++)
        {
            this->p[i]+=vec.p[i];
        }
        return *this;

        //this-size=(this->size>vec.size ? this->size:vec.size);
        //this-capacity=(this->capacity>vec.capacity ? this->capacity:vec.capacity);

    }
template<typename type>                     //�Ժ�׺�����++���أ�ʵ�ַ���++ǰ�Ķ���֮���ٶԲ�������ȫ��Ԫ�ؼ�1
Vector<type> & Vector<type>:: operator++(int)//��Ӽ�
    {
        static Vector<type> tp(*this);

        for(int i=0;i<this->size;i++)
        {
            this->p[i]++;
        }
        return tp;
    }
template<typename type>                     //��ǰ׺�����++���أ�ʵ���ȶԲ�������ȫ��Ԫ�ؼ�1���󷵻�++��Ķ���
Vector<type> &Vector<type>:: operator++()//ǰ�Ӽ�
    {
        for(int i=0;i<this->size;i++)
        {
            this->p[i]++;
        }
        return *this;
    }
template<typename type>                     //ͨ������vector.size��С�����飬��ԭ����Ǩ�ƣ���delete��ԭ������Ŀռ�
void Vector<type>:: free2()                 //��ɶ�size��ռ�����
    {
        type *temp=new type (this->size);
        for(int i=0;i<this->size;i++)
        {
            temp[i]=this->p[i];
        }
        delete []this->p;
        this->p=temp;

    }
template<typename type>                 //��ָ��λ��position����nԪ��
void Vector<type>:: insert(int position,type n)
    {
        if(this ->size==this->capacity)
        {
            capacity*=2;
            type *tempt=new type[this->capacity];
            for(int i=0;i<this->size;i++)
            {
                tempt[i]=this->p[i];
            }
            delete []p;
            p=tempt;
        }
        for(int i=this->size;i>position;i--)
            {
                this->p[i]=this->p[i-1];
            }
        this->p[position]=n;
        this->size++;
    }
template<typename type>                     //��positionλ�ò���m��nԪ��
void Vector<type>:: insert (int position ,type n,int m)
    {
        if((this ->size+m)>=this->capacity)
        {
            do
            {
                capacity*=2;
            }while((this ->size+m)>=this->capacity);
            type *tempt=new type[this->capacity];
            for(int i=0;i<this->size;i++)
            {
                tempt[i]=this->p[i];
            }
            delete []p;
            p=tempt;
        }
        for(int i=this->size+m-1;i>=position+m;i--)
            {
                this->p[i]=this->p[i-m];
            }
        for(int i=position ;i<position+m;i++)
            this->p[i]=n;
        this->size+=m;

    }
template<typename type>             //ɾȥn�±�����Ԫ��
void Vector<type>:: Delete(int n)
    {
        this->size--;
        for(int i=n;i<this->size;i++)
        {
            this->p[i]=this->p[i+1];
        }
        this->p[size]=0;
    }
template<typename type>                 //ɾȥnС�괦�����n��Ԫ��
void Vector<type>:: Delete(int n,int m)
    {//[n,m]����
        for(int i=0;i<this->size-m-1;i++)
            this->p[n+i]=this->p[m+i+1];

        for(int i=this->size-1;i>=this->size-1-m+n;i--)
        {
            this->p[i]=0;
        }
        this->size-=m-n+1;

    }
template<typename type>            //ʵ������vector�����ݻ���
void Vector<type>:: swap(Vector<type> &vec)
    {
        type *t=this->p;
        this->p=vec.p;
        vec.p=t;
        int tt;
        tt=this->size;
        this->size=vec.size;
        vec.size=tt;
        tt=this->capacity;
        this->capacity=vec.capacity;
        vec.capacity=tt;
    }
template <typename type>            //��<<���أ�ʹcout�����vector�������
ostream & operator<<( ostream & os ,Vector<type> &vec)
{
    for(int i=0;i<vec.size;i++)
    {
        cout <<vec.p[i];
        cout<<' ';
    }
    return os;
}
template <typename type>           //��>>���أ���ʹ��cin���vector����������
istream &operator>>(istream & is,Vector<type> &vec)
{
    char c;
    for(int i=0; ;i++)
    {
        is>>vec.p[i];
        vec.size++;
        scanf("%c",&c);
        //cout <<c;
        if(c=='\n')
            return is;
    }
}