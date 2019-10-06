import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.0



Item {
    id: item1
    ListModel
    {
        id:listModel
    }

    ColumnLayout {
        x: 0
        y: 50

        Button
        {
            id: pbGetJson
            text:qsTr("Get Json")
            Layout.preferredHeight: 30
            Layout.preferredWidth: 100
            onClicked: function()
            {
                var Http = new XMLHttpRequest()
                var url = 'https://jsonplaceholder.typicode.com/posts'
                Http.open("Get",url)
                Http.send()
                Http.onreadystatechange=function()
                {
                    if( Http.readyState === Http.DONE )
                    {
                        var requestData = Http.responseText.toString()
                        var objs=JSON.parse(requestData)
                        for (var index in objs )
                        {
                            var  obj = objs[index]
                            var str = obj.userId +"->"+ obj.id+"->"+ obj.title+"->"+ obj.body
                            listModel.append(obj)
                        }
                    }

                }
            }
        }

        ListView {
            id: listView
            width: parent.width
            Layout.preferredHeight: 338
            delegate:
                Rectangle
            {
                width: parent.width
                height: 100
                border.color: "darkCyan"
                Item {
                    anchors.fill: parent
                    Column {
                        id: row1
                        spacing: 10
                        Text {text: '<b>userId:</b>'+userId}
                        Text {text: '<b>id:</b>'+id}
                        Text {text:'<b>title:</b>'+title}
                        Text {text: '<b>body:</b>'+body}
                    }
                }
            }
            highlight: Rectangle { color: "lightsteelblue" ; radius: 5 }
            focus: true
            model:listModel
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
