import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12


Window {
    width: 440
    height: 380
    visible: true
    title: qsTr("Player")

    Rectangle{
        id: playScreen
        height: 200
        color: "#b0c4de"
        anchors {
            top: parent.top
            right: parent.right
            left: parent.left
            leftMargin: 5
            rightMargin: 5
            topMargin: 5
         }
     }

     GridLayout{
         id: managementTools
         columns: 5
         rows: 1
         anchors {
             top: playScreen.bottom
             right: parent.right
             left: parent.left
             leftMargin: 10
             rightMargin: 10
             topMargin: 5
          }

         Button{
              id: btn_1
              height: 60
              width: 75
              hoverEnabled: false
              background: Rectangle{
                  color: "#c0c0c0"
                  border.color: "#000000"
                  implicitWidth: 75
                  implicitHeight: 60
                  Text{
                      text: "\u25b6"
                      color: btn_1.down ? "#000000":"#808080"
                      font.family: "Verdana";
                      font.pixelSize: 48;
                      anchors.centerIn: parent
                  }
              }
          }

         Button{
              id: btn_2
              height: 60
              width: 75
              hoverEnabled: false
              background: Rectangle{
                  color: "#c0c0c0"
                  border.color: "#000000"
                  implicitWidth: 75
                  implicitHeight: 60
                  Text{
                      //text: "\u2016"
                      //text: "\uU+23 F8 U+FE0F        "
                      text: "\u275A" + "\u275A"
                      color: btn_2.down ? "#000000":"#808080"
                      font.family: "Verdana";
                      font.pixelSize: 22;
                      anchors.centerIn: parent
                  }
              }
          }

         Button{
              id: btn_3
              height: 60
              width: 75
              hoverEnabled: false
              background: Rectangle{
                  color: "#c0c0c0"
                  border.color: "#000000"
                  implicitWidth: 75
                  implicitHeight: 60
                  Text{
                      text: "\u25A0"
                      color: btn_3.down ? "#000000":"#808080"
                      font.family: "Verdana";
                      font.pixelSize: 48;
                      anchors.centerIn: parent
                  }
              }
          }

         Button{
              id: btn_4
              height: 60
              width: 75
              hoverEnabled: false
              background: Rectangle{
                  color: "#c0c0c0"
                  border.color: "#000000"
                  implicitWidth: 75
                  implicitHeight: 60
                  Text{
                      text: "\u25c0" + "\u25c0"
                      color: btn_4.down ? "#000000":"#808080"
                      font.family: "Verdana";
                      font.pixelSize: 32;
                      anchors.centerIn: parent
                  }
              }
          }

         Button{
              id: btn_5
              height: 60
              width: 75
              hoverEnabled: false
              background: Rectangle{
                  color: "#c0c0c0"
                  border.color: "#000000"
                  implicitWidth: 75
                  implicitHeight: 60
                  Text{
                      text: "\u25b6" + "\u25b6"
                      color: btn_5.down ? "#000000":"#808080"
                      font.family: "Verdana";
                      font.pixelSize: 32;
                      anchors.centerIn: parent
                  }
              }
          }

        }

     ProgressBar{
         anchors {
             top: managementTools.bottom
             bottom: parent.bottom
             right: parent.right
             left: parent.left
             leftMargin: 10
             rightMargin: 10
             topMargin: 5
         }

    }

}
