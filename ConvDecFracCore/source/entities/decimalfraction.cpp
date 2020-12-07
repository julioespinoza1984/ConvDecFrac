#include "decimalfraction.h"
#include <sstream>

namespace convFracDec {
namespace entities {

DecimalFraction::DecimalFraction()
    : m_integer(0), m_num(0), m_den(1), m_numComp(0)
{
//    cout << "Constructor de DecimalFraction" << endl;
}

DecimalFraction::DecimalFraction(const DecimalFraction &df)
{
    //    cout << "Constructor de Copia DecimalFraction: " << df.toString() << endl;
    m_integer = df.getInteger();
    m_num = df.getNum();
    m_den = df.getDen();
    m_numComp = df.getNumComp();
}

DecimalFraction::~DecimalFraction()
{
//    cout << "Destructor de DecimalFraction " << toString() << endl;
}

const DecimalFraction &DecimalFraction::operator=(DecimalFraction &df)
{
    if(this != &df) {
//    cout << "Operador de asignación DecimalFraction: " << df.toString() << endl;
            m_integer = df.getInteger();
            m_num = df.getNum();
            m_den = df.getDen();
            m_numComp = df.getNumComp();
    }
    return *this;
}

void DecimalFraction::setValueDec(std::string, std::string)
{

}

void DecimalFraction::setValue(long, long, long)
{

}

void DecimalFraction::setValue(long)
{

}

long DecimalFraction::getInteger() const
{
    return m_integer;
}

long DecimalFraction::getNum() const
{
    return m_num;
}

long DecimalFraction::getDen() const
{
    return m_den;
}

long DecimalFraction::getNumComp() const
{
    return m_numComp;
}

std::string DecimalFraction::toString() const
{
    std::ostringstream oss;
    std::string s("/");
    if(m_integer == 0) {
        oss << m_num;
        if(m_den != 1) {
            oss << s << m_den;
        }
    } else {
        std::string s1(" = ");
        oss << m_numComp;
        if(m_den != 1) {
            oss << s << m_den;
        }
        oss << s1 << m_integer;
        if(m_num != 0) {
            std::string s2("+");
            oss << s2 << m_num;
            if(m_den != 1) {
                oss << s << m_den;
            }
        }
    }
    return oss.str();
}

long DecimalFraction::getMcd(long a, long b)
{
    //cout << "Calculando Mcd(" << a << ", " << b << ")" << endl;
    if(b == 0) {
        return a;
    }
    if(a == 0) {
        return b;
    }

    //    cout << "Calculando Mcd(" << a << ", " << b << ")" << endl;
    if(b > 0) {
        long temp;
        while(a > 0) {
            if(a < b) {
                temp = a;
                a = b;
                b = temp;
            }
            a -= b;
        }
    }
    //cout << "Calculado Mcd(" << a << ", " << b << ") = " << b << endl;
    return b;
}

} // end namespace entities
} // end namespace convFracDec
