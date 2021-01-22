#ifndef PLOT_H
#define PLOT_H

#include <QtCore/QObject>
#include <QtGui/QScreen>
#include <QtGui/QWindow>
#include <QtGui/QPaintEvent>
#include <QtGui/QResizeEvent>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLFunctions_3_0>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QSurfaceFormat>

#include "qcustomplot.h"

class Plot: public QCustomPlot , protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit Plot(QWidget *parent  = nullptr, int radio_point = 15);

    bool isPaused(){return paused;}

protected:

    virtual void initializeGL() override
    {
        initializeOpenGLFunctions();
    }

    virtual void paintGL() override
    {
        //glClearColor(0.f, 0.15f, 0.05f, 0.f);
        //glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, width()/2, height()/2); //works!!
    }
    virtual void resizeGL(int w, int h) override
    {
        glViewport(0, 0, w/2, h/2); //doesn't work
    }

protected slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:

    void setup_Graph();

    void clear_Data();

    QVector<double> getVerticalGraph(int x_coord);
    void add_Data(quint8 graph_i, float x, float y);
    void add_Data(quint8 graph_i, double x, double y);
    void add_Data(quint8 graph_i=0, quint32 x =0, quint32 y =0);
    void add_Data(quint8 graph_i, QVector<double> x_vector, QVector<double> y_vector);
    void add_Data(quint8 graph_i, QVector<double> y_vector);

    void set_Range_x_axis_initial(int min, int max){ x_axis_initial_range = QCPRange(min, max); this->xAxis->setRange(min, max);
                                                     if(this->graphCount() > 0){ this->graph(0)->removeDataAfter(max);}}
    void set_Range_x_axis(QCPRange range){ x_axis_range = range; this->xAxis->setRange(range);
                                           if(this->graphCount() > 0){ this->graph(0)->removeDataAfter(range.upper);}}
    void set_Range_x_axis(int min, int max){ x_axis_range = QCPRange(min, max); this->xAxis->setRange(min, max);
                                             if(this->graphCount() > 0){ this->graph(0)->removeDataAfter(max);}}
    void set_Range_y_axis_initial(int min, int max){ y_axis_initial_range = QCPRange(min, max); this->yAxis->setRange(min, max);}
    void set_Range_y_axis(QCPRange range){ y_axis_range = range; this->yAxis->setRange(range);}
    void set_Range_y_axis(int min, int max){ y_axis_range = QCPRange(min, max); this->yAxis->setRange(min, max);}

    QCPRange x_axis_Range(){ return x_axis_range;}
    QCPRange y_axis_Range(){ return y_axis_range;}
    QCPRange x_axis_initial_Range(){ return x_axis_initial_range;}
    QCPRange y_axis_initial_Range(){ return y_axis_initial_range;}

    QVector<double> setHorizontalLimitLine(int y_coord);

public slots:
    void pauseGraph(){ paused = true;}
    void playGraph(){ paused = false;}

    void updateGraph(bool force_replot = false);

signals:
    void pressEvent(QMouseEvent*);
    void releaseEvent(QMouseEvent*);
    void pressAndHold();
    void shiftStateChanged(bool);
    void maximize_graph_signal(int);
    void minimize_graph_signal(int);

//protected:

//    bool event(QEvent *event);

private slots:
    void emitPressAndHold();

private:
    QTimer pressAndHoldTimer;

    QCPRange x_axis_initial_range;
    QCPRange y_axis_initial_range;

    QCPRange x_axis_range;
    QCPRange y_axis_range;

    bool paused = false;

};

#endif // PLOT_H
