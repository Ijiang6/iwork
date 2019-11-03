import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.3
Window {
    visible:  true
    width:640
    height: 480
    title:"SimpleDialog"
    Column
    {
        anchors.fill: parent
  Button
  {
      width: parent.width
      text:"open dialog"
      onClicked: simpledialog.open()

  }
  Button
  {
      width: parent.width
      text:"open messdialog"
      onClicked: messagedialog.open()

  }
  Button
  {
      width: parent.width
      text:"open fontdialog"
      onClicked: fontdialog.open()

  }
  Button
  {
      width: parent.width
      text:"open corlordialog"
      onClicked: colorDialog.open()

  }
  Button
  {
      width: parent.width
      text:"open filedialog"
      onClicked: filedialog.open()

  }

    }
  Dialog
  {
      id:simpledialog
      title: "SimpleDialog"
      standardButtons: StandardButton.Ok |StandardButton.Cancel |StandardButton.Yes
      onAccepted: Qt.quit()
      onRejected: this.close
      modality: Qt.WindowModal
      Text
      {
          text:"do you want to close dialog?"
      }
  }
  MessageDialog
  {
      id:messagedialog
      title: "MessageDialog"
      text:"Text"
      informativeText: "informativeText"
      detailedText:"detailedText"
      modality: Qt.ApplicationModal
      standardButtons: StandardButton.Ok |StandardButton.Cancel |StandardButton.Yes
      onAccepted: Qt.quit()
      onRejected: this.close
  }
  FontDialog
  {
      id:fontdialog
  }
  ColorDialog {
        id: colorDialog
        title: "Please choose a color"
        onAccepted: {
            console.log("You chose: " + colorDialog.color)
            Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
            Qt.quit()
        }
        showAlphaChannel: true

    }
  FileDialog
  {
      id:filedialog
      selectMultiple: true
      selectFolder: false
      nameFilters: "*.cpp"
      onAccepted:
      {
          selectMultiple ? console.log(filedialog.fileUrls):console.log(filedialog.fileUrl)
      }
  }
}
