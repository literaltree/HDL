#ifndef BUILTINCHIPS
#define BUILTINCHIPS
#include "splashkit.h"
#include <map>
using namespace std;

class chip {
    public:
        string name;
        int numIn;
        map<int,string> inputs;     // size, name
        int numOut;
        map<int,string> outputs;    // size, name        
};

#endif