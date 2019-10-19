import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick .Controls 1.2
import QtQuick .Layouts 1.2
Window {
    visible: true
    width: 1200
    height: 600

    color: "#babdb6"
    title: qsTr("iMusic")

    MainWgt {
        id: mainWgt
        anchors.fill: parent
    }
}

/*##^## Designer {
    D{i:6;anchors_x:241;anchors_y:203}
}
 ##^##*/
