import QtQuick 2.0
import QtQuick .Window 2.2
Item {
    width:Screen.width
    height: Screen.height -100

    focus: true
    Keys.onPressed:
    {
        if(event.key === Qt.Key_Up)
        {
            event.accepted = true
            img2.y = img2.y-10;
        }
        else if(event.key === Qt.Key_Down)
        {
            event.accepted = true
            img2.y = img2.y+10;
        }
        else if(event.key === Qt.Key_Left)
        {
            event.accepted = true
            img2.x = img2.x-10;
        }
        else if(event.key === Qt.Key_Right)
        {
            event.accepted = true
            img2.x = img2.x+10;
        }
    }

    Flickable
    {

        width:Screen.width
        height: Screen.height
        contentWidth: Screen.width*4
        contentHeight: Screen.height
        interactive: true
        boundsBehavior: Flickable.StopAtBounds
        Image {
            id: img
            anchors.fill: parent
            source: "qrc:/image/image/7.jpg"
            sourceSize.width: Screen.width
            sourceSize.height: Screen.height*4
        }
        Image {
            id: img2
            x:100
            y:100
            source: "qrc:/image/image/youtube-to-mp3.png"
            sourceSize.width: 50
            sourceSize.height: 30
        }
    }

}
