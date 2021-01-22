#include "log_information.h"
#include "ui_log_information.h"
#include <QScrollerProperties>
#include <QScroller>
#include "globals_settings.h"
#include <QAbstractItemModel>
#include <QStandardItemModel>
#include <QDebug>
#include "math.h"
#include <QScrollBar>

Log_Information::Log_Information(QWidget *parent, QStringList log_list) :
    QWidget(parent),
    ui(new Ui::Log_Information)
{
    ui->setupUi(this);
    logs = log_list;

    if(!logs.isEmpty()){

        addListToWidget(logs);

        //        QScrollerProperties sp;

        //        sp.setScrollMetric(QScrollerProperties::DragVelocitySmoothingFactor, 0.6);
        //        sp.setScrollMetric(QScrollerProperties::MinimumVelocity, 0.0);
        //        sp.setScrollMetric(QScrollerProperties::MaximumVelocity, 0.5);
        //        sp.setScrollMetric(QScrollerProperties::AcceleratingFlickMaximumTime, 0.4);
        //        sp.setScrollMetric(QScrollerProperties::AcceleratingFlickSpeedupFactor, 1.2);
        //        sp.setScrollMetric(QScrollerProperties::SnapPositionRatio, 0.2);
        //        sp.setScrollMetric(QScrollerProperties::MaximumClickThroughVelocity, 0);
        //        sp.setScrollMetric(QScrollerProperties::DragStartDistance, 0.001);
        //        sp.setScrollMetric(QScrollerProperties::MousePressEventDelay, 0.5);
        ////        sp.setScrollMetric(QScrollerProperties::AxisLockThreshold, 1);

        //        QScroller* scroller = QScroller::scroller(ui->listWidget);

        //        scroller->grabGesture(ui->listWidget, QScroller::LeftMouseButtonGesture);

        //        scroller->setScrollerProperties(sp);
    }
    ui->listWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { width: 25px;}");
    ui->l_page->setText(getCurrentPageString(current_page));
    connect(ui->listWidget->verticalScrollBar(), &QScrollBar::valueChanged, this, &Log_Information::onScrollerChanged);
}
Log_Information::~Log_Information()
{
    delete ui;
}

void Log_Information::onScrollerChanged(int value){
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    double den = LOGS_IN_SCREEN;
    int currentPage;
    double div = ceil(num_rows/den);
    if(value >= num_rows - LOGS_IN_SCREEN){
        currentPage = static_cast<int>(div) - 1;
    }else{
        currentPage = static_cast<int>(value / den);
    }

    if(div < 1){
        div = 1;
    }
    QString view = QString::number(currentPage+1)+"/"+
            QString::number(static_cast<int>(div));
    ui->l_page->setText(view);

    current_page = currentPage;
}


void Log_Information::addLogEvent(QString evento){
    logs.prepend(evento);
    addListToWidget(logs);
}

void Log_Information::addListToWidget(QStringList logs){
    ui->listWidget->clear();
    ui->listWidget->addItems(logs);
    QAbstractItemModel* model = ui->listWidget->model();
    for (int i = 0; i < logs.size(); i++) {
        QString evento = logs.at(i);

        QModelIndex index = model->index(i, 0, QModelIndex());
        if(evento.contains("alarma", Qt::CaseInsensitive)){
            if(evento.contains(" !!! ")){
                model->setData(index, color_high_priority, Qt::BackgroundRole);
                model->setData(index, QColor(Qt::white), Qt::ForegroundRole);
            }
            //            else if(evento.contains(" !! ")){
            //                model->setData(index, color_medium_priority, Qt::BackgroundRole);
            //                model->setData(index, QColor(Qt::black), Qt::ForegroundRole);
            //            }else if(evento.contains(" ! ")){
            //                model->setData(index, color_low_priority, Qt::BackgroundRole);
            //                model->setData(index, QColor(Qt::black), Qt::ForegroundRole);
            //            }
        }
    }
}

QString Log_Information::getCurrentPageString(int currentPage){
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    double den = LOGS_IN_SCREEN;
    double div = ceil(num_rows/den);
    if(div < 1){
        div = 1;
    }
    QString view = QString::number(currentPage+1)+"/"+
            QString::number(static_cast<int>(div));
    return view;
}
void Log_Information::on_l_down_trigger_clicked()
{
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    if(current_page > 0){
        current_page--;
    }
    if(num_rows > current_page*LOGS_IN_SCREEN){
        ui->listWidget->scrollToItem(ui->listWidget->item(current_page*LOGS_IN_SCREEN),
                                     QAbstractItemView::PositionAtTop);
    }
//    ui->l_page->setText(getCurrentPageString(current_page));
}

void Log_Information::on_l_up_trigger_clicked()
{
    QAbstractItemModel* model = ui->listWidget->model();
    int num_rows = model->rowCount();
    if(num_rows > (current_page + 1)*LOGS_IN_SCREEN){
        current_page++;
    }
    if(num_rows > current_page*LOGS_IN_SCREEN){
        ui->listWidget->scrollToItem(ui->listWidget->item(current_page*LOGS_IN_SCREEN),
                                     QAbstractItemView::PositionAtTop);
    }
//    ui->l_page->setText(getCurrentPageString(current_page));
}
