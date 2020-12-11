#ifndef DECIMALFRACTIONMODEL_H
#define DECIMALFRACTIONMODEL_H

#include <QObject>

#include "convdecfraccore_global.h"
#include "../entities/decimalfraction.h"

namespace convDecFrac {
namespace model {

class CONVDECFRACCORESHARED_EXPORT DecimalFractionModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString period WRITE setPeriod NOTIFY periodChanged)
    Q_PROPERTY(QString result READ result)
public:
    void setNumber(const QString&);
    void setPeriod(const QString&);
    QString result() const;
signals:
    void numberChanged();
    void periodChanged();

private:
    QString m_number, m_result;
    convDecFrac::entities::DecimalFraction m_decimalFraction;
};

} // end namespace model
} // end namespace convDecFrac

#endif // DECIMALFRACTIONMODEL_H
