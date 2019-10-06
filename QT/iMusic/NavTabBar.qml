import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    TabBar {
        id: bar
        width: parent.width
        spacing: 15
        Repeater {

            model: ["Recommend", "RankList", "LocalMusic", "LatestMusic"]

            TabButton {
                text: modelData
                width: Math.max(100, bar.width / 5)
            }
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
