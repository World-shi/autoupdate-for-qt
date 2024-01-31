#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "download.h"
#include "checkversion.h"
#include "handleziptype.h"
#include "globalval.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QProcess>
#include <QSettings>
#include <QStyleOption>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Download;
class CheckVersion;
class GlobalVal;
class HandleZipType;
class QProcess;
class QSettings;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void appendProgressMsg(QString msg);
   //void closeEvent(QCloseEvent *event) override;

private slots:
    void on_chkUpgradeBtn_clicked();
    void on_nowUpgradeBtn_clicked();
    void receiveMsgDate(QString msg);
    void receiveMsgDateln(QString msg);
    void upgradeBtnReset(int status);
    void quitApp();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
private:
    Ui::MainWindow *ui;
    Download *download;
    CheckVersion *cv;
    HandleZipType *handleZip;
    QPoint clickPos;
    void syncVersion();
    void startMainApp();
    void startUpgrade();
    void deleteDir(const QString& path);
    void readAutoUpdateFile(int& verNum, QString& appName, QString& upgradeUrl);
};
#endif // MAINWINDOW_H
