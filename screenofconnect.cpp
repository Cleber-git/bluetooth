#include "screenofconnect.h"
#include "ui_screenofconnect.h"

#include <QBluetoothLocalDevice>
#include <QBluetoothAddress>
#include <QBluetoothPermission>
#include <QByteArray>
#include <QLowEnergyController>
#include <QLoggingCategory>

screenOfConnect::screenOfConnect(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::screenOfConnect)
{
    ui->setupUi(this);

    // Create a discovery agent and connect to its signals
    m_discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(m_discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth.*=true"));
    ui->cmb_proximos->hide();
    ui->label_2->hide();
}

screenOfConnect::~screenOfConnect()
{
    delete ui;
}

void screenOfConnect::retrievingInfo(){

    QBluetoothLocalDevice localDevice;

    // verificar se existe algum
   // serviço de bluetooth
  // disponível no dispositivo

    qDebug() << localDevice.name();

    if(localDevice.isValid()){

        // Habilitar o Bluetooth
        localDevice.powerOn();

        m_nameDevice = localDevice.name();

        // tornando-o visível para os outros dispositivos
        localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

        // Mostrar qual item está atualmente conectado
        QList<QBluetoothAddress> remotes;
        remotes = localDevice.connectedDevices();
        for(auto bConnected : remotes){
            ui->cmb_connectado->addItem( m_nameDevice );
        }
    }
}

void screenOfConnect::on_pushButton_clicked(){
    QByteArray data = QByteArray::fromStdString(ui->lineEdit->text().toStdString());
    qDebug() << data;

    m_socket->write(data);
    // m_socket.flush();

    QObject::connect(m_socket, &QBluetoothSocket::readyRead, [&]() {
        qDebug() << "Received response";
    });
    QLowEnergyController *controller;
    controller->discoverServices();
    QObject::connect(controller, &QLowEnergyController::serviceDiscovered, [](const QBluetoothUuid &uuid) {
        qDebug() << "Serviço disponível:" << uuid.toString();
    });
}

void screenOfConnect::on_pushButton_2_clicked(){
    startDeviceDiscovery();
}

void screenOfConnect::refresh(){

}

void screenOfConnect::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    if(ui->cmb_proximos->findText(device.name()) == -1){
        qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';

        m_listDevices[device.name()] = device.address().toString();
        ui->listWidget->addItem( device.name());
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

void screenOfConnect::on_cmb_proximos_currentTextChanged(const QString &arg1)
{

}

void screenOfConnect::on_listWidget_itemClicked(QListWidgetItem *item)
{

    m_socket->disconnectFromService();
    m_nameDevice = item->text();
    QString add = m_listDevices[m_nameDevice];
    qDebug() << add;
    QBluetoothAddress address(add);
    m_socket->connectToService(address, 1);

    connect(m_socket, &QBluetoothSocket::connected, this, &screenOfConnect::retrievingInfo);
    disconnect(m_discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
               this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
}

