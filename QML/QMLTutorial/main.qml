import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Tutorial")

    Grid {
        id: grid
        anchors.fill: parent
        spacing: 15
        Button {
            id: buttonrec

            text: qsTr("Rectangle")
            onClicked:
            {
                recview.visible=true
            }

        }
        Button {
            id: buttontext

            text: qsTr("Text")
            onClicked:
            {
                textview.visible=true
            }

        }
        Button {
            id: buttonMouse

            text: qsTr("MousrArea")
            onClicked:
            {
                mouseview.visible=true
            }
        }
        Button {
            id: buttonProperty

            text: qsTr("Proterty - Signal-Slot")
            onClicked:
            {
                propertyview.visible=true
            }
        }
        Button {
            id: buttonImage

            text: qsTr("Image")
            onClicked:
            {
                imageview.visible=true
            }
        }
        Button {
            id: buttonLibrary

            text: qsTr("Library")
            onClicked:
            {
                libraryview.visible=true
            }
        }
        Button {
            id: buttonFlickable

            text: qsTr("flickable")
            onClicked:
            {
                flickableview.visible=true
            }
        }
        Button {
            id: buttonKeys

            text: qsTr("Keys")
            onClicked:
            {
                keyview.visible=true
            }
        }
        Button {
            id: buttonKeynavactive

            text: qsTr("KeyNavActive")
            onClicked:
            {
                keynavview.visible=true
            }
        }
       Button {
            id: buttonGridAndRepeated

            text: qsTr("GridAndRepeated")
            onClicked:
            {
                gridreview.visible=true
             }
        }
       Button {
            id: buttonModelView

            text: qsTr("ModelView")
            onClicked:
            {
                iModelview.visible=true
             }
        }
       Button {
            id: buttonxmlModelView

            text: qsTr("XmlListModelView")
            onClicked:
            {
                xmldoelview.visible=true
             }
        }
       Button {
            id: buttonjsfileView

            text: qsTr("jsfileView")
            onClicked:
            {
                jsfileview.visible=true
             }
        }
       Button {
           id: sequeanimationView

           text: qsTr("sequeanimationView")
           onClicked:
           {
               sequeanimationview.visible=true
            }
       }
       Button {
           id: anchoranimationView

           text: qsTr("sequeanimationView")
           onClicked:
           {
               anchoranimationview.visible=true
            }
       }
       Button {
           id: audioView

           text: qsTr("AudioView")
           onClicked:
           {
               audioiew.visible=true
            }
       }
       Button {
           id: simpledialogView

           text: qsTr("SimpleDialog")
           onClicked:
           {
               simpledialog.visible=true
            }
       }
       Button {
           id: simpledialogView_2

           text: qsTr("SimpleDialog_2")
           onClicked:
           {
               simpledialog_2.visible=true
            }
       }

    }

    SimpleDialog
    {
        id:simpledialog
        visible: false
    }
    SimpleDialog_2
    {
        id:simpledialog_2
        visible: false
    }
    Window
    {
        id:anchoranimationview
       AnimationAnchor
        {
            anchors.fill: parent
        }
       width: 640
       height: 480
      visible: false
    }
    Window
    {
        id:sequeanimationview
       RecAnimation
        {
            anchors.fill: parent
        }
       width: 640
       height: 480
      visible: false
    }
    Window
    {
        id:audioiew
       AudioView
        {
            anchors.fill: parent
        }
       width: 640
       height: 480
      visible: false
    }
    Window
    {
        id:jsfileview
       JavascripFileView
        {
            anchors.fill: parent
        }
       width: 640
       height: 480
      visible: false
    }
    Window
    {
        id:xmldoelview
       XMLlistModelView
        {
            anchors.fill: parent
        }
       width: 640
       height: 480
      visible: false
    }
    Window
    {
        id:gridreview
       GridAndRepeatedView
        {
            id:grifreId
            anchors.fill: parent
        }
        visible: false
    }
    Window
    {
        id:keyview
       Keysview
        {
            id:keyId
            anchors.fill: parent
        }
       width: 640
       height: 480
        visible: false
    }
    Window
    {
        id:iModelview
       ModelView
        {

            anchors.fill: parent
        }
       width: 640
       height: 480
        visible: false
    }
    Window
    {
        id:flickableview
       FlickableView
        {
            id:flickableId
            anchors.fill: parent
        }
       width: 640
       height: 480
        visible: false
    }
    Window
    {
        id:textinputview
        TextInputView
        {
            id:textinputId
            anchors.fill: parent
        }
        width: 640
        height: 480
        visible: false
    }
    Window
    {
        id:keynavview
        KeyNavAndActiveView
        {
            id:keynavId
            anchors.fill: parent
        }
        width: 640
        height: 480
        visible: false
    }
    Window
    {
        id:recview
        RectangleView
        {
            id:recId
            anchors.fill: parent
        }
        width: 640
        height: 480
        visible: false
    }
    Window
    {
        id:textview
        TextView
        {
            id:textId
            anchors.fill: parent
        }
        width: 640
        height: 480
        visible: false
    }
    Window
    {
        id:mouseview
        MourseAreaView
        {
            id:mouseId
            anchors.fill: parent
        }
        width: 640
        height: 480
        visible: false
    }
    Window
    {
        id:imageview
        ImageView
        {
            id:imageId
            anchors.fill: parent
        }
        width: 640
        height: 480
        visible: false
    }
    Window
    {
        id:libraryview
        ImportLibraryView
        {
            id:libraryId
            anchors.fill: parent
        }

        visible: false
    }
    Window
    {
        id:propertyview
        PropertyView
        {
            id:protertyId
            anchors.centerIn:  parent
            backColor: "red"
            bordColor: "dark cyan"
            borderWidth:4
            radius:20
            width:200
            height: 50
            buttonText: "custom button"
            fontSize: 18
            textColor: "white"
            onButtClicked:
            {
                console.log("button Clicekd")
            }
        }
        width: 640
        height: 480
        visible: false
    }
}
