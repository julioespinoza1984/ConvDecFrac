#include "testsuite.h"

#include <QDebug>

namespace convFracDec {

TestSuite::TestSuite(const QString &_testName)
    : QObject(),
      testName(_testName)
{
    qDebug() << "Creando test" << testName;
    testList().push_back(this);
    qDebug() << testList().size() << " tests registrados";
}

TestSuite::~TestSuite()
{
    qDebug() << "Destruyendo test";
}

std::vector<TestSuite *> &TestSuite::testList()
{
    static std::vector<TestSuite*> instance = std::vector<TestSuite*>();
    return instance;
}

} // end namespace

