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
            x: 93
            y: 79
            text: qsTr("Rectangle")
            onClicked:
            {
                recview.visible=true
            }

        }
        Button {
            id: buttontext
            x: 93
            y: 79
            text: qsTr("Text")
            onClicked:
            {
                textview.visible=true
            }

        }
        Button {
            id: buttonMouse
            x: 93
            y: 79
            text: qsTr("MousrArea")
            onClicked:
            {
                mouseview.visible=true
            }
        }
        Button {
            id: buttonProperty
            x: 93
            y: 79
            text: qsTr("Proterty - Signal-Slot")
            onClicked:
            {
                propertyview.visible=true
            }
        }
        Button {
            id: buttonImage
            x: 93
            y: 79
            text: qsTr("Image")
            onClicked:
            {
                imageview.visible=true
            }
        }
        Button {
            id: buttonLibrary
            x: 93
            y: 79
            text: qsTr("Library")
            onClicked:
            {
                libraryview.visible=true
            }
        }
        Button {
            id: buttonFlickable
            x: 93
            y: 79
            text: qsTr("flickable")
            onClicked:
            {
                flickableview.visible=true
            }
        }
    }
    Window
    {
        id:flickableview
       FlickableView
        {
            id:flickableId
            anchors.fill: parent
        }
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
