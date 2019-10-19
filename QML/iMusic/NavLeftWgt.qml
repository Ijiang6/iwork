import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick .Controls 2.2
import QtQuick .Layouts 1.2
import Qt.labs.calendar 1.0
Rectangle {

    ColumnLayout {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        ToolButton {
            id: toolButton
            text: qsTr("Search")
            display: AbstractButton.TextBesideIcon
            Layout.fillHeight: true
            Layout.fillWidth: true
            icon.source:  "qrc:/icons/Icons/mate-sensors.png"
        }

        ToolButton {
            id: toolButton1
            text: qsTr("Local")
            Layout.fillHeight: true
            transformOrigin: Item.TopLeft
            display: AbstractButton.IconOnly
            Layout.fillWidth: true
          //  icon.source:  "qrc:/icons/Icons/musictube.png"
            Image {
                id: localimg
               anchors.fill: parent
                source: "qrc:/icons/Icons/rhythmbox.png"
            }
        }

        ToolButton {
            id: toolButton2
            text: qsTr("Find")
            font.weight: Font.Normal
            Layout.fillHeight: true
            display: AbstractButton.IconOnly
            Layout.fillWidth: true
            Image {
                id: findimg
               anchors.fill: parent
                source: "qrc:/icons/Icons/musictube.png"
            }
        }

        ToolButton {
            id: toolButton3
            text: qsTr("Mv")
            Layout.fillHeight: true
            hoverEnabled: true
            display: AbstractButton.IconOnly
            font.weight: Font.Thin
            autoRepeat: false
            font.capitalization: Font.MixedCase
            checkable: true
            focusPolicy: Qt.WheelFocus
            highlighted: false
            Layout.fillWidth: true
            Image {
                id: mvimg
                anchors.bottomMargin: 31
                anchors.fill: parent
                source: "qrc:/icons/Icons/rosamp.png"
            }
        }
    }

}


/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:100}
}
 ##^##*/
