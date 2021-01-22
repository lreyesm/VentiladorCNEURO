#ifndef LOG_INFORMATION_H
#define LOG_INFORMATION_H

#include <QWidget>

#define LOGS_IN_SCREEN 12
namespace Ui {
class Log_Information;
}

class Log_Information : public QWidget
{
    Q_OBJECT

public:
    explicit Log_Information(QWidget *parent = nullptr, QStringList log_list = QStringList());
    ~Log_Information();

public slots:
    void addLogEvent(QString evento);
private slots:
    void on_l_down_trigger_clicked();

    void on_l_up_trigger_clicked();

    void onScrollerChanged(int value);
private:
    Ui::Log_Information *ui;
    QStringList logs;
    void addListToWidget(QStringList logs);
    int current_page = 0;

    QString getCurrentPageString(int currentPage);
};

#endif // LOG_INFORMATION_H
