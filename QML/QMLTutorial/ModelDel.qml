import QtQuick 2.0
//delegate
Item {
    width: parent.width
    height:80

    Rectangle
    {
        id:rec
        anchors.fill: parent
        color: c
        Image {
            id: img
            source: s
            anchors
            {
                verticalCenter:rec.verticalCenter
                left:rec.left
            }
            width: 50
            height: 30
        }
        Text {
            id: text
            text:name
            anchors
            {
                left:img.right
                verticalCenter:rec.verticalCenter
            }

        }

    }
}
