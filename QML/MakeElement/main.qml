import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import Files 0.1
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property string  error
    property string  outPut
    Column
    {
        anchors.fill: parent
        Button
        {
            text: "read_1"
            onClicked:
            {

                reader.readFile()
            }
        }
        Button
        {
            text: "read_2"
            onClicked:
            {
                reader.type= ReadFile.Read
                reader.exec()
            }
        }

    }




    Text {
        id: txt
        text: qsTr("text")
        anchors.centerIn: parent
    }

    ReadFile
    {
        id:reader

        fileName: "/home/hacker/Qt/work/MakeElement/in.txt"
        onTextChange:
        {
            txt.text = outPut
        }

        onError:
        {
            txt.text =error
        }
    }
    ReadFile
    {
        id:reader_2

        fileName: "/home/hacker/Qt/work/MakeElement/in.txt"
        onTextChange:
        {
            txt.text = outPut
        }
        type:ReadFile.Read
        onError:
        {
            txt.text =error
        }
    }
}
