import QtQuick 2.0

Item {
    anchors.fill: parent

    ModelData
    {
        id:modeldata
    }
    ModelDel
    {
        id:del
        //error  when create , the data not map
    }

    ListView
    {
        anchors.fill: parent
        spacing: 10
        header: ModelHeadView{
            id:iHead
        }
        model:modeldata
        delegate: ModelDel{

        }
    }

}
