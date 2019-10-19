import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick .Controls 1.2
import QtQuick .Layouts 1.2
Rectangle
{
    signal sig_musitcID(string sID)
    id:musicpicture
    color:"white"
 ListModel{
        id:imodel
    }
 function updateModelData(sJson )
 {
     imodel.append(sJson)
 }
    property int  itemCount: 6
    PathView
    {
        id:pathview
        model:imodel
        delegate:imageCard
        path:musicpicturepath
        pathItemCount: 10
        anchors.fill: parent
        preferredHighlightBegin:   0.5
        preferredHighlightEnd: 0.5
    }
    Component
    {
        id:imageCard
        Item {
            id: delegateItem
            width:400
            height: 300
            z:PathView.iconZ
            scale: PathView.iconScale

                    Image
                    {
                        id:image
                        source:imagepath
                        width: delegateItem.width
                        height: delegateItem.height
                        objectName: stringID
                        MouseArea
                        {
                            id:mouse
                            anchors.fill: parent
                            onDoubleClicked:
                            {
                                emit:sig_musitcID(image.objectName)
                            }
                        }
                        Text{
                            id:sName
                            text:name
                            anchors.left: parent.left
                            anchors.bottom: parent.bottom
                        }
                    }
                   ShaderEffect
                    {
                        anchors.top:image.bottom
                        anchors.left: image.left
                        width: image.width
                        height: image.height
                        property variant source: image
                        property size sourceSize: Qt.size(0.5/image.width,0.5/image.height)
                        fragmentShader: "varying highp vec2 qt_TexCoord0;
                                uniform lowp sampler2D source;
                                uniform lowp vec2 sourceSize;
                                uniform lowp float qt_Opacity;
                                void main() {

                                    lowp vec2 tc = qt_TexCoord0 * vec2(1, -1) + vec2(0, 1);
                                    lowp vec4 col = 0.25 * (texture2D(source, tc + sourceSize) + texture2D(source, tc- sourceSize)
                                    + texture2D(source, tc + sourceSize * vec2(1, -1))
                                    + texture2D(source, tc + sourceSize * vec2(-1, 1)));
                                    gl_FragColor = col * qt_Opacity * (1.0 - qt_TexCoord0.y) * 0.2;
                                }"

                    }
                    transform: Rotation
                    {
                        origin.x:image.width/1.0
                        origin.y:image.height/2.0
                        angle:delegateItem.PathView.iconAngle
                        axis{
                            x:0
                            y:1
                            z:0
                         }
                    }
       }
    }
    Path
    {
        id:musicpicturepath
        startX: 0
        startY: musicpicture.height/3
        PathAttribute
        {
            name:"iconZ"
            value: 0
        }
        PathAttribute
        {
            name:"iconAngle"
            value: 70
        }
        PathAttribute
        {
            name:"iconScale"
            value: 0.6
        }
        PathLine
        {
            x:musicpicture.width/2
            y:musicpicture.height/3
        }
        PathAttribute
        {
            name:"iconZ"
            value: 100
        }
        PathAttribute
        {
            name:"iconAngle"
            value: 0
        }
        PathAttribute
        {
            name:"iconScale"
            value: 1.0
        }
        PathLine
        {
            x:musicpicture.width
            y:musicpicture.height/3
        }
        PathAttribute
        {
            name:"iconZ"
            value: 0
        }
        PathAttribute
        {
            name:"iconAngle"
            value: -70
        }
        PathAttribute
        {
            name:"iconScale"
            value: 0.6
        }
        PathPercent
        {
            value:1.0
        }

    }

}
