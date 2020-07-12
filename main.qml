import QtQuick 2.13
import QtQuick.Window 2.13

import "./qml"

Window
{
    id: root
    visible: true
    width: Screen.width * 0.6
    height: Screen.height * 0.7
    title: "LivePriceChecker"

    CurrencyTab
    {
        id: bitcoinTab
        x: parent.width * 0.1
        width: parent.width * 0.3
        y: parent.height * 0.1
        height: parent.height * 0.3
        currency: "bitcoin"
    }

    CurrencyTab
    {
        id: ethereumTab
        x: parent.width * 0.6
        width: parent.width * 0.3
        y: parent.height * 0.1
        height: parent.height * 0.3
        currency: "ethereum"
    }

    CurrencyTab
    {
        id: rippleTab
        x: parent.width * 0.1
        width: parent.width * 0.3
        y: parent.height * 0.6
        height: parent.height * 0.3
        currency: "ripple"
    }

    CurrencyTab
    {
        id: stellarTab
        x: parent.width * 0.6
        width: parent.width * 0.3
        y: parent.height * 0.6
        height: parent.height * 0.3
        currency: "stellar"
    }

    Timer
    {
        interval: 2500
        running: true
        repeat: true
        onTriggered:
        {
            if(priceMachine.isInitialized())
            {
                priceMachine.update();
            }
        }
    }

}
