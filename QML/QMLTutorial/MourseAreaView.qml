import QtQuick 2.0

Rectangle {
    id: rootTangle //key
    width:360
    height:360
    color: "red" //key
    Rectangle
    {
        id:recTangle
        width:rootTangle.width /2  //key
        height: rootTangle.height/6 //key
        anchors.centerIn: parent
        border.color: "#000000"
        border.width: 6
        radius: 20
        color: "blue"
    }

    MouseArea
    {
        id:mouseArea
        anchors
        {
            fill: recTangle
        }
        onClicked:
        {
            Qt.quit()
        }
        hoverEnabled: true
        onEntered:
        {
            recTangle.color="brown"
            recTangle.rotation =45
            mousetext.rotation =45
        }
        onExited:
        {
            recTangle.color="blue"
            recTangle.rotation =0
            mousetext.rotation =0
        }

        Text
        {
            id:mousetext
            anchors.centerIn: mouseArea
            text:"  Hello <b> World </b>" //key
            color: "white"
            font.pixelSize: Math.round(recTangle.height/3) //key

        }
    }
}
