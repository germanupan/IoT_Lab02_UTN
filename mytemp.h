// mytemp.h
#ifndef MYTEMP_H
#define MYTEMP_H
struct Sensor {
 char name[15];
 float value;
};
struct Sensor read_temperature();
struct Sensor read_humidity();
struct Sensor read_pressure();
#endif
