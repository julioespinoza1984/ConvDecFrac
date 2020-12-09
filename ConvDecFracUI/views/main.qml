import QtQuick 2.12
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import components 1.0
import assets 1.0

ApplicationWindow {
    id: root;
    visible: true
    width: Style.widthWindow;
    height: Style.heightWindow;
    minimumWidth: Style.minWidthWindow;
    minimumHeight: Style.minHeightWindow;
    title: titleOriginal;
    property bool vertical: width < height;

    function orientationToString() {
        if(vertical) {
            return Style.myKeyboardStateVertical;
        } else {
            return Style.myKeyboardStateHorizontal;
        }
    }

    MessageDialog {
        id: aboutDialog
        icon: StandardIcon.Information
        title: Style.aboutTitle;
        text: Style.aboutText;
        informativeText: Style.about;
    }

    property string titleOriginal: vertical ? Style.titleWindowShort : Style.titleWindow;

    toolBar: ToolBar {
        id: mainToolBar;
        width: parent.width;
        RowLayout {
            anchors.fill: parent;
            Label {
                id: labelTitle;
                text: root.titleOriginal;
            }
            Item {
                Layout.fillWidth: true;
            }
            Button {
                style: ButtonStyle {
                    background: BorderImage {
                        source: "qrc:/assets/IconConvDecFrac.png";
                        border.left: Style.mainToolBarBorderButton;
                        border.right: Style.mainToolBarBorderButton;
                        border.top: Style.mainToolBarBorderButton;
                        border.bottom: Style.mainToolBarBorderButton;
                    }
                }
                onClicked: aboutDialog.open();
            }
            Button {
                style: ButtonStyle {
                    background: BorderImage {
                        source: "qrc:/assets/but-quit.png";
                        border.left: Style.mainToolBarBorderButton;
                        border.right: Style.mainToolBarBorderButton;
                        border.top: Style.mainToolBarBorderButton;
                        border.bottom: Style.mainToolBarBorderButton;
                    }
                }
                onClicked: Qt.quit();
            }
        }
    }

    MyKeyboard {
        id: keyboard;
        stateValue: orientationToString();
        anchors.fill: parent;
    }
}
