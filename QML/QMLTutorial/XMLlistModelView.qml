import QtQuick 2.0
import QtQuick.XmlListModel 2.0
Item {

    XmlListModel
    {
        id:imodel
        source: "qrc:/image/data.xml"
        query: "/rss/channel/item"
        XmlRole { name: "title"; query: "title/string()" }
        XmlRole { name: "pubDate"; query: "pubDate/string()" }
        onStatusChanged:
        {
            if(status === XmlListModel.Loading)
            {
                console.log("loading")
            }
            else if(status === XmlListModel.Ready)
            {
                console.log("ready")
            }
            else if(status === XmlListModel.Error)
            {
                console.log("error")
            }

        }
    }
     ListView
     {
         id :listview
         anchors.fill: parent
         model:imodel
         delegate: Text { text: title + ": " + pubDate }

     }

}
