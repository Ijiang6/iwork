import QtQuick 2.0
import QtQuick.Layouts 1.0
Rectangle {
    id: musicItemRoot
    property alias imgUrl: bacImge.source
    property alias playNum : textPlayNum.text
    property alias description :strDescription.text
    property string userId
    signal sig_clickItem(string id)
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }
    border.color: "#173a51"
    ColumnLayout
    {
        id:columnLayout
        anchors.rightMargin: -105
        anchors.bottomMargin: 0
        anchors.fill: parent
        Image {

            id:bacImge
            source: "qrc:/icons/Icons/7.jpg"
            width:50
            height: 50
            Layout.maximumHeight: 200
            Layout.maximumWidth: 200
            Layout.rowSpan: 0
            Text {
                id: textPlayNum
                anchors.left: imageIconListen.right
                anchors.bottom: parent.bottom
               color:"white"

            }

            Image {
                id: imageIconListen
                y: 312
                anchors.left:   parent.left
                anchors.bottom: parent.bottom
                width: 15
                height: 15
                anchors.leftMargin: 3
                source: "qrc:/icons/Icons/musictube.png"
            }

            Image {
                id: imageIconPlay
                x: 706
                y: 312
                width: 20
                height: 20
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                source: "qrc:/icons/Icons/ooopic_1569151249.png"
            }
            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onDoubleClicked:
                {
                   emit:sig_clickItem(userId)
                }
            }
        }
        Text
        {
            id:strDescription
            wrapMode:Text.WordWrap
        }
    }


}


/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
