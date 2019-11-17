import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick .Controls 2.2
import QtQuick .Layouts 1.2
import QtMultimedia 5.11
Rectangle {
    property alias button1: buttonpaly
    property  var utilDate: new Date()
    function msecToString(msec)
    {
        utilDate.setTime(msec)
        return Qt.formatTime(utilDate,"mm:ss")
    }

    //http://localhost:3000/song/url?id=33894312
    function updatePaly(sID,sName)
    {
        //url
        var Http = new XMLHttpRequest()
        var url = 'http://localhost:3000/song/url?id='+sID
        Http.open("Get",url)
        Http.send()
        Http.onreadystatechange=function()
        {
            if( Http.readyState === Http.DONE )
            {
                var requestData = Http.responseText.toString()
                var objs=JSON.parse(requestData)
                var objData = objs.data
                for (var index in objData )
                {
                    var  obj = objData[index]
                    var url = obj.url
                    mediaplayer.source=url
                    musicplay()
                    label.text=sName
                }
            }

        }

    }

    MediaPlayer {
        id: mediaplayer
        source: "file:/home/hacker/Qt/work/build-audioTest-Desktop_Qt_5_11_2_GCC_64bit-Debug/Delacey - Dream It Possible.mp3"
        onPlaying:function()
        {
            console.log("pos"+pos+"/"+mediaplayer.metaData.size)
            buttonpaly.icon.source= "qrc:/icons/Icons/ooopic_1569151262.png"
        }
        onPaused: function()
        {
            buttonpaly.icon.source= "qrc:/icons/Icons/ooopic_1569151249.png"
        }
        onPositionChanged:
        {
            labeltime.posStr =  msecToString(position)
            slider.curPos=position
        }

        onDurationChanged:
        {
            labeltime.durStr =  msecToString(duration)
            slider.maxlen = duration
        }

    }
    function musicplay() {
        if(mediaplayer.playbackState == MediaPlayer.PlayingState)
        {
            mediaplayer.pause()
        }
        else
        {
            mediaplayer.play()
        }
    }
    RowLayout {
        anchors.fill: parent
        RowLayout {
            Layout.preferredHeight: 38
            Layout.preferredWidth: 293

            Button {
                id: button
                width: 30
                height: 30
                display: AbstractButton.TextBesideIcon
                Layout.fillHeight: true
                icon.source:  "qrc:/icons/Icons/ooopic_1569151257.png"
                icon.color:"transparent" //颜色
            }

            Button {
                id: buttonpaly
                width: 30
                height: 30
                Layout.fillHeight: true
                padding: 4
                focusPolicy: Qt.NoFocuse
                transformOrigin: Item.Center
                font.bold: false
                font.italic: false
                font.underline: false
                font.family: "Tahoma"
                spacing: 5
                icon.source:  "qrc:/icons/Icons/ooopic_1569151249.png"
                icon.width: 20
                icon.height: 30
                icon.color:"transparent" //颜色
                onClicked:musicplay()
            }

            Button {
                id: button2
                width: 30
                height: 30
                Layout.fillHeight: true
                icon.source:  "qrc:/icons/Icons/ooopic_1569151266.png"
                icon.color:"transparent" //颜色
            }
        }

        RowLayout {

            ColumnLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true

                Label {
                    id: label
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                RowLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Slider {
                        id: slider
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        value: curPos
                        from:0
                        to:maxlen
                        property var maxlen:100
                        property var curPos:10
                        handle: Rectangle
                        {
                            anchors.centerIn:parent
                            color:"transparent" //颜色
                            //border.color:"darkCyan"
                            border.width:1
                            width:50
                            height:20
                            radius:10
                            Text
                            {
                                anchors.centerIn: parent
                                text:labeltime.posStr
                            }
                        }
                    }

                    Label {

                        id: labeltime
                        text: /*posStr+"/"+*/durStr
                        property var posStr:"00.00"
                        property var durStr:"05:20"
                    }
                }
            }
        }

        RowLayout {

            RowLayout {
                Button
                {
                    Layout.fillHeight: true
                    icon.color:"transparent" //颜色
                    icon.source: "qrc:/icons/Icons/audio-volume.png"
                    onClicked: {
                        volumeslider.visible = !volumeslider.visible
                    }
                }
                Slider {
                    Layout.fillHeight: true
                    id: volumeslider
                    value: 80
                    from:0
                    to:100
                    visible: false
                    handle: Rectangle
                    {
                    }
                    onValueChanged:
                    {
                        mediaplayer.volume = value/volumeslider.to
                    }

                }
            }

            Button {
                id: button4
                Layout.fillHeight: true
                icon.color:"transparent" //颜色
                //listsequence.png
                icon.source: "qrc:/icons/Icons/listsequence.png"
            }

            Button {
                id: button5
                Layout.fillHeight: true
                icon.color:"transparent" //颜色
                icon.source:  "qrc:/icons/Icons/btnlist.png"
            }
        }
    }
}
/*##^## Designer {
    D{i:0;autoSize:true;height:50;width:640}
}
 ##^##*/
