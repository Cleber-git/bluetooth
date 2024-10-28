#ifndef SCREENOFCONNECT_H
#define SCREENOFCONNECT_H

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void refresh();

private:
    Ui::screenOfConnect *ui;
    QString m_nameDevice;
};

#endif // SCREENOFCONNECT_H
