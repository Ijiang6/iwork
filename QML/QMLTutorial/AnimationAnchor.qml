import QtQuick 2.0

Rectangle {
 id:rootrec
 anchors.fill: parent
color: "darkCyan"
 Rectangle
 {
     id:rec
     color: "cyan"
     width: parent.width/3
     height: parent.height/3
     states: [
         State {
             name: "CLICKED"
             AnchorChanges {
                 target: rec
                 anchors.horizontalCenter: rootrec.horizontalCenter
                 anchors.bottom: rootrec.bottom
             }
             PropertyChanges {
                 target: rec
                 color:"red"
                 rotation:360
             }
         }
     ]
     transitions: [
         Transition {

             ParallelAnimation
            // SequentialAnimation  animations 2
             {
                 AnchorAnimation{

                    duration: 1200
                    easing.type: Easing.OutBounce
                 }
                // PauseAnimation{duration: 800}animations 2
                 RotationAnimation
                 {
                     duration: 1200
                     easing.type: Easing.OutCirc
                 }
             }
         }
     ]
     MouseArea
     {
         anchors.fill: parent
         onClicked:
         {
             rec.state ="CLICKED"
         }
     }
 }

}
