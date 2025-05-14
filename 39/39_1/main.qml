import QtQuick 2.12
import QtQuick.Window 2.12


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id:scene
        anchors.fill: parent
        //state: "CurrentState"


        Rectangle {
            id: leftRectangle
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            Text {
                id: name1
                anchors.centerIn: parent
                text: "move"
            }

            MouseArea {
                anchors.fill: parent
                onClicked:
                    if (ball.x + ball.width < rightRectangle.x) {
                        ball.x += 10
                        scene.state = "CurrentState"
                    }
                    else
                        scene.state = "InitialState"
           }

        }

        Rectangle {
            id: rightRectangle
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5

            Text {
                id: name2
                anchors.centerIn: parent
                text: "return"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "InitialState"
            }
        }

        Rectangle {
            id: ball
            color: "darkgreen"
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            radius: width / 2
        }

        states: [
            State {
                name: "CurrentState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            },

            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            }
        ]

        transitions: [
            Transition {
                from: "CurrentState"
                to: "InitialState"
                NumberAnimation {
                    properties: "x,y"
                    duration: 500
                    easing.type: Easing.OutElastic
                }
            }
        ]
    }
}

















