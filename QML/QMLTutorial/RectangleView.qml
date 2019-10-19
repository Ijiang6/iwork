import QtQuick 2.0

Rectangle {
    id: rootTangle //key
    width:360
    height:360
    color: "red" //key

    Rectangle
    {
        id:blueTangle
        width:rootTangle.width /2  //key
        height: 64
        anchors.centerIn:  rootTangle //key
        color: "blue" //key
        border.color: "#000000"
        border.width: 6
        radius: 20
    }
    Rectangle
    {
        id:whiteTangle_1
        width:rootTangle.width /2  //key
        height: 64
        anchors.top: blueTangle.bottom
        anchors.left: blueTangle.left
        color: "#50FFFFFF" //key
        border.color: "#000000"
        border.width: 6
        radius: 20
    }
    Rectangle
    {
        id:whiteTangle_2
        width:rootTangle.width /2  //key
        height: 64
        anchors.top: whiteTangle_1.bottom
        anchors.left: whiteTangle_1.left
        color: "#FFFFFF" //key
        border.color: "#000000"
        border.width: 6
        radius: 20
    }
    Rectangle
    {
        id:recTangle_3
        width:rootTangle.width /2  //key
        height: 64
        anchors.top: whiteTangle_2.bottom
        anchors.left: whiteTangle_2.left
        border.color: "#000000"
        border.width: 6
        radius: 20
        rotation: 180 //key
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightsteelblue" }
            GradientStop { position: 1.0; color: "blue" }
        }

    }
    Text
    {
        anchors.centerIn: parent
        text:"Hello World"
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
