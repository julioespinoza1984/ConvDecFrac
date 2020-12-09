/**************************************************
 * Ejercicios tomados de Aritmética de Baldor
 **************************************************/
#include "decimalfractiontest.h"
#include <model/decimalfractionmodel.h>

#include <QtTest>

namespace convFracDec {
namespace model {   // Instance

static DecimalFractionTest instance;

DecimalFractionTest::DecimalFractionTest()
    : TestSuite("DecimalFractionTest")
{
}

} // end namespace model

namespace model { // Test

void DecimalFractionTest::testDecimalFraction185()
{
    DecimalFractionModel model;
    model.setNumber("0.4");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.4 = 2/5"));
    model.setNumber("0.05");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.05 = 1/20"));
    model.setNumber("0.06");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.06 = 3/50"));
    model.setNumber("0.007");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.007 = 7/1000"));
    model.setNumber("0.0008");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.0008 = 1/1250"));
    model.setNumber("0.00009");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.00009 = 9/100000"));
    model.setNumber("0.000004");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.000004 = 1/250000"));
    model.setNumber("0.018");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.018 = 9/500"));
    model.setNumber("1.0036");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("1.0036 = 2509/2500 = 1+9/2500"));
    model.setNumber("2.00048");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("2.00048 = 12503/6250 = 2+3/6250"));
    model.setNumber("3.000058");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("3.000058 = 1500029/500000 = 3+29/500000"));
    model.setNumber("4.00124");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("4.00124 = 100031/25000 = 4+31/25000"));
    model.setNumber("0.03215");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.03215 = 643/20000"));
    model.setNumber("0.198");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.198 = 99/500"));
    model.setNumber("0.3546");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.3546 = 1773/5000"));
    model.setNumber("0.72865");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.72865 = 14573/20000"));
    model.setNumber("1.186");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("1.186 = 593/500 = 1+93/500"));
    model.setNumber("3.004");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("3.004 = 751/250 = 3+1/250"));
    model.setNumber("5.0182");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("5.0182 = 25091/5000 = 5+91/5000"));
    model.setNumber("7.14684");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("7.14684 = 178671/25000 = 7+3671/25000"));
}

void DecimalFractionTest::testDecimalFraction186()
{
    DecimalFractionModel model;
    model.setNumber("0.33");
    model.setPeriod("3");
    QCOMPARE(model.result(), QString("0.33 = 1/3"));
    model.setNumber("0.44");
    model.setPeriod("4");
    QCOMPARE(model.result(), QString("0.44 = 4/9"));
    model.setNumber("0.66");
    model.setPeriod("6");
    QCOMPARE(model.result(), QString("0.66 = 2/3"));
    model.setNumber("0.1212");
    model.setPeriod("12");
    QCOMPARE(model.result(), QString("0.1212 = 4/33"));
    model.setNumber("0.1515");
    model.setPeriod("15");
    QCOMPARE(model.result(), QString("0.1515 = 5/33"));
    model.setNumber("0.1818");
    model.setPeriod("18");
    QCOMPARE(model.result(), QString("0.1818 = 2/11"));
    model.setNumber("0.2020");
    model.setPeriod("20");
    QCOMPARE(model.result(), QString("0.2020 = 20/99"));
    model.setNumber("0.8181");
    model.setPeriod("81");
    QCOMPARE(model.result(), QString("0.8181 = 9/11"));
    model.setNumber("0.123123");
    model.setPeriod("123");
    QCOMPARE(model.result(), QString("0.123123 = 41/333"));
    model.setNumber("0.156156");
    model.setPeriod("156");
    QCOMPARE(model.result(), QString("0.156156 = 52/333"));
    model.setNumber("0.143143");
    model.setPeriod("143");
    QCOMPARE(model.result(), QString("0.143143 = 143/999"));
    model.setNumber("0.18961896");
    model.setPeriod("1896");
    QCOMPARE(model.result(), QString("0.18961896 = 632/3333"));
    model.setNumber("0.003003");
    model.setPeriod("003");
    QCOMPARE(model.result(), QString("0.003003 = 1/333"));
    model.setNumber("1.0505");
    model.setPeriod("05");
    QCOMPARE(model.result(), QString("1.0505 = 104/99 = 1+5/99"));
    model.setNumber("1.7272");
    model.setPeriod("72");
    QCOMPARE(model.result(), QString("1.7272 = 19/11 = 1+8/11"));
    model.setNumber("2.009009");
    model.setPeriod("009");
    QCOMPARE(model.result(), QString("2.009009 = 223/111 = 2+1/111"));
    model.setNumber("3.00450045");
    model.setPeriod("0045");
    QCOMPARE(model.result(), QString("3.00450045 = 3338/1111 = 3+5/1111"));
    model.setNumber("4.186186");
    model.setPeriod("186");
    QCOMPARE(model.result(), QString("4.186186 = 1394/333 = 4+62/333"));
    model.setNumber("5.018018");
    model.setPeriod("018");
    QCOMPARE(model.result(), QString("5.018018 = 557/111 = 5+2/111"));
    model.setNumber("6.00060006");
    model.setPeriod("0006");
    QCOMPARE(model.result(), QString("6.00060006 = 20000/3333 = 6+2/3333"));
}

void DecimalFractionTest::testDecimalFraction187()
{
    DecimalFractionModel model;
    model.setNumber("0.355");
    model.setPeriod("55");
    QCOMPARE(model.result(), QString("0.355 = 16/45"));
    model.setNumber("0.644");
    model.setPeriod("44");
    QCOMPARE(model.result(), QString("0.644 = 29/45"));
    model.setNumber("0.988");
    model.setPeriod("88");
    QCOMPARE(model.result(), QString("0.988 = 89/90"));
    model.setNumber("0.133");
    model.setPeriod("33");
    QCOMPARE(model.result(), QString("0.133 = 2/15"));
    model.setNumber("0.6655");
    model.setPeriod("55");
    QCOMPARE(model.result(), QString("0.6655 = 599/900"));
    model.setNumber("0.1244");
    model.setPeriod("44");
    QCOMPARE(model.result(), QString("0.1244 = 28/225"));
    model.setNumber("0.3622");
    model.setPeriod("2");
    QCOMPARE(model.result(), QString("0.3622 = 163/450"));
    model.setNumber("0.1844");
    model.setPeriod("4");
    QCOMPARE(model.result(), QString("0.1844 = 83/450"));
    model.setNumber("0.2366");
    model.setPeriod("6");
    QCOMPARE(model.result(), QString("0.2366 = 71/300"));
    model.setNumber("0.51919");
    model.setPeriod("19");
    QCOMPARE(model.result(), QString("0.51919 = 257/495"));
    model.setNumber("0.012323");
    model.setPeriod("23");
    QCOMPARE(model.result(), QString("0.012323 = 61/4950"));
    model.setNumber("0.0011818");
    model.setPeriod("18");
    QCOMPARE(model.result(), QString("0.0011818 = 13/11000"));
    model.setNumber("0.124356356");
    model.setPeriod("356");
    QCOMPARE(model.result(), QString("0.124356356 = 15529/124875"));
    model.setNumber("0.451201201");
    model.setPeriod("201");
    QCOMPARE(model.result(), QString("0.451201201 = 601/1332"));
    model.setNumber("1.033");
    model.setPeriod("3");
    QCOMPARE(model.result(), QString("1.033 = 31/30 = 1+1/30"));
    model.setNumber("1.766");
    model.setPeriod("6");
    QCOMPARE(model.result(), QString("1.766 = 53/30 = 1+23/30"));
    model.setNumber("1.031515");
    model.setPeriod("15");
    QCOMPARE(model.result(), QString("1.031515 = 851/825 = 1+26/825"));
    model.setNumber("2.014545");
    model.setPeriod("45");
    QCOMPARE(model.result(), QString("2.014545 = 554/275 = 2+4/275"));
    model.setNumber("3.6112112");
    model.setPeriod("112");
    QCOMPARE(model.result(), QString("3.6112112 = 18038/4995 = 3+3053/4995"));
    model.setNumber("4.09912912");
    model.setPeriod("912");
    QCOMPARE(model.result(), QString("4.09912912 = 136501/33300 = 4+3301/33300"));
}

void DecimalFractionTest::testDecimalFraction188()
{
    DecimalFractionModel model;
    model.setNumber("0.8");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.8 = 4/5"));
    model.setNumber("0.185");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.185 = 37/200"));
    model.setNumber("0.4646");
    model.setPeriod("46");
    QCOMPARE(model.result(), QString("0.4646 = 46/99"));
    model.setNumber("0.3636");
    model.setPeriod("36");
    QCOMPARE(model.result(), QString("0.3636 = 4/11"));
    model.setNumber("0.544");
    model.setPeriod("4");
    QCOMPARE(model.result(), QString("0.544 = 49/90"));
    model.setNumber("0.32");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.32 = 8/25"));
    model.setNumber("3.55");
    model.setPeriod("5");
    QCOMPARE(model.result(), QString("3.55 = 32/9 = 3+5/9"));
    model.setNumber("0.143636");
    model.setPeriod("36");
    QCOMPARE(model.result(), QString("0.143636 = 79/550"));
    model.setNumber("0.17333");
    model.setPeriod("3");
    QCOMPARE(model.result(), QString("0.17333 = 13/75"));
    model.setNumber("0.146");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.146 = 73/500"));
    model.setNumber("0.00540054");
    model.setPeriod("0054");
    QCOMPARE(model.result(), QString("0.00540054 = 6/1111"));
    model.setNumber("0.1861515");
    model.setPeriod("15");
    QCOMPARE(model.result(), QString("0.1861515 = 6143/33000"));
    model.setNumber("0.02");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.02 = 1/50"));
    model.setNumber("0.0036");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.0036 = 9/2500"));
    model.setNumber("0.144144");
    model.setPeriod("144");
    QCOMPARE(model.result(), QString("0.144144 = 16/111"));
    model.setNumber("0.87611");
    model.setPeriod("1");
    QCOMPARE(model.result(), QString("0.87611 = 1577/1800"));
    model.setNumber("0.15169169");
    model.setPeriod("169");
    QCOMPARE(model.result(), QString("0.15169169 = 7577/49950"));
    model.setNumber("0.00564");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.00564 = 141/25000"));
    model.setNumber("6.018018");
    model.setPeriod("018");
    QCOMPARE(model.result(), QString("6.018018 = 668/111 = 6+2/111"));
    model.setNumber("5.1515");
    model.setPeriod("15");
    QCOMPARE(model.result(), QString("5.1515 = 170/33 = 5+5/33"));
    model.setNumber("0.008");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.008 = 1/125"));
    model.setNumber("3.05");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("3.05 = 61/20 = 3+1/20"));
    model.setNumber("0.060060");
    model.setPeriod("060");
    QCOMPARE(model.result(), QString("0.060060 = 20/333"));
    model.setNumber("4.1344");
    model.setPeriod("4");
    QCOMPARE(model.result(), QString("4.1344 = 3721/900 = 4+121/900"));
    model.setNumber("0.0001515");
    model.setPeriod("15");
    QCOMPARE(model.result(), QString("0.0001515 = 1/6600"));
    model.setNumber("0.0000014");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.0000014 = 7/5000000"));
    model.setNumber("8.03210321");
    model.setPeriod("0321");
    QCOMPARE(model.result(), QString("8.03210321 = 26771/3333 = 8+107/3333"));
    model.setNumber("0.086363");
    model.setPeriod("63");
    QCOMPARE(model.result(), QString("0.086363 = 19/220"));
    model.setNumber("6.891616");
    model.setPeriod("16");
    QCOMPARE(model.result(), QString("6.891616 = 68227/9900 = 6+8827/9900"));
    model.setNumber("18.0326");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("18.0326 = 90163/5000 = 18+163/5000"));
    model.setNumber("14.66");
    model.setPeriod("6");
    QCOMPARE(model.result(), QString("14.66 = 44/3 = 14+2/3"));
    model.setNumber("0.096055");
    model.setPeriod("5");
    QCOMPARE(model.result(), QString("0.096055 = 1729/18000"));
    model.setNumber("15.075");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("15.075 = 603/40 = 15+3/40"));
    model.setNumber("0.0885608856");
    model.setPeriod("08856");
    QCOMPARE(model.result(), QString("0.0885608856 = 24/271"));
    model.setNumber("0.1868");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.1868 = 467/2500"));
    model.setNumber("0.01369346934");
    model.setPeriod("6934");
    QCOMPARE(model.result(), QString("0.01369346934 = 136921/9999000"));
    model.setNumber("0.000018");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.000018 = 9/500000"));
    model.setNumber("0.000000864");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("0.000000864 = 27/31250000"));
    model.setNumber("5.165165");
    model.setPeriod("165");
    QCOMPARE(model.result(), QString("5.165165 = 1720/333 = 5+55/333"));
    model.setNumber("0.894894");
    model.setPeriod("894");
    QCOMPARE(model.result(), QString("0.894894 = 298/333"));
    model.setNumber("0.056893893");
    model.setPeriod("893");
    QCOMPARE(model.result(), QString("0.056893893 = 56837/999000"));
    model.setNumber("9.00360036");
    model.setPeriod("0036");
    QCOMPARE(model.result(), QString("9.00360036 = 10003/1111 = 9+4/1111"));
    model.setNumber("0.54323323");
    model.setPeriod("323");
    QCOMPARE(model.result(), QString("0.54323323 = 54269/99900"));
    model.setNumber("21.006");
    model.setPeriod("-");
    QCOMPARE(model.result(), QString("21.006 = 10503/500 = 21+3/500"));
    model.setNumber("4.0088300883");
    model.setPeriod("00883");
    QCOMPARE(model.result(), QString("4.0088300883 = 400879/99999 = 4+883/99999"));
}

} // end namespace model
} // end namespace convFracDec
