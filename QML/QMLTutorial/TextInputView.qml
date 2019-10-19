import QtQuick 2.0

Rectangle {
    anchors.fill: parent
    color:"black"
    Text
    {
        id: testtip
        text:"Please Input  Your Name:"
        color: "white"
        anchors.centerIn: parent
    }
    TextInput
    {
        id: textin
        text:"eg:Tom"
        color: "white"
        anchors.top:testtip.bottom
        anchors.topMargin: 10
        anchors.left: testtip.left
        onAccepted: text2.text = "Your Name is \n"+text
    }
    Text
    {
        id:text2
        color: "white"
        anchors.top:textin.bottom
        anchors.left: textin.left
        anchors.topMargin: 10
        font.pixelSize: 20
    }

}
