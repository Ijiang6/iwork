import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0
import com.i.JsonCpp 1.0
Item {
   signal sig_musicListIem(string id)
    JsonCpp
    {
        id:jsonModel
        onSig_updateitem:
        {
          updateGridView()
        }
    }
    ListModel
    {
        id:musicinfoModel
    }
    function updateGridView()
    {
        console.log("receive Sig")
      //musicinfoModel.append({"name": "情绪河豚 | 不要温和地\n走进那个墨绿的夜", "Imageurl":"icons/Icons/7.jpg"});
    }
    GridView {
        anchors.fill: parent
        id: gridView1
        cellHeight:300
        cellWidth: 300
        model:musicinfoModel
        delegate: MusicListItem
                    {
                        imgUrl: Imageurl
                        playNum: "9999"
                        description: name
                        userId:index
                        onSig_clickItem:
                        {
                            console.log("click Item"+id)
                            emit:sig_musicListIem(id)
                        }

                    }

            }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
