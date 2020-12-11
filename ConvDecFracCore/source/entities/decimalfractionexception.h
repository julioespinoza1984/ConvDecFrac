#ifndef DECIMALFRACTION_EXCEPTION_H
#define DECIMALFRACTION_EXCEPTION_H

#include <string>

namespace convDecFrac {
namespace entities {

class DecimalFractionException
{
public:
    DecimalFractionException(std::string msg) : m_msg(msg) {}
    
    std::string getMessage() {
      std::string title = "Error en los datos: ";
      return title + m_msg;
    }
    
private:
    std::string m_msg;
};

} // end namespace entities
} // end namespace convDecFrac

#endif // DECIMALFRACTION_EXCEPTION_H
