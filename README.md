# Temp-Humidity-sensing
*Temp-Humidity sensing and communicating data to Arduino UNO*

In this project, temperature and humidity is sensed using DHT11 sensor.
The DHT11 sensor is interfaced with NodeMCU, the temperature and humidity values are
communicated with Arduino UNO using I2C interface.


## master.ino
This file interfaces DHT11 with NodeMCU and then communicates the data with Arduino UNO

## slave.ino
This file receives the data sent by NodeMCU to Arduino UNO and prints the data on Serial monitor

## Circuit

![DHT11-NodeMCU connection](/NodeMCU-DHT11.png)

![NodeMCU-Arduino connection](/master-slave.png)
