import QtQuick 2.0
import QtQuick.Window 2.2
Rectangle {
   width: Screen.width
   height: Screen.height -100
    MouseArea
    {
        anchors.fill: parent
        Text{
            id:text
            text:"Click to Quit"
            anchors.centerIn:  parent
        }
        onClicked:
        {
            console.log(Screen.width)
            Qt.quit()

        }
    }





}
