import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick .Controls 1.4
import QtQuick .Layouts 1.2
import QtQuick.Controls 2.3
Item {
    id:mainwgt
    signal sig_init()
    Timer {
        id:timer
        interval: 1000; running: true; repeat: false
        onTriggered:
        {
            latestmusic.updateMusic()
            recommend.updateMusic()
        }
    }
//    Component.onCompleted: {
//      mainwgt.sig_init.connect(latestmusic.updateMusic())
//    }
    function updateMusicTable(bAblum,ID)
    {
        if(stackview.depth >1)
        {
            stackview.pop()
        }
        if( bAblum)
        {
         musicTable.updateDataAlbum(ID)
        }
        else
        {
            musicTable.updateDataPlayList(ID)
        }
        stackview.push(musicTable)
    }
 function musicPlayData(sID,sName)
 {
     musicPlay.updatePaly(sID,sName)
 }
    RankList
    {
        id:rank

        onSig_musicListIem:
        {
            console.log("RankList"+id)
        }
    }
    Recommend
    {
        id:recommend
        onSig_albumID:
        {
           updateMusicTable(bAblum, sID)
        }
    }
    MusicInfoTable
    {
        id:musicTable
        onSig_musicPaly:
        {
            musicPlayData(sID,sName)
        }
    }
    LatestMusic
    {
        id: latestmusic
        onSig_clickMusicItem:
        {
           updateMusicTable(bAblum,sID)
        }
    }
    ColumnLayout {
        anchors.fill: parent
        TabBar {
            id: bar
            width: parent.width
            spacing: 15
            Repeater {

                model: ["Recommend", "RankList", "LatestMusic","LocalMusic" ]

                TabButton {
                    text: modelData
                    width: Math.max(100, bar.width / 5)
                    onClicked:
                    {
                        if(stackview.depth >1)
                        {
                            stackview.pop()
                        }
                        if(text == "RankList")
                        {
                            stackview.push(rank)
                        }
                        else if(text == "LocalMusic")
                        {
                            stackview.push(musicTable)
                        }
                        else if(text == "LatestMusic")
                        {
                            stackview.push(latestmusic)
                        }

                    }
                }
            }
        }

        StackView
        {
            id:stackview
            Layout.fillWidth: true
            Layout.fillHeight: true
            initialItem:recommend
        }
        MusicPlay {
            id: musicPlay
            height: 50
            Layout.fillWidth: true
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:10;anchors_x:13;anchors_y:43}D{i:1;anchors_height:300;anchors_width:360;anchors_x:140;anchors_y:64}
}
 ##^##*/
