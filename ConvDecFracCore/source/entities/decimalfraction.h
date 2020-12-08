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
    void setValue(long, long, long = 0);
    void setValue(long);
    long getInteger() const;
    long getNum() const;
    long getDen() const;
    long getNumComp() const;

    std::string toString() const;

private:
    long getMcd(long, long);

    long m_integer{0};
    long m_num{0};
    long m_den{1};
    long m_numComp{0};
};

} // end namespace entities
} // end namespace convFracDec

#endif // DECIMALFRACTION_H
