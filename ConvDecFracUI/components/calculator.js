function doOp(op) {
    if(op === "." && displayDecimal.text.toString().search(/\./) !== -1) {
        return;
    }

    if(op.toString().length === 1 && ((op >= "0" && op <= "9") || op === ".")) {
        if(rbDecimal.checked) {
            if(displayDecimal.text.toString().length >= 14) return;
            if(displayDecimal.text !== "0" || op === ".") {
                displayDecimal.text = displayDecimal.text + op.toString();
            } else {
                displayDecimal.text = op.toString();
            }
        } else {
            if(displayPeriodo.text.toString().length >= 13) return;
            displayPeriodo.text = displayPeriodo.text + op.toString();
        }
        return;
    }

    if(op === "\u2190") {
        if(rbDecimal.checked) {
            displayDecimal.text = displayDecimal.text.toString().slice(0, -1);
            if(displayDecimal.text.length === 0) {
                displayDecimal.text = "0";
            }
        } else {
            displayPeriodo.text = displayPeriodo.text.toString().slice(0, -1);
        }
        displayOutput.result = "";
    } else if(op === "Borrar") {
        if(rbDecimal.checked) {
            displayDecimal.text = "0";
        }
        displayPeriodo.text = "";
        displayOutput.result = "";
    } else if(op === "Nueva") {
        displayDecimal.text = "0";
        displayPeriodo.text = "";
        rbDecimal.checked = true;
        displayOutput.result = "";
    } else if (op === "=") {
        if(displayDecimal.text !== "0") {
            appModel.number = displayDecimal.text;
            appModel.period = displayPeriodo.text === "" ? "-" : displayPeriodo.text;
            displayOutput.result = appModel.result;
        }
    }
}
