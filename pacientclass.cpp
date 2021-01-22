/**
 * @file pacientclass.cpp
 * @date Apr 23, 2020
 * @author <b>Ing. Luis Alejandro Reyes Morales.</b>
 *
 * @brief
 *
 * This class implements the PacientClass. This a data type that keeps the information of one pacient.
 * The Database keeps the data save with this format
 */
#include "pacientclass.h"
#include <QDebug>

//Constructor de la clase recibe el nombre de la madre y el del bebe como parametros-------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
PacientClass::PacientClass(QString name, QString age){

    ID = QDateTime::currentDateTime().toString("yyyyMMddHHmmss");
    sexo_paciente = "unknow";
    estado_paciente = "INICIO";

    if(name.isEmpty()){
        name = QDateTime::currentDateTime().toString(fecha_format);
        has_name = false;
    }else {
        has_name = true;
    }
    if(age.isEmpty()){
        age = "-1";
    }
    this->name_pacient = name;
    this->age_pacient = age;

    time_paciente = QTime::currentTime();
    date_paciente = QDate::currentDate();

    jsonObjectPacient.insert(ID_key, ID);
    jsonObjectPacient.insert(nombre_key, name_pacient);
    jsonObjectPacient.insert(edad_key, age_pacient);
    jsonObjectPacient.insert(sexo_key, "");
    jsonObjectPacient.insert(birth_date_key, "");
    jsonObjectPacient.insert(weight_key, weight);
    jsonObjectPacient.insert(height_key, height);
    jsonObjectPacient.insert(date_key, date_paciente.toString(date_format));
    jsonObjectPacient.insert(time_key, time_paciente.toString(time_format));
    jsonObjectPacient.insert(estado_key, estado_paciente);
    jsonObjectPacient.insert(comentarios_key, comentarios);

}
//PacientClass::PacientClass(const PacientClass &other_pacient){
//    operator_equal(other_pacient);
//}
//-----------------------------------------------------------------------------------------------------------------------



//Esta funcion me define los nombre de ficheros de los datos de paciente para luego guardarlos----------------------------
//-----------------------------------------------------------------------------------------------------------------------
void PacientClass::setName(QString name){
    name_pacient = name;
}
void PacientClass::setFolderPacient(){
    QString name_files = "";
    name_files =  name_pacient.replace(":", "_").replace("-", "_");
    QDir dir = QDir::current();
    dir.cdUp();
    dir.setPath(dir.path() + "/" + "Pacientes/" + name_files);
    if(!dir.exists()){
        dir.mkpath(dir.path());
    }
    main_dir = dir.path();

    file_info_log_name_txt = dir.path() + "/" + name_files + ".txt";  //log
    file_info_log_name_dat = dir.path() + "/" + name_files + ".dat";  //informacion de paciente
    file_info_log_name_data_dat = dir.path() + "/" + name_files + "_data.dat"; //informacion de parametros (eventos del log)
    file_info_function_data_dat = dir.path() + "/" + name_files + "_function_data"
            + QDateTime::currentDateTime().toString("yyyyMMddHHmmss")+ ".dat"; //graficas
}
//-----------------------------------------------------------------------------------------------------------------------

//Cambia el nobre del fichero de la funcion del paciente con la fecha-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void PacientClass::setFileFunctionNameCurrentTime(){
    QString name_files = "";
    name_files =  name_pacient.replace(":", "_").replace("-", "_");
    QDir dir = QDir::current();
    dir.cdUp();
    dir.setPath(dir.path() + "/" + "Pacientes/" + name_files);
    if(!dir.exists()){
        dir.mkpath(dir.path());
    }
    file_info_function_data_dat = dir.path() + "/" + name_files + "_function_data"
            + QDateTime::currentDateTime().toString("yyyyMMddHHmmss")+ ".dat"; //graficas
}
//-----------------------------------------------------------------------------------------------------------------------


//Esta funcion guarda informacion de paciente en archivos----------------------------
//-----------------------------------------------------------------------------------------------------------------------
bool PacientClass::write_file(){ //escribir datos de paciente en dat
    QJsonDocument d;
    d.setObject(jsonObjectPacient);
    QFile *data_base = new QFile(file_info_log_name_dat); // ficheros .dat se puede usar para cargar despues

    if(data_base->open(QIODevice::WriteOnly))
    {
        QDataStream out(data_base);
        out << d.toJson(QJsonDocument::Compact);
        data_base->close();
        return true;
    }
    return false;
}
bool PacientClass::write_LOG_parameters_in_DAT_file(QString parameters){ //escribir parametros en fichero dat
    QFile *data_base = new QFile(file_info_log_name_data_dat); // ficheros .dat se puede usar para cargar despues

    if(data_base->open(QIODevice::Append))
    {
        QDataStream out(data_base);
        out << parameters;
        data_base->close();
        return true;
    }
    return false;
}

bool PacientClass::write_file_function_data(double *data, int size){ //escribir datos de funcion de presion
    QFile *data_base = new QFile(file_info_function_data_dat); // ficheros .dat se puede usar para cargar despues
    if(data_base->open(QIODevice::Append))
    {
        QDataStream out(data_base);
        for (int i=0; i< size; i++) {
            out << data[i];
        }
        data_base->close();
        return true;
    }
    return false;
}
bool PacientClass::write_file_log(){ //escribir informacion de paciente
    QFile *data_base = new QFile(file_info_log_name_txt); // ficheros .txt se puede usar para visualizar log

    if(data_base->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QString file_text = QString::fromLatin1(data_base->read(100));

        data_base->seek(0);
        data_base->write(QString("Nombre : " + jsonObjectPacient.value(nombre_key).toString() +  "\n").toUtf8());
        data_base->write(QString("Edad : " + jsonObjectPacient.value(edad_key).toString()+ "\n").toLatin1());

        data_base->write(QString("ID : " + jsonObjectPacient.value(ID_key).toString().toLatin1() + "\n").toLatin1());
        data_base->write(QString("Sexo : " + jsonObjectPacient.value(sexo_key).toString()+ "\n").toLatin1());
        //        data_base->write(QString("Estado : " + jsonObjectPacient.value(estado_key).toString()+ "\n").toLatin1());
        data_base->write(QString("Peso : " + jsonObjectPacient.value(weight_key).toString()+ "\n").toLatin1());
        data_base->write(QString("Estatura : " + jsonObjectPacient.value(height_key).toString()+ "\n").toLatin1());

        if(!file_text.contains("Fecha inicio")){
            data_base->write(QString("Fecha inicio : " + jsonObjectPacient.value(date_key).toString()+ "\n").toLatin1());
            data_base->write(QString("Hora inicio : " + jsonObjectPacient.value(time_key).toString()+ "\n").toLatin1());
        }
        data_base->write(QString("Comentarios : " + jsonObjectPacient.value(comentarios_key).toString()+ "\n").toLatin1());

        data_base->write(QString("\n").toLatin1());

        data_base->close();
        return true;
    }
    return false;
}
bool PacientClass::write_LOG(QString log){ //escribir log
    log.prepend("\n\n");
    QFile *data_base = new QFile(file_info_log_name_txt); // ficheros .txt se puede usar para visualizar log
    if(data_base->open(QIODevice::Append | QIODevice::Text))
    {
        data_base->write(log.toLatin1());
        data_base->close();
        return true;
    }
    return false;
}


//-----------------------------------------------------------------------------------------------------------------------
//Esta funcion guarda datos de respiracion de paciente en archivos----------------------------
////-----------------------------------------------------------------------------------------------------------------------
//bool PacientClass::write_file_Respiracion(QJsonObject jsonObject){
//    jsonObjectRespiracion = jsonObject;
//    QFile *data_base = new QFile(file_info_log_name_txt); // ficheros .dat se puede utilizar formato txt tambien
//    if(data_base->exists()) {
//        if(data_base->open(QIODevice::Append))
//        {
//            data_base->seek(0);
//            QDataStream out(data_base);
//            data_base->close();
//            return true;
//        }
//    }
//    return false;
//}
//-----------------------------------------------------------------------------------------------------------------------


//Esta funcion carga informacion de paciente de un archivo--------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
QJsonObject PacientClass::read_file(){
    QJsonObject jsonObject;
    QByteArray bytes;
    QJsonDocument d;
    QFile *data_base = new QFile(file_info_log_name_dat); // ficheros .dat se puede utilizar formato txt tambien
    if(data_base->exists()) {
        if(data_base->open(QIODevice::ReadOnly))
        {
            QDataStream in(data_base);
            in>>bytes;
            QJsonParseError error;
            d = d.fromJson(bytes, &error);
            if(!d.isEmpty()){
                if(d.isObject()){
                    jsonObject = d.object();
                }
            }
            data_base->close();

            operator_equal(jsonObject);
        }
    }
    return jsonObject;
}
QStringList PacientClass::read_LOG_parameters_in_DAT_file(){ //leer parametros en fichero dat
    QStringList logs= QStringList();
    QFile *data_base = new QFile(file_info_log_name_data_dat); // ficheros .dat se puede usar para cargar despues

    if(data_base->open(QIODevice::ReadOnly))
    {
        QDataStream in(data_base);
        QString log;
        while(!data_base->atEnd()){
            in>>log;
            if(!log.isEmpty()){
                logs.prepend(log);
            }
        }
        data_base->close();
    }
    return logs;
}
long long PacientClass::read_file_function_data(double *data, int size, long long pos){ //leer datos de funcion de presion
    long long pos_return=0;
    QFile *data_base = new QFile(file_info_function_data_dat); // ficheros .dat se puede usar para cargar despues
    if(data_base->open(QIODevice::ReadOnly))
    {
        data_base->seek(pos);
        QDataStream in(data_base);
        for (int i=0; i< size; i++) {
            in >> data[i];
        }
        pos_return = data_base->pos();
        data_base->close();
    }
    return pos_return;
}
//-----------------------------------------------------------------------------------------------------------------------



//Esta funcion imprime en consola datos de bebe-------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void PacientClass::print_pacient_data(){

    qDebug()<<"nombre paciente :  " + this->name_pacient;
    qDebug()<<"edad mama :  " + this->age_pacient;
    qDebug()<<"fecha inicio :  " + this->date_paciente.toString();
    qDebug()<<"hora hora :  " + this->time_paciente.toString();

    qDebug()<<"ID paciente:  " + this->ID;
    qDebug()<<"Estado paciente:  " + this->estado_paciente;
}
//-----------------------------------------------------------------------------------------------------------------------


//Esta funcion iguala dos objetos bebe-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void PacientClass::operator_equal(const PacientClass &other_pacient){

    ID = other_pacient.ID;
    sexo_paciente = other_pacient.sexo_paciente;
    estado_paciente = other_pacient.estado_paciente;

    this->name_pacient = other_pacient.name_pacient;
    this->age_pacient = other_pacient.age_pacient;

    weight = other_pacient.weight;
    height = other_pacient.height;

    comentarios = other_pacient.comentarios;

    time_paciente = other_pacient.time_paciente;
    date_paciente = other_pacient.date_paciente;

    birth_date_paciente = other_pacient.birth_date_paciente;

    has_name = other_pacient.has_name;

    jsonObjectPacient.insert(ID_key, ID);
    jsonObjectPacient.insert(nombre_key, name_pacient);
    jsonObjectPacient.insert(edad_key, age_pacient);
    jsonObjectPacient.insert(sexo_key, sexo_paciente);
    jsonObjectPacient.insert(birth_date_key, birth_date_paciente.toString());
    jsonObjectPacient.insert(weight_key, weight);
    jsonObjectPacient.insert(height_key, height);
    jsonObjectPacient.insert(date_key, date_paciente.toString(date_format));
    jsonObjectPacient.insert(time_key, time_paciente.toString(time_format));
    jsonObjectPacient.insert(estado_key, estado_paciente);
    jsonObjectPacient.insert(comentarios_key, comentarios);

    if(!this->name_pacient.isEmpty()){
        has_name = true;
        setFolderPacient();
        write_file_log();//log
        write_file(); //info de paciente en dat
    }
}
void PacientClass::operator_equal(QJsonObject jsonObject_pacient){

    ID = jsonObject_pacient.value(ID_key).toString();
    sexo_paciente = jsonObject_pacient.value(sexo_key).toString();
    estado_paciente = jsonObject_pacient.value(estado_key).toString();

    weight = jsonObject_pacient.value(weight_key).toString();
    height = jsonObject_pacient.value(height_key).toString();

    this->name_pacient = jsonObject_pacient.value(nombre_key).toString();
    this->age_pacient = jsonObject_pacient.value(edad_key).toString();

    time_paciente = QTime::fromString(jsonObject_pacient.value(time_key).toString(), time_format);
    date_paciente = QDate::fromString(jsonObject_pacient.value(date_key).toString(), date_format);

    comentarios = jsonObject_pacient.value(comentarios_key).toString();

    QString birth_d = jsonObject_pacient.value(birth_date_key).toString();

    jsonObjectPacient.insert(ID_key, ID);
    jsonObjectPacient.insert(nombre_key, name_pacient);
    jsonObjectPacient.insert(edad_key, age_pacient);
    jsonObjectPacient.insert(sexo_key, sexo_paciente);
    jsonObjectPacient.insert(weight_key, age_pacient);
    jsonObjectPacient.insert(height_key, sexo_paciente);
    jsonObjectPacient.insert(birth_date_key, birth_d);
    jsonObjectPacient.insert(date_key, date_paciente.toString(date_format));
    jsonObjectPacient.insert(time_key, time_paciente.toString(time_format));
    jsonObjectPacient.insert(estado_key, estado_paciente);
    jsonObjectPacient.insert(comentarios_key, comentarios);

    setFolderPacient();
}
//-----------------------------------------------------------------------------------------------------------------------


//Esta funcion me devuelve un booleano true si son dos bebes iguales-----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
bool PacientClass::is_equal(PacientClass &other_pacient){

    if(this->name_pacient == other_pacient.name_pacient && this->ID == other_pacient.ID)
        return true;
    else
        return false;
}
//-----------------------------------------------------------------------------------------------------------------------
