// demo.c
#include "contiki.h" 
#include "sys/etimer.h" //etimer Event Timer
#include "mytemp.h"
#include <stdio.h>

PROCESS(sensor_process, "Sensor process");
AUTOSTART_PROCESSES(&sensor_process);

static struct etimer timer;
PROCESS_THREAD(sensor_process,ev, data)
{
PROCESS_BEGIN ();
printf("Native Sensor\n");
while(1){
etimer_set(&timer, CLOCK_SECOND*2);
PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));

struct Sensor temp = read_temperature();
printf("%s: %.2f\n", temp.name, (double)temp.value);

struct Sensor hum = read_humidity();
printf("%s: %.2f\n", hum.name, (double)hum.value);

struct Sensor pressure=read_pressure();
printf("%s: %.2f\n", pressure.name, (double)pressure.value);

printf("********************\n");
}
PROCESS_END();
}
