#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>
#include <QString>

#include <vector>

namespace convFracDec {

class TestSuite : public QObject
{
    Q_OBJECT
public:
    explicit TestSuite(const QString& = "");
    virtual ~TestSuite();

    QString testName;
    static std::vector<TestSuite*>& testList();
};

} // end namespace convFracDec

#endif // TESTSUITE_H
