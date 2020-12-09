#include <QtTest/QTest>
#include <QDebug>

#include "testsuite.h"

using namespace convFracDec;

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << "Empezando Paquete de Pruebas...";
    qDebug() << "Accediendo a las pruebas desde " << &TestSuite::testList();
    qDebug() <<  TestSuite::testList().size() <<" pruebas detectadas";

    int failedTestsCount = 0;

    for(TestSuite* i : TestSuite::testList()) {
        qDebug() << "Ejecutando Prueba " << i->testName;
        QString filename(i->testName + ".xml");
        int result = QTest::qExec(i, QStringList() << " " << "-o" << filename << "-xunitxml");
        qDebug() << "Resultado de la Prueba " << result;
        if(result != 0) {
            ++failedTestsCount;
        }
    }

    qDebug() << "Paquete de Pruebas Completado - " << QString::number(failedTestsCount) << " fracasos detectados.";

    return failedTestsCount;
}
