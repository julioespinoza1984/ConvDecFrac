import QtQuick 2.12
import assets 1.0

Grid {
    id: grid;

    rows: Style.numberPadRows;
    columns: Style.numberPadColumns;
    spacing: Style.numberPadSpacing;

    property real buttonWidth: grid.width / columns - grid.spacing;
    property real buttonHeight: grid.height / rows - grid.spacing;

    // Los botones de la 1era fila
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        color: Style.numberPadColourYellowULButton;
        operation: Style.numberPadOperationNew;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        color: Style.numberPadColourYellowUButton;
        operation: Style.numberPadOperationClearAll;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        color: Style.numberPadColourYellowURButton;
        operation: Style.numberPadOperationClear;
    }

    // El Teclado Numérico
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation7;
        color: Style.numberPadColourOrangeLButton;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation8;
        color: Style.numberPadColourOrangeCButton;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation9;
        color: Style.numberPadColourOrangeRButton;
    }

    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation4;
        color: Style.numberPadColourOrangeLButton;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation5;
        color: Style.numberPadColourOrangeCButton;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation6;
        color: Style.numberPadColourOrangeRButton;
    }

    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation1;
        color: Style.numberPadColourOrangeLButton;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation2;
        color: Style.numberPadColourOrangeCButton;
    }
    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation3;
        color: Style.numberPadColourOrangeRButton;
    }

    MyButton {
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperation0;
        color: Style.numberPadColourOrangeDLButton;
    }
    MyButton {
        id: mcdButton;
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperationDot;
        color: Style.numberPadColourWhiteDButton;
    }
    MyButton {
        id: mcmButton;
        width: grid.buttonWidth;
        height: grid.buttonHeight;
        operation: Style.numberPadOperationEqual;
        color: Style.numberPadColourGreenDRButton;
    }
}

