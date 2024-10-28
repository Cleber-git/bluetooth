#include "screenofconnect.h"
#include "ui_screenofconnect.h"

#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothAddress>

screenOfConnect::screenOfConnect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::screenOfConnect)
{
    ui->setupUi(this);

}

screenOfConnect::~screenOfConnect()
{
    delete ui;
}

void screenOfConnect::retrievingInfo(){

    QBluetoothLocalDevice localDevice;

    // verificar se existe algum serviço de bluetooth
    // disponível no dispositivo
    qDebug() << localDevice.name();

    if(localDevice.isValid()){
        // Habilitar o Bluetooth
        localDevice.powerOn();

        m_nameDevice = localDevice.name();

        // tornando-o visível para os outros dispositivos
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // obter lista de dispositivos próximos
        QList<QBluetoothAddress> remotes;
        remotes = localDevice.connectedDevices();
        for(auto bConnected : remotes){
            ui->cmb_connectado->addItem(bConnected.toString());
        }
    }
}

void screenOfConnect::on_pushButton_clicked(){
    retrievingInfo();
}

void screenOfConnect::on_pushButton_2_clicked(){

}

void screenOfConnect::refresh(){

}
