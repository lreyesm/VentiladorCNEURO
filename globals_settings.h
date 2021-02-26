#ifndef GLOBALS_SETTINGS_H
#define GLOBALS_SETTINGS_H

#include <QString>
#include <QColor>


static QString nombre_equipo = "PCUVENTE01";

static QString version_software = "1.2";

static QColor color_active_alarm = QColor(255,255,255); //QColor(243,100,100);
static QColor color_low_priority = QColor(254,147,20);
static QColor color_medium_priority = QColor(Qt::yellow);
static QColor color_high_priority = QColor(Qt::red);
static QColor color_alarm_notifications = QColor(Qt::white);
static QColor color_modo = QColor(135,220,98);
static QColor color_Vt = QColor(227,134,134);
static QColor color_Fr = QColor(255,222,89);
static QColor color_IE = QColor(194,153,209);
static QColor color_green_oxigen = QColor(156, 252, 129);

enum{none_priority, low_priority, medium_priority, high_priority};

enum{none_alarm = 0x00, presure_leak = 0x01, over_presure = 0x02, low_presure = 0x04, low_battery = 0x08,//HIGH_PRIORITY
     peep_range = 0x10, low_volumen = 0x20,raise_resistence = 0x40, low_battery_medium = 0x80,//MEDIUM_PRIORITY
     no_intern_battery = 0x100, pressure_error_measurement = 0x200, high_energy_consumption = 0x400,//MEDIUM_PRIORITY
     high_oxigen_level = 0x800, high_temperature = 0x1000, apnea_detected = 0x2000, oxygen_sensor_error = 0x4000,//MEDIUM_PRIORITY
     high_co2_level = 0x8000, co2_sensor_error = 0x10000, low_co2_level = 0x20000,//MEDIUM_PRIORITY
     no_extern_source = 0x100000, clock_error = 0x200000};//LOW_PRIORITY

static QString saved_configuration = "saved_configuration.dat";
static QString function_data_file = "function_data.dat";

static QString Pmax_key = "Pmax";
static QString Relacion_IE_key = "Relation_IE";
static QString BPM_key = "BPM";
static QString VolumenTidal_key = "VolumenTidal";
static QString ModoVentilacion_key = "ModoVentilacion";
static QString Tplat_key = "Tplat";
static QString Pmin_key = "Pmin";
static QString trigger_asistido_key = "trigger_asistido";
static QString t_plateau_key = "t_plateau";
static QString Ti_key = "Ti";
static QString FiO2_key = "FiO2";
static QString ETCO2_key = "ETCO2";
static QString EstadoAlarmas_key = "EstadoAlarmas";
static QString EstadoBocinas_key = "EstadoBocinas";
static QString date_time_key = "date_time";
static QString PEEP_key = "EstadoAlarmas";
static QString Ppla_key = "EstadoBocinas";
static QString PIP_key = "date_time";
static QString ventilationState_key = "ventilationState";
static QString capnographyState_key = "capnographyState";
static QString MAX_VOLUMEN_key = "MAX_VOLUMEN";
static QString formato_fecha_hora_log = "dd/MM/yyyy HH:mm:ss";

static bool myanimationEnabled = true;

#define VISUALIZATION_FREQUENCY 1 //mientras mas bajo mas actualizaciones (mas recursos y potencia) //ahora mismo en multiplos de 500ms

#define ALARM_ACTIVED 1

#define MUESTRAS_EN_GRAFICA 800
#define CICLOS_EN_GRAFICA 3
#define AMBU_SILICONA 800
#define MARK_4 700


#endif // GLOBALS_SETTINGS_H
