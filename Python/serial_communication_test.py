import serial
import time

def communicate_with_mcu():
    # create the connection by setting up parameters
    ser = serial.Serial(
        port='some/port',
        baudrate=115200,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
    )
    
    try:
        ser.write("Read Voltage\n\r")
        
        time.sleep(0.1)
        
        if ser.in_waiting > 0:
            response = ser.readline().decode('utf-8').strip()
            voltage = float(response)
            
            print("Measured Voltage : {voltage}\n")
            
    finally:
        ser.close()