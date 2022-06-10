import QtQuick
import QtQuick.Controls
import SpecialValidator 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Special Validator")

    TextField {
        id: textField
        anchors.centerIn: parent
        font.pixelSize: 20
        validator: SpecialValidator {}
        background: Rectangle {
            color: textField.acceptableInput ? "lightgreen" : "lightcoral"
            border {
                color: "black"
                width: 1
            }
            implicitWidth: 140
            radius: 4
        }
    }
}
