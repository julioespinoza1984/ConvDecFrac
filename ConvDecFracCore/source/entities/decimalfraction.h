#ifndef DECIMALFRACTION_H
#define DECIMALFRACTION_H

#include <string>

namespace convFracDec {
namespace entities {

class DecimalFraction
{

public:
    DecimalFraction();  // Constructor
    DecimalFraction(const DecimalFraction&); // Constructor de copia
    ~DecimalFraction(); // Destructor

    const DecimalFraction& operator=(DecimalFraction&); // operador de asignación
    bool operator==(DecimalFraction&) const; // operador de igualdad
    bool operator!=(DecimalFraction&) const; // operador de desigualdad

    void setValueDec(std::string, std::string = "");
    void setValue(unsigned long, unsigned long, unsigned long = 0);
    void setValue(unsigned long);
    unsigned long getInteger() const;
    unsigned long getNum() const;
    unsigned long getDen() const;
    unsigned long getNumComp() const;

    std::string toString() const;

private:
    unsigned long getMcd(unsigned long, unsigned long);

    unsigned long m_integer{0};
    unsigned long m_num{0};
    unsigned long m_den{1};
    unsigned long m_numComp{0};
};

} // end namespace entities
} // end namespace convFracDec

#endif // DECIMALFRACTION_H
