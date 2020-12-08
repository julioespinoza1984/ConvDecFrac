#include "decimalfraction.h"
#include "decimalfractionexception.h"
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;

namespace convFracDec {
namespace entities {

DecimalFraction::DecimalFraction()
    : m_integer(0), m_num(0), m_den(1), m_numComp(0)
{
    cout << "Constructor de DecimalFraction " << toString() << endl;
}

DecimalFraction::DecimalFraction(const DecimalFraction &df)
{
    cout << "Constructor de Copia DecimalFraction: " << df.toString() << endl;
    m_integer = df.getInteger();
    m_num = df.getNum();
    m_den = df.getDen();
    m_numComp = df.getNumComp();
}

DecimalFraction::~DecimalFraction()
{
    cout << "Destructor de DecimalFraction " << toString() << endl;
}

const DecimalFraction& DecimalFraction::operator=(DecimalFraction &df)
{
    if(this != &df) { // previene la auto-asignación
    cout << "Operador de asignación DecimalFraction: " << df.toString() << endl;
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
    long numerador = 0;
    long entero = 0;
    long denominador = 1;

//    cout << "numero: " << numero << "\tperiodo: " << periodo << endl;
    unsigned int ubicacion = number.find(".");
    //    cout << "ubicacion: " << ubicacion << endl;
    if(ubicacion > 0 && ubicacion < number.length()) {
        std::string parteEntera = number.substr(0, ubicacion);
        std::istringstream cadenaEntera(parteEntera);
        cadenaEntera >> entero;
//        cout << "parteEntera: " << parteEntera;
        std::string partDecimal = number.substr(ubicacion + 1, number.length() - 1);
//        cout << "\tpartDecimal: " << partDecimal << endl;
        if(periodo == "") {
            unsigned int size = partDecimal.length();
            for(unsigned int i = 0; i < size; ++i) denominador *= 10;
            std::istringstream cadenaDecimal(partDecimal);
            cadenaDecimal >> numerador;
        } else {
            unsigned int ubicacionPeriodo = partDecimal.find(periodo);
//            cout << "ubicacionPeriodo: " << ubicacionPeriodo << endl;
            if(ubicacionPeriodo == std::string::npos) {
                std::string s1("El per\u00EDodo ");
                s1 += periodo;
                s1 += " no est\u00E1 en el n\u00FAmero ";
                s1 += number;
                throw DecimalFractionException(s1);
            }
            std::string noPeriodica = partDecimal.substr(0, ubicacionPeriodo);
//            cout << "noPeriodica: " << noPeriodica << endl;
            if(noPeriodica == "") {
//                cout << "noPeriodica == "" es true" << endl;
                unsigned int size = periodo.length();
                for(unsigned int i = 0; i < size; ++i) denominador *= 10;
                --denominador;
                std::istringstream cadenaDecimal(periodo);
                cadenaDecimal >> numerador;
            } else {
//                cout << "noPeriodica == "" es false" << endl;
//                cout << "\tNoPeriodo: " << noPeriodica;
                std::string stringTotal = noPeriodica + periodo;
                unsigned int sizeNoPeriodo = noPeriodica.length();
                unsigned int size = stringTotal.length();
                long denominadorPeriodo = 1;
                for(unsigned int i = 0; i < size; ++i) denominadorPeriodo *= 10;
                long denominadorNoPeriodo = 1;
                for(unsigned int i = 0; i < sizeNoPeriodo; ++i) denominadorNoPeriodo *= 10;
                denominador = denominadorPeriodo - denominadorNoPeriodo;

                long numPeriodo, numNoPeriodo;
                std::istringstream cadenaPeriodo(stringTotal), cadenaNoPeriodo(noPeriodica);
                cadenaPeriodo >> numPeriodo;
                cadenaNoPeriodo >> numNoPeriodo;
                numerador = numPeriodo - numNoPeriodo;
            }
//            cout << "\tperiodo: " << periodo;

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
//    cout << "\tnum: " << numerador;
//    cout << "\tden: " << denominador << endl;
    setValue(numerador, denominador, entero);
}

void DecimalFraction::setValue(long num, long den, long integer)
{
    if(0 == den) {
        std::string s1("Valor Inv\u00E1lido. Denominar cero.");
        throw DecimalFractionException(s1);
    }
    //    cout << "\n_num: " << _num << endl;
    //    cout << "_den: " << _den << endl;
    //    cout << "_partEntera: " << _partEntera << endl;
    long numInner = num + den * integer;
    //    cout << "numInner: " << numInner << endl;
    long mcd = getMcd(numInner >= 0 ? numInner : -numInner, den > 0 ? den : -den);
    //    cout << "mcd: " << mcd << endl;
    m_num = numInner / mcd;
    //    cout << "num: " << num << endl;
    m_den = den / mcd;
    //    cout << "den: " << den << endl;
    m_integer = m_num/m_den;
    //    cout << "partEntera: " << partEntera << endl;
    m_num %= m_den;
    //    cout << "num: " << num << endl;
    m_numComp = m_num + m_den * m_integer;
    //    cout << "numComp: " << numComp << endl;
}

void DecimalFraction::setValue(long num)
{
    m_num = num;
    m_den = 1;
    m_integer = num;
    m_numComp = num;
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
