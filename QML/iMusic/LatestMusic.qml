import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0

Item {
    signal sig_clickMusicItem(bool bAblum ,string sID)
    function updateMusic()
    {
        var Http = new XMLHttpRequest()
        var url = 'http://localhost:3000/top/playlist?limit=10&order=hot'
        Http.open("Get",url)
        Http.send()
        Http.onreadystatechange=function()
        {
            if( Http.readyState === Http.DONE )
            {
                var requestData = Http.responseText.toString()
                var objs=JSON.parse(requestData)
                var objInfo = objs.playlists
                for (var index in objInfo )
                {
                    var  obj = objInfo[index]
                    musicinfoModel.append(obj)
                }
            }

        }
    }

    ListModel
    {
        id:musicinfoModel
    }
    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.fillWidth: true

            Button {
                id: button
                text: "Chinese"
                onClicked:updateMusic()
            }

            Button {
                id: button1
                text: qsTr("English")
            }

            Button {
                id: button2
                text: qsTr("Pop")
            }
        }

        GridView {
            id: gridView
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.preferredHeight: 204
            Layout.preferredWidth: 344
            cellHeight:300
            cellWidth: 300
            delegate: MusicListItem
            {

                imgUrl:coverImgUrl// "icons/Icons/7.jpg"
                playNum: playCount
                description: name
                userId:id
                onSig_clickItem:{
                    emit: sig_clickMusicItem(false,id)
                }

            }
            model:musicinfoModel
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:31;anchors_x:114;anchors_y:82}
}
 ##^##*/
