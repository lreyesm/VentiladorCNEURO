#ifndef UPDATER_H
#define UPDATER_H

#include <QWidget>
#include <QDir>

namespace Ui {
class Updater;
}

class Updater : public QWidget
{
    Q_OBJECT

public:
    explicit Updater(QWidget *parent = nullptr);
    ~Updater();

private slots:
    void on_pb_update_arduino_clicked();

    void on_pb_update_raspberry_pi_qt_clicked();

    void on_pb_close_clicked();

private:
    Ui::Updater *ui;
    void updateVentilatorQt(QString dir_source, QString dir_destiny);
    void updateVentilatorArduino(QString dir_source);

    QStringList searchIntoDrives(QStringList &list_Drives, QDir &dir);
    QStringList searchIntoFolders(QStringList list_folders, QDir &dir);
    QStringList searchFilesAndLoadUpdateQt(QStringList list_files, QDir &dir, QString dir_destiny);

    bool searchFilesAndLoadUpdateArduino(QStringList list_files, QDir &dir);
};

#endif // UPDATER_H
