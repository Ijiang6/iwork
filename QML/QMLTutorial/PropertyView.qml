import QtQuick 2.0

Item {
 id:button
 property string  backColor
 property string bordColor
 property int borderWidth
 property int radius
 property string buttonText
 property int  fontSize
 property string  textColor
 signal buttClicked
 Rectangle
 {
     id:blueRec
     radius: button.radius
     color:backColor
     border.color: button.bordColor
     border.width: button.borderWidth
     width:parent.width
     height: parent.height
 }
 Text
 {
     id:buttontext
     anchors.centerIn: recMouseArea
     text:buttonText
     color: textColor
     font.pixelSize: fontSize
     wrapMode: Text.WordWrap

 }

 MouseArea
 {
     id:recMouseArea
     anchors.fill: parent
     hoverEnabled: true
     onEntered:
     {
         blueRec.scale =1.5
         blueRec.color =bordColor
         blueRec.border.color =backColor
     }
     onExited:
     {
         blueRec.scale =1
         blueRec.color =backColor
         blueRec.border.color =bordColor
     }
     onClicked:
     {
         buttClicked()
     }
 }
}
