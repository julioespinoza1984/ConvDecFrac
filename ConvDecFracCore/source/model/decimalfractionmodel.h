#ifndef DECIMALFRACTIONMODEL_H
#define DECIMALFRACTIONMODEL_H

#include <QObject>

#include "convdecfraccore_global.h"

namespace convFracDec {
namespace model {

class CONVDECFRACCORESHARED_EXPORT DecimalFractionModel : public QObject
{
    Q_OBJECT
public:
    explicit DecimalFractionModel(QObject *parent = nullptr);

signals:

public slots:
};

} // end namespace model
} // end namespace convFracDec

#endif // DECIMALFRACTIONMODEL_H
