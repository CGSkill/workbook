import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.4
import Qt.labs.platform 1.1
import QtQuick .Controls 1.2

ApplicationWindow{
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {

        Menu {
            title: "换肤"
            MenuItem {
                text: "one"
                onTriggered:  {
                }
            }
            MenuItem {
                text: "two"
                onTriggered:  {
                }
            }
            MenuItem {
                text: "three"
                onTriggered:  {
                }
            }
            MenuItem {
                text: "four"
                onTriggered:  {
                }
            }
            MenuItem {
                text: "five"
                onTriggered:  {
                }
            }

        }

        Menu {
            title: "Edit"
            MenuItem { text: "Cut" }
            MenuItem { text: "Copy" }
            MenuItem { text: "Paste" }
        }

    }


}
