import QtQuick 2.0
import QtQuick .Window 2.2
Item {
    width:Screen.width
    height: Screen.height -100

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
  }

}
