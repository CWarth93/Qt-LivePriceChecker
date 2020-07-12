import QtQuick 2.13

Item
{
    property string currency: ""

    Rectangle
    {
        color: "silver"
        border.color: "black"
        border.width: width * 0.02
        anchors.fill: parent

        Image
        {
            x: parent.width * 0.1
            width: parent.width * 0.3
            height: width
            anchors.verticalCenter: parent.verticalCenter
            source: "../img/"  + currency + ".png"
        }

        Text
        {
            text: currency
            x: parent.width * 0.5
            y: parent.height * 0.1
            font.pixelSize: parent.height * 0.1
        }

        Text
        {
            id: priceField
            text: ""
            x: parent.width * 0.5
            y: parent.height * 0.5
            font.pixelSize: parent.height * 0.05
        }
    }

    Connections
    {
        target: priceMachine
        onUpdated:
        {
            priceField.text = priceMachine.getPrice(currency);
        }
    }

}
