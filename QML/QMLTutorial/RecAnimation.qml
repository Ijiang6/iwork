import QtQuick 2.0


    Rectangle
    {
        id:root

        anchors.fill: parent
        color: "darkCyan"

        Rectangle
        {
            id:child
            width: 50
            height: 50
            color:"cyan"
        }
        SequentialAnimation
        {
            running: true
            loops: Animation.Infinite

            NumberAnimation {
                target: child
                property: "x"
                to:500
                duration: 1200


            }
            NumberAnimation {
                target: child
                property: "y"
                to:300
                duration: 1200
                }
                 NumberAnimation {
                    target: child
                    property: "x"
                    to:0
                    duration: 1200

                }
                NumberAnimation {
                    target: child
                    property: "y"
                    to:0
                    duration: 1200

                }

        }
        MouseArea
        {
            anchors.fill: parent
            onClicked: {
                console.log("width:"+child.width)
                 console.log("height:"+child.height)
            }
        }

    }


