import QtQuick 2.0
import QtQuick.Layouts 1.0
Item {
    anchors.fill: parent
    Grid
    {
        spacing: 15
        columns: 3
        rows:3
        Repeater
        {
            model:9

            Rectangle
            {
                id:index
                width :80
                height: 60
                color: "cyan"
            }
        }
    }


}
