#include <event.h>
#include <stdio.h>
#include <time.h>
#include "common_func.h"
#include <unordered_map>

#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp> 
#include <boost/shared_ptr.hpp>
#include <string>
#include <iostream>

#include <map>
#include <string>
using namespace std;


class implementation
{
public:
    implementation() {count = 0;}
    ~implementation() { std::cout << this <<" destroying implementation\n"; }
    void do_something() { std::cout << "did something " << count << "\n"; }
public:
    int count;
};

boost::shared_ptr<implementation> sp1;

void thread_func()
{
    boost::shared_ptr<implementation> sp2 = sp1;
    boost::this_thread::sleep(boost::posix_time::seconds(10));   
    sp2->do_something();
    std::cout<<"obj address is "<<sp1.get()<<"\n";
}

void test()
{
    sp1 = boost::make_shared<implementation>();
    sp1->do_something();
    std::cout<<"obj address is "<<sp1.get()<<"\n";
    boost::thread t1(thread_func);
    boost::this_thread::sleep(boost::posix_time::seconds(2));
    sp1.reset();
    sp1 = boost::make_shared<implementation>();
    sp1->count = 2;
    t1.join();
}

boost::shared_ptr<implementation> sp22;
void test1()
{
    boost::shared_ptr<implementation> sp1(new implementation());
    std::cout<<"The Sample now has "<<sp1.use_count()<<" references\n";

    sp22 = sp1;
    std::cout<<"The Sample now has "<<sp22.use_count()<<" references\n";
    
    sp1.reset();
    std::cout<<"After Reset sp1. The Sample now has "<<sp22.use_count()<<" references\n";

    sp22.reset();
    std::cout<<"After Reset sp2.\n";
}

class Mykey
{
public:
    Mykey(string _name, int _age):
        m_strName(_name), m_iAge(_age)
    {
    
    }
    bool operator==(const Mykey &sk) const
    {
        return m_strName == sk.m_strName && m_iAge == sk.m_iAge;
    }
private:
    string m_strName;
    int    m_iAge;
};

class A
{
public:
    A()
    {
        printf("A is constract\n");
    }
    ~A()
    {
        printf("A is descontract\n");
    }

};

class B
{
public:
    B(A &_a):a(_a)
    {
        printf("B is constract\n");
    }
    ~B()
    {
        printf("B is descontract\n");
    }
private:
    A& a;
};

static void
hello(int fd, short event, void *arg)
{
    int a = 5, b= 10;
    printf("hello man:%d\n", Add(a,b));
}

map<string,uint>  map_test;

int main(int argc, const char *argv[]) 
{
    test();

    // map_test.insert(make_pair("gujinfei",1));
    // map_test.erase("duhuaiyu");
    // struct event_base *base;
    // struct timeval tm;
    // struct event evt;

    // evutil_timerclear(&tm);
    // tm.tv_sec = 10;

    // base = event_base_new();
    // //evtimer_set(&evt, hello, NULL);
    // event_set(&evt, -1, EV_PERSIST, hello, NULL);
    // event_base_set(base, &evt);
    // evtimer_add(&evt, &tm);
    // event_base_loop(base, 0);
    return 0;
}
