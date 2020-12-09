import QtQuick 2.12
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import "calculator.js" as Calculator
import assets 1.0

Button {
    id: button;
    property alias enabledButton: button.enabled;
    property alias operation: button.text;
    property string color: "";

    onClicked: {
        Calculator.doOp(operation);
    }

    style: ButtonStyle {
        background: BorderImage {
             source: "qrc:/assets/button-" + color + ".png";
             border.left: Style.myButtonBorderStyle;
             border.right: Style.myButtonBorderStyle;
             border.top: Style.myButtonBorderStyle;
             border.bottom: Style.myButtonBorderStyle;
             Rectangle {
                anchors.fill: parent;
                anchors.margins: Style.myButtonAnchorMarginsStyleRectangle;
                color: Style.myButtonColourStyleRectangle;
                antialiasing: true;
                visible: !pressed;
                border.color: Style.myButtonBorderColourStyleRectangle;
                radius: Style.myButtonRadiusStyleRectangle;
            }
        }
        label: Text {
            verticalAlignment: Text.AlignVCenter;
            horizontalAlignment: Text.AlignHCenter;
            font.pixelSize: control.width > control.height ? control.height / 2 : control.width / 2;
            text: control.text;
            style: Text.Sunken;
            color: Style.myButtonColourTextButton;
            styleColor: Style.myButtonColourStyleTextButton;
            smooth: true;
        }
    }
}

