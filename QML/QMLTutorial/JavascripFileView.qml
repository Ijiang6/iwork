import QtQuick 2.0
import "/script/JavaScript/ImageError.js" as Utils
Item {
    Image {
        anchors.fill: parent
        id: img
        source: "file"
        onStatusChanged:
        {
            if(status === Image.Error)
            {
                source=Utils.imgurl
            }

        }
    }
}
