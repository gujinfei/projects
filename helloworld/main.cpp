#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp> 
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <string.h>
#include <iostream>


using namespace std;
using namespace boost;

class Test
{
public:
    Test()
    {
        name = "gujinfei";
    }
    void print(){
        cout << "name is " << name << endl;
    }
private:
    string name;
};

template< class T >
class example
{
    boost::shared_ptr< T > p ;
public:
    example()
        : p( boost::make_shared<T>( T() ) )
    {}

    boost::shared_ptr< T >  GetTPtr()
    {
        return p;
    }

    void f_read()
    {
        // boost::shared_ptr< T > p_transient = GetTPtr();
        // if ( p_transient )
        // {
        //     p_transient -> print();
        // }

        boost::shared_ptr< T > p_transient(boost::atomic_load(&p));
        if ( p_transient )
        {
            p_transient -> print();
        }
    }

    void f_write()
    {
        // p.reset(new T) ;

        boost::atomic_store(&p, boost::shared_ptr<T>(new T));
    }
};
example<Test> *ee = new example<Test>();

void thread_func()
{
    while (1)
    {
        ee->f_write();
        this_thread::sleep(posix_time::milliseconds(10));
    }
    
}

void thread_func11()
{
    while (1)
    {
        ee->f_read();
        this_thread::sleep(posix_time::milliseconds(10));
    }
    
}


boost::shared_ptr<int> foo (new int(10));
boost::shared_ptr<int> bar (new int(20));

void thread_func3()
{
    int *tmp = foo.get();
    while (1)
    {
        cout << "The value is " << *tmp << endl;
        this_thread::sleep(posix_time::milliseconds(10));
    }
    
}

int main()
{
    try {
        throw(std::runtime_error("hahaha"));
    } catch (...)
    {
        
    }
    thread th1(thread_func3);  
    thread th2(thread_func3);
    boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(5)); 
    foo.reset();
    th1.join();
    th2.join();
    return 0;
}