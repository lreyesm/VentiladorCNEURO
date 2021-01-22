#include "plot.h"
#include <QDebug>

Plot::Plot(QWidget *parent, int radio_point)
    :QCustomPlot(parent)
{
    Q_UNUSED(radio_point);
}

void Plot::emitPressAndHold(){
    disconnect(&pressAndHoldTimer, &QTimer::timeout, this, &Plot::emitPressAndHold);
    qDebug()<<"Emiting pressAndHold";
    pressAndHoldTimer.stop();
    emit pressAndHold();
}

void Plot::mousePressEvent(QMouseEvent *event){
//    pressAndHoldTimer.setInterval(1000);
//    connect(&pressAndHoldTimer, &QTimer::timeout, this, &Plot::emitPressAndHold);
//    pressAndHoldTimer.start();
//    qDebug()<<"Started pressAndHold timer";
    QCustomPlot::mousePressEvent(event);
    emit pressEvent(event);
}

void Plot::mouseReleaseEvent(QMouseEvent *event){
//    disconnect(&pressAndHoldTimer, &QTimer::timeout, this, &Plot::emitPressAndHold);
//    pressAndHoldTimer.stop();
//    qDebug()<<"Stopped pressAndHold timer";
    QCustomPlot::mouseReleaseEvent(event);
    emit releaseEvent(event);
}

void Plot::updateGraph(bool force_replot){
    if(force_replot || !paused){
        this->replot();
    }
}

void Plot::setup_Graph(){
    this->addGraph();

    this->xAxis->setVisible(true);
    this->yAxis->setVisible(true);

    this->setBackground(QBrush(QColor(17,21,25))); //mismo fondo de app
    //this->setBackground(QBrush(QColor(Qt::white)));
    QPen pen = QPen(QColor(0, 204, 255).lighter(130)); //azul de curva
    pen.setWidth(2);
    this->graph(0)->setPen(pen);
    pen.setWidth(0);
    pen.setColor(QColor(30, 30, 30));
    this->xAxis->grid()->setPen(pen);
    this->yAxis->grid()->setPen(pen);

    //    this->se
    this->xAxis->setTickLabels(false);
    this->xAxis->setTicks(false);
    this->xAxis->setSubTickLength(0,0);
    this->xAxis->setTickLabelColor(QColor(Qt::white));

    this->yAxis->setTickLabels(true);
    this->yAxis->setSubTickLength(0,0);
    this->yAxis->setTickLabelFont(QFont("Din Pro", 10));
    this->yAxis->setTickLength(0, 5);
    this->yAxis->setTickPen(pen);
    this->yAxis->setTickLabelColor(QColor(Qt::white));
    this->yAxis->setLabelColor(QColor(Qt::white));
    //this->setAutoFillBackground(true);

    this->setPlottingHints(QCP::phFastPolylines | QCP::phCacheLabels /*|QCP::phForceRepaint*/);
    this->setAntialiasedElements(QCP::aeAll);

    this->addGraph(); //esta es la linea vertical de
    pen.setColor(QColor(Qt::white).lighter(130));
    this->graph(1)->setPen(pen);

    this->addGraph(); //esta es la linea horizontal de limite
    pen.setColor(QColor(Qt::red).lighter(130));
    this->graph(2)->setPen(pen);

    this->addGraph(); //esta es la linea horizontal de maximo
    //    pen.setStyle(Qt::DashLine);
    pen.setColor(QColor(Qt::red).lighter(130));
    this->graph(3)->setPen(pen);
    this->graph(3)->setLineStyle(QCPGraph::lsNone);
    this->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 2));


    this->addGraph(); //esta es la linea vertical de
    pen.setWidth(2);
    pen.setColor(QColor(Qt::green).lighter(130));
    this->graph(4)->setPen(pen);

    this->replot();
}

void Plot::clear_Data(){
    for(qint16 i=0; i<this->graphCount(); i++){
        this->graph(i)->data()->clear();
    }
    this->xAxis->setRange(x_axis_initial_range);
    this->replot();///*QCustomPlot::rpHint*/);
}

QVector<double> Plot::getVerticalGraph(int x_coord){  //funcion para crear linea de barrido

    int min = static_cast<int>(y_axis_initial_range.lower);
    int max = static_cast<int>(y_axis_initial_range.upper);
    int count = max-min;
    QVector<double> time_x_axis(count), y_axis(count);
    for(int i= 0; i< count; i++){
        time_x_axis[i]= x_coord;
        y_axis[i]=min;
        min++;
    }
    this->graph(1)->data()->clear();
    add_Data(1, time_x_axis, y_axis);
    return y_axis;
}

QVector<double> Plot::setHorizontalLimitLine(int y_coord){
    int min = static_cast<int>(x_axis_initial_range.lower);
    int max = static_cast<int>(x_axis_initial_range.upper);
    int count = max - min;
    int mod = static_cast<int>(static_cast<float>(max) / 40); //40 puntos en grafica

    QVector<double> time_x_axis(count), time_x_axis_maximun(count), y_axis_limit(count), y_axis_maximun(count);
    for(int i= 0; i< count; i++){
        if(i%mod==0){
            time_x_axis[i]= i;
            y_axis_limit[i]=y_coord;
        }
        time_x_axis_maximun[i]= i;
        y_axis_maximun[i] = 40;
    }
    this->graph(3)->data()->clear();
    add_Data(3, time_x_axis, y_axis_limit);
    this->graph(2)->data()->clear();
    add_Data(2, time_x_axis_maximun, y_axis_maximun);
    return y_axis_limit;
}

void Plot::add_Data(quint8 graph_i, float x, float y)
{
    this->graph(graph_i)->removeData(static_cast<double>(x));
    this->graph(graph_i)->addData(static_cast<double>(x),static_cast<double>(y));
    getVerticalGraph(static_cast<int>(x));//crea linea vertical de barrido
}

void Plot::add_Data(quint8 graph_i, double x, double y)
{
    this->graph(graph_i)->removeData(x);
    this->graph(graph_i)->addData(x,y);
    getVerticalGraph(static_cast<int>(x));//crea linea vertical de barrido
}

void Plot::add_Data(quint8 graph_i, quint32 x, quint32 y)
{
    this->graph(graph_i)->removeData(static_cast<double>(x));
    this->graph(graph_i)->addData(x,y);
    getVerticalGraph(static_cast<int>(x));//crea linea vertical de barrido
}

void Plot::add_Data(quint8 graph_i, QVector<double> x_vector, QVector<double> y_vector)
{
    this->graph(graph_i)->addData(x_vector,y_vector);
}

void Plot::add_Data(quint8 graph_i, QVector<double> y_vector)
{
    clear_Data();

    if(graph_i==0){

        QVector<double> x_vector;
        x_vector.clear();
        for(quint16 i=0; i< y_vector.length();i++){
            x_vector.append(i+1);
        }
        this->graph(graph_i)->addData(x_vector,y_vector);
    }
}
