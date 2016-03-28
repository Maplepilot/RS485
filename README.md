## RS485
  * Baud rate = 1Mbit/s
  * Connect both DE and RE to pin 8 on all master and slave devices.  
  * Buffer size tested: 10.


![](https://github.com/piliwilliam0306/RS485/blob/master/IMAG0085.jpg)

## Sequence
![](https://github.com/piliwilliam0306/RS485/blob/master/IMAG0086.jpg)

## Setting slave device address
  * #define slave (device number 1-8).

## Test procedure
  * run 485_test.cpp to publish command.
  * use rosbag to record all topics.

## Reference
  * http://www.microcontroller-project.com/rs485-communication-between-arduino-mega-and-arduino-pro-mini.html  
  * http://wiki.ros.org/rosbag/Tutorials/Recording%20and%20playing%20back%20data


