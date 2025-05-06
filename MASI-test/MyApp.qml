import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    width: 600
    height: 350

    // Dane dla pionu i poziomu niezależnie
    property string input1: ""
    property string input2: ""
    property string inputW: ""

    property string hInput1: ""
    property string hInput2: ""
    property string hInputW: ""

    property string substitutionTarget: ""
    property bool showSubstitution: false

    // Dialog do wpisania danych
    Dialog {
        id: inputDialog
        title: "Wprowadź dane (pionowo)"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        visible: false
        onAccepted: {
            input1 = field1.text
            input2 = field2.text
            inputW = field3.text
        }

        contentItem: ColumnLayout {
            spacing: 10


            TextField { id: field1; placeholderText: "Wyraz 1" }
            TextField { id: field2; placeholderText: "Wyraz 2" }
            TextField { id: field3; placeholderText: "w - ?" }
        }
    }
    Dialog {
        id: substitutionDialog
        title: "Wybierz rodzaj zamiany"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        visible: false
        onAccepted: {
            showSubstitution = true
        }

        contentItem: ColumnLayout {
            spacing: 10
            RadioButton {
                text: "Zamiana za A"
                checked: true
                onClicked: substitutionTarget = "A"
            }
            RadioButton {
                text: "Zamiana za B"
                onClicked: substitutionTarget = "B"
            }
        }
    }


    Dialog {
        id: horizontalDialog
        title: "Wprowadź dane (poziomo)"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        visible: false
        onAccepted: {
            hInput1 = hField1.text
            hInput2 = hField2.text
            hInputW = hField3.text
        }

        contentItem: ColumnLayout {
            spacing: 10


            TextField { id: hField1; placeholderText: "Wyraz A" }
            TextField { id: hField2; placeholderText: "Wyraz B" }
            TextField { id: hField3; placeholderText: "u - ?" }
        }
    }

    RowLayout {
        anchors.fill: parent
        anchors.margins: 20

        // Lewa kolumna – pionowa linia + dane
        Column {
            width: 150
            spacing: 10
            anchors.verticalCenter: parent.verticalCenter

            // Pionowa kreska z daszkiem i stopką
            Canvas {
                id: kreskaCanvas
                width: 20
                height: 120
                onPaint: {
                    var ctx = getContext("2d")
                    ctx.clearRect(0, 0, width, height)
                    ctx.strokeStyle = "black"
                    ctx.lineWidth = 2

                    ctx.beginPath()
                    ctx.moveTo(width/2, 5)
                    ctx.lineTo(width/2, height - 5)
                    ctx.stroke()

                    ctx.beginPath()
                    ctx.moveTo(0, 5)
                    ctx.lineTo(width, 5)
                    ctx.moveTo(0, height - 5)
                    ctx.lineTo(width, height - 5)
                    ctx.stroke()
                }
            }

            // Teksty obok kreski
            Column {
                spacing: 8
                anchors.left: kreskaCanvas.right
                anchors.leftMargin: 10

                Text { text: input1; visible: input1 !== "" }
                Text { text: ";" ; visible: input1 !== "" }
                Text { text: input2; visible: input2 !== "" }
                Text { text: ";" ; visible: input2 !== "" }
                Text { text: inputW + " - ?"; visible: inputW !== "" }
            }

            // Przerwa między pionem a poziomem
            Rectangle { height: 20; width: 1; color: "transparent" }

            // Pozioma linia z daszkiem i stopką oraz tekstem pod spodem
            Column {
                spacing: 5
                visible: hInput1 !== ""

                Canvas {
                    width: 120
                    height: 20
                    onPaint: {
                        var ctx = getContext("2d")
                        ctx.clearRect(0, 0, width, height)
                        ctx.strokeStyle = "black"
                        ctx.lineWidth = 2

                        ctx.beginPath()
                        ctx.moveTo(5, height/2)
                        ctx.lineTo(width - 5, height/2)
                        ctx.stroke()

                        ctx.beginPath()
                        ctx.moveTo(5, 0)
                        ctx.lineTo(5, height)
                        ctx.moveTo(width - 5, 0)
                        ctx.lineTo(width - 5, height)
                        ctx.stroke()
                    }
                }

                Row {
                    spacing: 10
                    Text { text: hInput1 }
                    Text { text: ";" }
                    Text { text: hInput2 }
                    Text { text: ";" }
                    Text { text: hInputW + " - ?" }
                }

            }
        } Rectangle {
            width: 250
            height: 180
            color: "transparent"
            visible: showSubstitution
            border.color: "transparent"

            Column {
                spacing: 8
                anchors.centerIn: parent

                // Górna linia z końcówkami
                Canvas {
                    width: 200
                    height: 20
                    onPaint: {
                        var ctx = getContext("2d")
                        ctx.clearRect(0, 0, width, height)
                        ctx.strokeStyle = "black"
                        ctx.lineWidth = 2

                        ctx.beginPath()
                        ctx.moveTo(5, height/2)
                        ctx.lineTo(width - 5, height/2)
                        ctx.stroke()

                        ctx.beginPath()
                        ctx.moveTo(5, 0)
                        ctx.lineTo(5, height)
                        ctx.moveTo(width - 5, 0)
                        ctx.lineTo(width - 5, height)
                        ctx.stroke()
                    }
                }

                Row {
                    spacing: 10

                    // Miejsce A
                    Item {
                        width: 60
                        Column {
                            spacing: 6
                            // jeśli zamiana za A — pokaż blok pionowy
                            visible: substitutionTarget === "A"
                            Canvas {
                                width: 20
                                height: 100
                                onPaint: {
                                    var ctx = getContext("2d")
                                    ctx.clearRect(0, 0, width, height)
                                    ctx.strokeStyle = "black"
                                    ctx.lineWidth = 2
                                    ctx.beginPath()
                                    ctx.moveTo(width/2, 5)
                                    ctx.lineTo(width/2, height - 5)
                                    ctx.stroke()
                                    ctx.beginPath()
                                    ctx.moveTo(0, 5)
                                    ctx.lineTo(width, 5)
                                    ctx.moveTo(0, height - 5)
                                    ctx.lineTo(width, height - 5)
                                    ctx.stroke()
                                }
                            }
                            Text { text: input1 }
                            Text { text: ";" }
                            Text { text: input2 }
                            Text { text: ";" }
                            Text { text: inputW + " - ?" }
                        }

                        Text {
                            visible: substitutionTarget !== "A"
                            text: hInput1
                        }
                    }

                    Text { text: ";" }

                    // Miejsce B
                    Item {
                        width: 60
                        Column {
                            spacing: 6
                            visible: substitutionTarget === "B"
                            Canvas {
                                width: 20
                                height: 100
                                onPaint: {
                                    var ctx = getContext("2d")
                                    ctx.clearRect(0, 0, width, height)
                                    ctx.strokeStyle = "black"
                                    ctx.lineWidth = 2
                                    ctx.beginPath()
                                    ctx.moveTo(width/2, 5)
                                    ctx.lineTo(width/2, height - 5)
                                    ctx.stroke()
                                    ctx.beginPath()
                                    ctx.moveTo(0, 5)
                                    ctx.lineTo(width, 5)
                                    ctx.moveTo(0, height - 5)
                                    ctx.lineTo(width, height - 5)
                                    ctx.stroke()
                                }
                            }
                            Text { text: input1 }
                            Text { text: ";" }
                            Text { text: input2 }
                            Text { text: ";" }
                            Text { text: inputW + " - ?" }
                        }

                        Text {
                            visible: substitutionTarget !== "B"
                            text: hInput2
                        }
                    }

                    Text { text: ";" }
                    Text { text: hInputW + " - ?" }
                }



                // pionowy blok wstawiony jako substytucja
                Row {
                    spacing: 10
                    Canvas {
                        width: 20
                        height: 120
                        onPaint: {
                            var ctx = getContext("2d")
                            ctx.clearRect(0, 0, width, height)
                            ctx.strokeStyle = "black"
                            ctx.lineWidth = 2
                            ctx.beginPath()
                            ctx.moveTo(width/2, 5)
                            ctx.lineTo(width/2, height - 5)
                            ctx.stroke()
                            ctx.beginPath()
                            ctx.moveTo(0, 5)
                            ctx.lineTo(width, 5)
                            ctx.moveTo(0, height - 5)
                            ctx.lineTo(width, height - 5)
                            ctx.stroke()
                        }
                    }

                    Column {
                        spacing: 6
                        Text { text: input1; visible: input1 !== "" }
                        Text { text: ";" ; visible: input1 !== "" }
                        Text { text: input2; visible: input2 !== "" }
                        Text { text: ";" ; visible: input2 !== "" }
                        Text { text: inputW + " - ?"; visible: inputW !== "" }
                    }

                }
            }
        }


        // Prawa kolumna – przyciski
        ColumnLayout {
            spacing: 10
            Layout.alignment: Qt.AlignTop

            Button {
                text: "➕ Dodaj pionowo"
                onClicked: inputDialog.open()
            }

            Button {
                text: "➕ Dodaj poziomo"
                onClicked: horizontalDialog.open()
            }
            Button {
                text: "🔁 Zamień"
                onClicked: substitutionDialog.open()
            }

        }
    }
}
