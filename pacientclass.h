/**
 * @file pacientclass.h
 * @date Apr 23, 2020
 * @author <b>Ing. Luis Alejandro Reyes Morales.</b>
 *
 * @brief
 *
 * This class implements the PacientClass. This a data type that keeps the information of one pacient.
 * The Database keeps the data save with this format
 */

#ifndef PACIENTCLASS_H
#define PACIENTCLASS_H

#include <QtCore>

class PacientClass
{
    const QString fecha_format = "yyyy-MM-dd HH:mm:ss";
    const QString date_format = "yyyy-MM-dd";
    const QString time_format = "HH:mm:ss";

    const QString nombre_key = "nombre";
    const QString edad_key = "edad";
    const QString ID_key = "ID";
    const QString sexo_key = "sexo";
    const QString birth_date_key = "birth_date";
    const QString date_key = "date";
    const QString time_key = "time";
    const QString estado_key = "estado";
    const QString weight_key = "peso";
    const QString height_key = "estatura";
    const QString comentarios_key = "comentarios";

public:
    PacientClass(QString name="",QString age= "");
//    PacientClass(const PacientClass &);

    void setFolderPacient();

    void operator_equal(QJsonObject jsonObject_pacient);
    bool is_equal(PacientClass &);

    bool write_file();
    QJsonObject read_file();
    QStringList read_LOG_parameters_in_DAT_file();

    void print_pacient_data();

    void operator_equal(const PacientClass &other_pacient);

    QString ID;
    QString age_pacient;
    QString name_pacient;
    bool has_name = false;
    QString height ="0";
    QString weight ="0";
    QString sexo_paciente;
    QString estado_paciente;
    QString comentarios = "";
    QDate birth_date_paciente;
    QDate date_paciente; //fecha de creacion de objecto paciente
    QTime time_paciente; //Hora de creacion de objecto paciente

//    bool write_file_Respiracion(QJsonObject jsonObject);
    bool write_file_log();
    bool write_LOG(QString log);

    long long read_file_function_data(double *data, int size, long long pos);
    void setFileFunctionNameCurrentTime();
    QString getMainDir(){return main_dir;}

    void setName(QString name);
public slots:
    bool write_file_function_data(double *data, int size);

    bool write_LOG_parameters_in_DAT_file(QString parameters);
private:
    QJsonObject jsonObjectPacient;
    QJsonObject jsonObjectRespiracion;

    QString main_dir;
    QString file_info_log_name_txt = ""; //archivo del LOG
    QString file_info_log_name_dat = ""; //archivo del LOG
    QString file_info_log_name_data_dat = ""; //archivo del LOG
    QString file_info_function_data_dat = ""; //archivo del LOG
};


#endif // PACIENTCLASS_H
