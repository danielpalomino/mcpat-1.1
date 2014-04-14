#include "streamlistener.h"
#include "XML_Parse.h"

#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory>

Streamlistener::Streamlistener(std::istream& in, int plevel)
 : in(in), plevel(plevel)
{
    if (!in)
        throw std::runtime_error(std::string("StreamListener: invalid input stream"));
    in.unsetf(std::ios_base::skipws);
}

void
Streamlistener::computeEnergy(Processor &proc)
{
    std::string filebuf;
    std::copy(std::istream_iterator<char>(in), std::istream_iterator<char>(), std::back_inserter(filebuf));

    std::auto_ptr<ParseXML> xml(new ParseXML);
    xml->parse(filebuf);
    proc.computeEnergy(xml.get(), true);	// thermal design power
    proc.computeEnergy(xml.get(), false);	// runtime dynamic
    proc.collectEnergy();
    proc.displayEnergy(2, plevel);
}
