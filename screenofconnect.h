#ifndef SCREENOFCONNECT_H
#define SCREENOFCONNECT_H

#include <QBluetoothDeviceInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QMap>
#include <QListWidgetItem>
#include <QBluetoothSocket>


namespace Ui {
class screenOfConnect;
}

class screenOfConnect : public QWidget
{
    Q_OBJECT

public:
    explicit screenOfConnect(QWidget *parent = nullptr);
    ~screenOfConnect();

    void refresh();

    void startDeviceDiscovery();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_cmb_proximos_currentTextChanged(const QString &arg1);



    void on_listWidget_itemClicked(QListWidgetItem *item);

public slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void retrievingInfo();
private:
    Ui::screenOfConnect *ui;
    QString m_nameDevice;
    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent;
    QMap<QString, QString> m_listDevices;
    QBluetoothSocket *m_socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
};

#endif // SCREENOFCONNECT_H
