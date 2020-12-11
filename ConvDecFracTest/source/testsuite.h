#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>
#include <QString>

#include <vector>

namespace convDecFrac {

class TestSuite : public QObject
{
    Q_OBJECT
public:
    explicit TestSuite(const QString& = "");
    virtual ~TestSuite();

    QString testName;
    static std::vector<TestSuite*>& testList();
};

} // end namespace convDecFrac

#endif // TESTSUITE_H
