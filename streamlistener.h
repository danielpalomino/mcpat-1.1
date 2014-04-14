#include <iosfwd>
#include <string>
#include "processor.h"

class StreamListener
{
public:
    StreamListener(std::istream &in, Processor &proc, int verbosity = 2);

    void simulateEnergyConsumption();
private:
    
    /**
     * Reads a XML component spec from `in' into `filebuf'. Returns true if
     * successful, else false (typically if EOF was reached).
     */
    bool readXmlRequest();

    /**
     * Recomputes energy for the statistics of the latest request.
     */
    void computeEnergy();

    /**
     * Displays the computed data.
     */
    void displayEnergy();


    /* Class attributes */

    std::istream &in;
    
    Processor &proc;
    std::string filebuf;
    int verbosity;

    /**
     * End marker of a (valid) XML component spec.
     */
    static const std::string endtag;
};

