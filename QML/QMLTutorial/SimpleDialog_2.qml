import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.3
Window {
    visible:  true
    width:640
    height: 480
    title:"SimpleDialog-2"
  Button
  {
      width: parent.width
      text:"just close"
      onClicked: simpledialog.open()

  }
  Dialog
  {
      id:simpledialog
      title: "SimpleDialog_2"

      onAccepted: Qt.quit()
      onRejected: this.close
      contentItem: Rectangle{
          Column
          {
              anchors.fill: parent
              Text
              {
                  text:"do you want to close dialog?"
              }

              Button
              {
                  text:"Yes"
                  onClicked: Qt.quit()
              }
              Button
              {
                  text:"Cancel"
                  onClicked:simpledialog.close()
              }

          }
  }
  }

}
