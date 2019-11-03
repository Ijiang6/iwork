import QtQuick 2.0
import QtMultimedia 5.0
Rectangle {
    anchors.fill: parent
    gradient:
        Gradient
    {
     GradientStop{position: 0.9;color: Qt.darker(palette.window,1.8)}
     GradientStop{position: 0.1;color: palette.window}
    }
    SystemPalette
    {
        id:palette
    }
    Audio
    {
        id:player
        source: "/home/hacker/Qt/work/Dream It Possible.mp3"
        autoLoad:  true
        autoPlay:  true
    }

    Rectangle
    {
        id:bottomBar
        width: parent.width
        height: parent.height/8
        anchors.bottom: parent.bottom
        gradient:
            Gradient
        {
         GradientStop{position: 0.1;color: Qt.darker(palette.window,1.5)}
         GradientStop{position: 0.9;color: palette.window}
        }

    }
    Rectangle
    {
        id:playrec
        width: parent.width/4
        height: parent.height/8
        color: Qt.darker(palette.window,1.4)
        radius: 20
        border
        {
            color: Qt.lighter(palette.window,1.4)
            width:1
        }
        anchors
        {
            left:bottomBar.left
            leftMargin:bottomBar.width/30
            bottom:bottomBar.bottom
        }
        MouseArea
        {
            id:playMouseArea
            anchors.fill: playrec
            onClicked: {
                if(player.playbackState ===1)
                {
                    player.pause()
                }
                else
                {
                    player.play()
                }
            }
        }

        Text {
            id: playtext
            anchors.centerIn: playMouseArea
            text:{
                if(player.playbackState ===1)
                {
                    return "pause"
                }
                else
                {
                    return "play"
                }
            }

            color: palette.buttonText
        }
    }

    //seek
    Rectangle
    {
        id:seekrec
        width: parent.width/4
        height: parent.height/8
        color: Qt.darker(palette.window,1.4)
        radius: 20
        border
        {
            color: Qt.lighter(palette.window,1.4)
            width:1
        }
        anchors
        {
            right:bottomBar.right
            rightMargin:bottomBar.width/30
            bottom:bottomBar.bottom
        }
        MouseArea
        {
            id:seekMouseArea
            anchors.fill: seekrec
            onClicked: {
                player.seek(player.position+100)
            }
        }

        Text {
            id: seektext
            anchors.centerIn: seekMouseArea
            text:{
               player.duration
            }

            color: palette.buttonText
        }
    }

}
