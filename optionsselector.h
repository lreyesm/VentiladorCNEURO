#ifndef OPTIONSSELECTOR_H
#define OPTIONSSELECTOR_H

#include <QWidget>

namespace Ui {
class OptionsSelector;
}

class OptionsSelector : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsSelector(QWidget *parent = nullptr, QStringList options = QStringList());
    ~OptionsSelector();
    void addOptions(QStringList options = QStringList());
    void moveCenter();
signals:
    void selected_option(QString);
    void selected();
private slots:
    void emitSelectedItem(QString option);
private:
    Ui::OptionsSelector *ui;
};

#endif // OPTIONSSELECTOR_H
