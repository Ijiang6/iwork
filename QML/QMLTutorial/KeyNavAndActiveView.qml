import QtQuick 2.0
import QtQuick.Layouts 1.0
Item {
     Column
     {
         anchors.fill: parent
         spacing: 10
         Rectangle
         {
             id:rec1
             width: 200
             height:100
             focus: true
             color:activeFocus ?"red":"grey"
             KeyNavigation.up: rec3
             KeyNavigation.down: rec2
         }
         Rectangle
         {
             id:rec2
             width: 200
             height:100
             color:activeFocus ?"yellow":"grey"
             KeyNavigation.up: rec1
             KeyNavigation.down: rec3
         }
         Rectangle
         {
             id:rec3
             width: 200
             height:100
             color:activeFocus ?"cyan":"grey"
             KeyNavigation.up: rec2
             KeyNavigation.down: rec1
         }


     }

}
