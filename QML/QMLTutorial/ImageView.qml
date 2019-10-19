import QtQuick 2.0

Item {
    id:root
   Image
   {
       id:image
       source: "https://ss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=2068181080,433513959&fm=26&gp=0.jpg"
      anchors.horizontalCenter: root.horizontalCenter
       sourceSize.width: root.width /2
       sourceSize.height: root.height /2
       onProgressChanged:
       {
           if( progress <1)
           {
               textTip.text="Loading"
           }
       }
       onStatusChanged:
       {
           if( status === Image.Ready)
           {
               textTip.text = "Your Image is Loaded from \n"+source
           }
       }


   }
   Text
   {
       id:textTip
       anchors
       {
           top:image.bottom
           topMargin:20
       }
   }

}
