#include "decimalfraction.h"
#include "decimalfractionexception.h"
#include <sstream>

namespace convFracDec {
namespace entities {

DecimalFraction::DecimalFraction()
    : m_integer(0), m_num(0), m_den(1), m_numComp(0)
{
}

DecimalFraction::DecimalFraction(const DecimalFraction &df)
{
    m_integer = df.getInteger();
    m_num = df.getNum();
    m_den = df.getDen();
    m_numComp = df.getNumComp();
}

DecimalFraction::~DecimalFraction()
{
}

const DecimalFraction& DecimalFraction::operator=(DecimalFraction &df)
{
    if(this != &df) { // previene la auto-asignación
        m_integer = df.getInteger();
        m_num = df.getNum();
        m_den = df.getDen();
        m_numComp = df.getNumComp();
    }
    return *this;
}

bool DecimalFraction::operator==(DecimalFraction &df) const
{
    return m_integer == df.getInteger() && m_num == df.getNum()
            && m_den == df.getDen() && m_numComp == df.getNumComp();
}

bool DecimalFraction::operator!=(DecimalFraction &df) const
{
    return m_integer != df.getInteger() || m_num != df.getNum()
            || m_den != df.getDen() || m_numComp != df.getNumComp();
}

void DecimalFraction::setValueDec(std::string number, std::string periodo)
{
    unsigned long numerador = 0;
    unsigned long entero = 0;
    unsigned long denominador = 1;

    unsigned long ubicacion = number.find(".");
    if(ubicacion > 0 && ubicacion < number.length()) {
        std::string parteEntera = number.substr(0, ubicacion);
        std::istringstream cadenaEntera(parteEntera);
        cadenaEntera >> entero;
        std::string partDecimal = number.substr(ubicacion + 1, number.length() - 1);
        if(periodo == "") {
            unsigned long size = partDecimal.length();
            for(unsigned int i = 0; i < size; ++i) {
                denominador *= 10;
            }
            std::istringstream cadenaDecimal(partDecimal);
            cadenaDecimal >> numerador;
        } else {
            unsigned long ubicacionPeriodo = partDecimal.find(periodo);
            if(ubicacionPeriodo == std::string::npos) {
                std::string s1("El per\u00EDodo ");
                s1 += periodo;
                s1 += " no est\u00E1 en el n\u00FAmero ";
                s1 += number;
                throw DecimalFractionException(s1);
            }
            std::string noPeriodica = partDecimal.substr(0, ubicacionPeriodo);
            if(noPeriodica == "") {
                unsigned long size = periodo.length();
                for(unsigned int i = 0; i < size; ++i) {
                    denominador *= 10;
                }
                --denominador;
                std::istringstream cadenaDecimal(periodo);
                cadenaDecimal >> numerador;
            } else {
                std::string stringTotal = noPeriodica + periodo;
                unsigned long sizeNoPeriodo = noPeriodica.length();
                unsigned long size = stringTotal.length();
                unsigned long denominadorPeriodo = 1;
                for(unsigned int i = 0; i < size; ++i) {
                    denominadorPeriodo *= 10;
                }
                unsigned long denominadorNoPeriodo = 1;
                for(unsigned int i = 0; i < sizeNoPeriodo; ++i) {
                    denominadorNoPeriodo *= 10;
                }
                denominador = denominadorPeriodo - denominadorNoPeriodo;

                unsigned long numPeriodo, numNoPeriodo;
                std::istringstream cadenaPeriodo(stringTotal), cadenaNoPeriodo(noPeriodica);
                cadenaPeriodo >> numPeriodo;
                cadenaNoPeriodo >> numNoPeriodo;
                numerador = numPeriodo - numNoPeriodo;
            }
        }
    } else {
        if(periodo == "") {
            std::istringstream cadenaEntera(number);
            cadenaEntera >> entero;
        } else {
            std::string s1("El per\u00EDodo ");
            s1 += periodo;
            s1 += " no est\u00E1 en el n\u00FAmero ";
            s1 += number;
            throw DecimalFractionException(s1);
        }
    }
    setValue(numerador, denominador, entero);
}

void DecimalFraction::setValue(unsigned long num, unsigned long den, unsigned long integer)
{
    if(0 == den) {
        std::string s1("Valor Inv\u00E1lido. Denominar cero.");
        throw DecimalFractionException(s1);
    }
    unsigned long numInner = num + den * integer;
    unsigned long mcd = getMcd(numInner, den);
    m_num = numInner / mcd;
    m_den = den / mcd;
    m_integer = m_num/m_den;
    m_num %= m_den;
    m_numComp = m_num + m_den * m_integer;
}

void DecimalFraction::setValue(unsigned long num)
{
    m_num = num;
    m_den = 1;
    m_integer = num;
    m_numComp = num;
}

unsigned long DecimalFraction::getInteger() const
{
    return m_integer;
}

unsigned long DecimalFraction::getNum() const
{
    return m_num;
}

unsigned long DecimalFraction::getDen() const
{
    return m_den;
}

unsigned long DecimalFraction::getNumComp() const
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

unsigned long DecimalFraction::getMcd(unsigned long a, unsigned long b)
{
    if(b == 0) {
        return a;
    }
    if(a == 0) {
        return b;
    }

    if(b > 0) {
        unsigned long temp;
        while(a > 0) {
            if(a < b) {
                temp = a;
                a = b;
                b = temp;
            }
            a -= b;
        }
    }
    return b;
}

} // end namespace entities
} // end namespace convFracDec
