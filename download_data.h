#ifndef DOWNLOAD_DATA_H
#define DOWNLOAD_DATA_H

#include <QWidget>
#include <QDir>
#define LOGS_IN_SCREEN 9

class MainWindow;

namespace Ui {
class Download_Data;
}

class Download_Data : public QWidget
{
    Q_OBJECT

public:
    explicit Download_Data(QWidget *parent = nullptr, QString pacient_name = "Ale");
    ~Download_Data();
    static bool copyRecursively(const QString &srcFilePath, const QString &tgtFilePath);
    MainWindow* getMainWindowInstance();
signals:
    void stopAnimation();
private slots:
    void on_listWidget_pressed(const QModelIndex &index);

    void on_l_descargar_todos_clicked();

    void on_l_descargar_paciente_clicked();

    void on_l_eject_memory_clicked();

    void on_l_down_trigger_clicked();

    void on_l_up_trigger_clicked();

    void onScrollerChanged(int value);
    void selectedDrive(QString drive);
    void initCopyPacient();
    void initCopyAll();
private:
    Ui::Download_Data *ui;
    QString searchDrivesAndCreateDir(QDir &dir);
    QString folder_to_copy = "";
    QString dir_pacientes = "";
    QString dir_paciente = "";
    QStringList lista_pacientes;
    QString paciente_seleccionado = "";
    void searchData(QString dir_destiny);
    QStringList searchPacientsData(QString dir_source);

    int current_page = 0;

    QString getCurrentPageString(int currentPage);

    bool checkIfUSBConnected();
    QString selected_drive = "";
    QString drivePath = "";
    QString rootFolder = "/media/pi/";
    void setCopyingState(float state);
    QString removeUSBMocks();
};

#endif // DOWNLOAD_DATA_H
