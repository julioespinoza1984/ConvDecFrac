#ifndef DECIMALFRACTION_TEST_H
#define DECIMALFRACTION_TEST_H

#include <testsuite.h>

namespace convFracDec {
namespace model {

class DecimalFractionTest : public TestSuite
{
    Q_OBJECT

public:
    DecimalFractionTest();

private slots:
    void testDecimalFraction185();
    void testDecimalFraction186();
    void testDecimalFraction187();
    void testDecimalFraction188();
};

} // end namespace model
} // end namespace convFracDec

#endif // DECIMALFRACTION_TEST_H
