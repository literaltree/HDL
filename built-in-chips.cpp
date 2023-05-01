#include "built-in-chips.h"
#include <map>
#include "splashkit.h"

chip chip_init(string name, int numIn, map<int,string> inputs, int numOut, map<int,string> outputs) {
    chip newHDL;
    newHDL.name = name;
    newHDL.numIn = numIn;
    newHDL.inputs = inputs;
    newHDL.numOut = numOut;
    newHDL.outputs = outputs;
}