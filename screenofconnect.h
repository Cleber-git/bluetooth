#ifndef SCREENOFCONNECT_H
#define SCREENOFCONNECT_H

#include <QBluetoothDeviceInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QWidget>
#include <QString>
#include <QDebug>


namespace Ui {
class screenOfConnect;
}

class screenOfConnect : public QWidget
{
    Q_OBJECT

public:
    explicit screenOfConnect(QWidget *parent = nullptr);
    ~screenOfConnect();

    void retrievingInfo();

    void refresh();

    void startDeviceDiscovery();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
private:
    Ui::screenOfConnect *ui;
    QString m_nameDevice;
    QBluetoothDeviceDiscoveryAgent *m_discoveryAgent;
};

#endif // SCREENOFCONNECT_H
