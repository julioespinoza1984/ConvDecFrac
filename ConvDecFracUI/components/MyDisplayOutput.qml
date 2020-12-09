import QtQuick 2.12
import assets 1.0

BorderImage {
    id: image;

    property alias result: operationText.text;

    source: "qrc:/assets/display.png";
    border {
        left: Style.myDisplayOutputBorder;
        top: Style.myDisplayOutputBorder;
        right: Style.myDisplayOutputBorder;
        bottom: Style.myDisplayOutputBorder;
    }

    Text {
        id: operationText;
        font.bold: Style.myDisplayOutputDisplayTextBold;
        font.pixelSize: parent.height * 0.25;
        color: Style.myDisplayOutputDisplayTextColor;
        smooth: true;
        anchors {
            left: parent.left;
            leftMargin: Style.myDisplayOutputDisplayTextLeftMargin;
        }
        width: parent.width;
        wrapMode: Text.WordWrap;
    }
}
