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
        rotation: 180
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightsteelblue" }
            GradientStop { position: 1.0; color: "blue" }
        }

    }
    Text
    {
        anchors.centerIn: recTangle
        text:"  Hello <b> World </b>" //key
        color: "white"
        font.pixelSize: Math.round(recTangle.height/3) //key
        width:recTangle.width //key
        //font.bold: true
        wrapMode: Text.WordWrap

    }
    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            Qt.quit()
        }
    }
}
