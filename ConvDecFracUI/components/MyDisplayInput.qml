import QtQuick 2.12
import assets 1.0

BorderImage {
    id: image;

    property alias text: displayText.text;

    source: "qrc:/assets/display.png";
    opacity: Style.myDisplayInputOpacity;
    border {
        left: Style.myDisplayInputBorder;
        top: Style.myDisplayInputBorder;
        right: Style.myDisplayInputBorder;
        bottom: Style.myDisplayInputBorder;
    }

    Text {
        id: displayText;
        anchors {
            right: parent.right;
            verticalCenter: parent.verticalCenter;
            verticalCenterOffset: Style.myDisplayInputDisplayTextVerticalCenterOffset;
            rightMargin: Style.myDisplayInputDisplayTextRightMargin;
        }
        font.pixelSize: parent.height * 0.6;
        text: Style.myDisplayInputDisplayText;
        horizontalAlignment: Text.AlignRight;
        elide: Text.ElideRight;
        color: Style.myDisplayInputDisplayTextColor;
        smooth: true;
        font.bold: Style.myDisplayInputDisplayTextBold;
    }
}
