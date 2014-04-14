#include <iosfwd>
#include "processor.h"

class Streamlistener
{
public:
    Streamlistener(std::istream &in, int plevel = 2);

    void computeEnergy(Processor &p);
private:
    std::istream &in;
    int plevel;
};

