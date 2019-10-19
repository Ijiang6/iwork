import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    //http://localhost:3000/album?id=32311
 signal sig_musicPaly(string sID , string sName)
     function updateDataPlayList(playID)
     {
        var url = 'http://localhost:3000/playlist/detail?id='+playID
         var Http = new XMLHttpRequest()
        Http.open("Get",url)
        Http.send()
        Http.onreadystatechange=function()
        {
            if( Http.readyState === Http.DONE )
            {
                var requestData = Http.responseText.toString()
                var objs=JSON.parse(requestData)
                var objInfo = objs.playlist//playlists
                var objtrakIds = objInfo.trackIds
                for (var index in objtrakIds )
                {
                    var  obj = objtrakIds[index]
                    parseTrackIds(obj.id)
                }
            }

        }
     }
    function parseTrackIds(ID)
    {
        var url = 'http://localhost:3000/song/detail?ids='+ID
         var Http = new XMLHttpRequest()
        Http.open("Get",url)
        Http.send()
        Http.onreadystatechange=function()
        {
            if( Http.readyState === Http.DONE )
            {
                var requestData = Http.responseText.toString()
                var objs=JSON.parse(requestData)
                var objInfo = objs.songs
                parseJsonSong(objInfo)
            }

        }

    }

    function updateDataAlbum(albumID)
    {
        //tableModel.clear()
    var Http = new XMLHttpRequest()
        var url = 'http://localhost:3000/album?id='+albumID
        Http.open("Get",url)
        Http.send()
        Http.onreadystatechange=function()
        {
            if( Http.readyState === Http.DONE )
            {
                var requestData = Http.responseText.toString()
                var objs=JSON.parse(requestData)
                var objInfo = objs.songs
                parseJsonSong(objInfo)
            }
        }
    }
 function parseJsonSong(objInfo)
   {
       for (var index in objInfo )
       {
           var  obj = objInfo[index]
           var objAr = obj.ar
           var aralias=""
           for(var indexar in objAr)
           {
               var objauthor = objAr[indexar]
               var alis =objauthor.alia
//               if(alis !== null || alis !== "undefined" || alis !== "")
//               {
//                   aralias += objauthor.name+"("+objauthor.alia+")"
//               }
//               else
//               {
                 aralias += objauthor.name
 //              }
           }
           var objmusic = obj.alia
           var aralimusic=""
           for(var indexmu in objmusic)
           {
               var objmu = objmusic[indexmu]
               aralimusic +=objmu
           }
           var music = obj.name
//           if( aralimusic !== null || aralimusic !== "undefined" || aralimusic !== "")
//           {
//               music = obj.name+"("+aralimusic+")"
//           }
            var jsonObj = {"name":music,"id":obj.id,"author":aralias}

           tableModel.append(jsonObj)
       }
   }
 function doubleClickRowData(row)
 {
     if(row <0)
     {
         return
     }
    var rowItem= tableModel.get(row)
    var sID= rowItem.id
    var sName= rowItem.name+"-"+rowItem.author
     emit:sig_musicPaly(sID,sName)
 }
    ListModel
    {
        id:tableModel
//        ListElement
//        {
//            name: "情绪河豚"
//            time:"05:20"
//            singer:"singer"
//            album:"album"
//        }
    }


    TableView {
        id:table
        anchors.fill: parent
        TableViewColumn
        {
           role: "id"
           title: "ID"
           visible: false
        }
        TableViewColumn
        {
           role: "name"
           title: "Name"
        }
        TableViewColumn
        {
           role: "author"
           title: "Singer"
        }
      model: tableModel
      onDoubleClicked:
      {
          doubleClickRowData(row)
      }
    }
}


/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
