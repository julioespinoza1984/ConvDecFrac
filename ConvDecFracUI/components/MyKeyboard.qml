import QtQuick 2.12
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4
import assets 1.0

Rectangle {
    id: window;
    property alias stateValue: window.state;
    property bool landscapeWindow: width > height;
    property real baseWidth: landscapeWindow ? width : height;
    property real baseHeight: landscapeWindow ? height : width;
    property real rotationDelta: landscapeWindow ? Style.myKeyboardRotationHorizontal
                                                 : Style.myKeyboardRotationVertical;

    rotation: rotationDelta;

    color: Style.myKeyboardColourBackground;

    Column {
        id: box;
        spacing: Style.myKeyboardBoxSpacings;

        anchors {
            fill: parent;
            margins: Style.myKeyboardBoxAnchorsMargins;
        }
        ExclusiveGroup { id: radioGroup; }
        Row {
            RadioButton {
                id: rbDecimal;
                text: qsTr("N\u00FAmero: ");
                exclusiveGroup: radioGroup;
                checked: true;
                style: rbStyle;
            }
            MyDisplayInput {
                id: displayDecimal;
                width: window.width - 2 * box.spacing - rbDecimal.width;
                height: window.height / 11 - box.spacing;
            }
        }
        Row {
            RadioButton {
                id: rbPeriodo;
                text: qsTr("Per\u00EDodo: ");
                exclusiveGroup: radioGroup;
                style: rbStyle;

            }
            MyDisplayInput {
                id: displayPeriodo;
                width: window.width - 2 * box.spacing - rbPeriodo.width;
                height: window.height / 11 - box.spacing;
                text: "";
            }
        }
        NumberPad {
            width: window.width - box.spacing;
            height: 7 * window.height / 11 - 2 * box.spacing;
        }
        MyDisplayOutput {
            id: displayOutput;
            width: window.width - 2 * box.spacing;
            height: 2 * window.height / 11 - box.spacing;
        }
    }
    states: [
        State {
            name: Style.myKeyboardStateHorizontal;
            PropertyChanges {
                target: window;
                rotation: 90 + rotationDelta;
                width: baseHeight;
                height: baseWidth;
            }
        }
    ]
    // Pequeña animación para cuando cambia de estado
    transitions: Transition {
        SequentialAnimation {
            RotationAnimation {
                direction: RotationAnimation.Shortest;
                duration: Style.myKeyboardAnimationDuration;
                easing.type: Easing.InOutQuint
            }
            NumberAnimation {
                properties: "x,y,width,height";
                duration: Style.myKeyboardAnimationDuration;
                easing.type: Easing.InOutQuint
            }
        }
    }
    Component {
        id: rbStyle
        RadioButtonStyle {
            indicator: Rectangle {
                implicitWidth: 16
                implicitHeight: 16
                radius: 9
                border.color: control.activeFocus ? "dark#AA7733" : "gray"
                border.width: 1
                Rectangle {
                    anchors.fill: parent
                    visible: control.checked
                    color: "#555"
                    radius: 9
                    anchors.margins: 4
                }
            }
            label: Text {
                text: control.text;
                font.pixelSize: displayDecimal.height * 0.6;
                color: "white";
            }
        }
    }
}

