#ifdef USE_BOOST
#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp> 
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/enable_shared_from_this.hpp>
using namespace boost;
#endif
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec {1,2,3};
    for (auto &i : vec)
    {
        cout << i << endl;
    }
    
    return 0;
}