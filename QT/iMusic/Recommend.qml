import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
Item {
      signal sig_albumID(bool bAblum ,string sID)
        MusicPicture {
            id: musicPicture
            anchors.fill: parent
            Layout.fillHeight: true
            Layout.fillWidth: true
            onSig_musitcID:
            {
                emit:sig_albumID(true,sID)
            }
        }
        //http://localhost:3000/personalized/newsong
        function updateMusic()
        {

            var Http = new XMLHttpRequest()
            var url = 'http://localhost:3000/personalized/newsong'
            Http.open("Get",url)
            Http.send()
            Http.onreadystatechange=function()
            {
                if( Http.readyState === Http.DONE )
                {
                    var requestData = Http.responseText.toString()
                    var objs=JSON.parse(requestData)
                    var objInfo = objs.result
                    for (var index in objInfo )
                    {
                        var  obj = objInfo[index]
                        var sName = obj.name
                        var objSong = obj.song
                        var objAlbum =objSong.album

                        var jsonObj = {"name": sName,"imagepath":objAlbum.blurPicUrl,"stringID":objAlbum.id}
                        musicPicture.updateModelData(jsonObj)
                    }
                }
            }
        }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:600;width:1000}
}
 ##^##*/
