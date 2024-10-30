#include "screenofconnect.h"
#include "ui_screenofconnect.h"

#include <QBluetoothLocalDevice>
#include <QBluetoothAddress>
#include <QBluetoothPermission>

screenOfConnect::screenOfConnect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::screenOfConnect)
{
    ui->setupUi(this);

    // Create a discovery agent and connect to its signals
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(m_discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

}

screenOfConnect::~screenOfConnect()
{
    delete ui;
}

void screenOfConnect::retrievingInfo(){

    QBluetoothLocalDevice localDevice;

    // verificar se existe algum
   //  serviço de bluetooth
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
    startDeviceDiscovery();
}

void screenOfConnect::refresh(){

}

void screenOfConnect::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
    if(ui->cmb_proximos->findText(device.name()) == -1){
        ui->cmb_proximos->addItem(device.name());
        return;
    }
    disconnect(m_discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
                this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
}

void screenOfConnect::startDeviceDiscovery(){


    // Start a discovery
    m_discoveryAgent->start();

}
