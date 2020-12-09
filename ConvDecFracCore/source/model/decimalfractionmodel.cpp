#include "decimalfractionmodel.h"
#include "../entities/decimalfractionexception.h"

#include <string>
#include <QDebug>

namespace convFracDec {
namespace model {

void DecimalFractionModel::setNumber(const QString &number)
{
    qDebug() << "_numero = " << number;
    if(number != m_number) {
        m_number = number;
        qDebug() << "m_numero: " << m_number;
        emit numberChanged();
    }
}

void DecimalFractionModel::setPeriod(const QString &period)
{
    qDebug() << "periodo =" << period;
    if(!m_number.isNull() && !m_number.isEmpty() && !period.isNull()) {
        qDebug() << "m_number =" << m_number << "periodo =" << period;
        std::string periodStr;
        if(period != "-") {
            periodStr = period.toStdString();
        }
        try {
            m_decimalFraction.setValueDec(m_number.toStdString(), periodStr);
            m_result = m_number;
            m_result += " = ";
            m_result += QString::fromStdString(m_decimalFraction.toString());
        } catch (convFracDec::entities::DecimalFractionException &e) {
            m_result = QString::fromStdString(e.getMessage());
        }
    }
    qDebug() << "m_result =" << m_result;
    emit periodChanged();
}

QString DecimalFractionModel::result() const
{
    return m_result;
}


} // end namespace model
} // end namespace convFracDec
