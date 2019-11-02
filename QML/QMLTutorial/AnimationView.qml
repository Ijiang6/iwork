import QtQuick 2.0
import QtQuick.Window 2.2
Window {
    width: 640
    height: 480
    visible: true
    ListModel
    {
        id:imodel
        ListElement
        {
            sourceimg:"https://car3.autoimg.cn/cardfs/product/g27/M00/88/63/800x0_1_q95_autohomecar__ChcCQFxFjPWAIADaAAXXP8bFUoE708.jpg"//"image/image/Local.png"
        }
        ListElement
        {
            sourceimg:"https://car3.autoimg.cn/cardfs/product/g27/M07/89/FF/800x0_1_q95_autohomecar__ChsEfFxFjPSADnNpAAWhFk4hwqk917.jpg"
        }
        ListElement
        {
            sourceimg:"https://car3.autoimg.cn/cardfs/product/g28/M07/84/72/800x0_1_q95_autohomecar__ChsEnlxFjPSAceY2AAV29nRrb6k776.jpg"
        }

    }

    ListView
    {
        anchors.fill: parent
        id:imgview
        model :imodel
        spacing: 10
        delegate:
            Rectangle
        {
            id:backRec
            color: "transparent"
            radius: 20
            width:300
            height:200
            states: [
                State {
                    name: "ENTERED"
                    PropertyChanges {
                        target: backRec
                        color:"cyan"
                    }
                },
                State {
                    name: "EXITED"
                    PropertyChanges {
                        target: backRec
                        color:"transparent"
                    }
                }
            ]
            transitions:
            [
                Transition {
                    from: "EXITED"
                    to: "ENTERED"
                    ColorAnimation {
                        target: backRec
                        duration: 1200
                    }
                },
                Transition {
                    from: "ENTERED"
                    to: "EXITED"
                    ColorAnimation {
                        target: backRec
                        duration: 1200
                    }
                }
            ]
            Image
            {
                id:mainImg
                anchors.centerIn:  parent
                source: sourceimg
                width: parent.width/2
                height: parent.height/2
                scale : status == Image.Ready ? 1:0
                Behavior on scale
                {
                    NumberAnimation
                    {
                        duration: 1200
                        easing.type: Easing.OutBack
                    }
                }
                opacity: status == Image.Ready ? 1:0
                Behavior on opacity
                {
                    NumberAnimation
                    {
                        duration: 1000
                        from:0
                        to:1
                        easing.type: Easing.OutCirc
                    }
                }

                MouseArea
                {
                    id:mouse
                    anchors.fill: mainImg
                    hoverEnabled: true
                    onClicked:
                    {
                        scalAnimation.start()
                    }
                   onEntered: backRec.state="ENTERED"
                  onExited:  backRec.state="EXITED"
                }

                PropertyAnimation {
                    id:scalAnimation
                    target: mainImg;  property: "scale"
                    from: 0
                    to:1
                    duration: 1200
                    easing.type: Easing.OutBack
                }
            }
        }


    }


}
