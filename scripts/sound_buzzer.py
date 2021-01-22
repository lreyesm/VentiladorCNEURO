import RPi.GPIO as GPIO
import time

buzzer_pin = 2
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer_pin, GPIO.OUT)

def buzz(pitch, duration):  #pitch = frecuencia -- duration = tiempo de pulso
    
    period = 1.0 / pitch
    delay = period / 2
    cycles = int(duration * pitch)
    for i in range(cycles):
        GPIO.output(buzzer_pin, True)
        time.sleep(delay)
        GPIO.output(buzzer_pin, False)
        time.sleep(delay)

def buzz_pulse(pitch, duration):
    pitch_s = 262
    pitch = float(pitch_s)
    duration_s = 0.150
    duration = float(duration_s)
    buzz(pitch, duration)

def buzz_step_pulse(frec, duration):
    GPIO.output(buzzer_pin, True)  #150ms 1er pulso    
    time.sleep(duration)
    
def buzz_stop_pulse(duration):
    GPIO.output(buzzer_pin, False)  #150ms 1er pulso    
    time.sleep(duration)
   
while True:
    #---------------------------Primeros 3 bit secuence------------------
    buzz_step_pulse(262, 0.15) #150ms 1er pulso C4 = 262Hz   
    buzz_stop_pulse(0.12)#120ms 1ra pausa
    buzz_step_pulse(440, 0.15) #150ms 2do pulso A4 = 440Hz 
    buzz_stop_pulse(0.12)#120ms 2da pausa  
    buzz_step_pulse(349, 0.15) #150ms 3er pulso F4 = 349Hz   
    buzz_stop_pulse(0.39)#390ms 3ra pausa (larga) 
    #---------------------------Segundos 2 bit secuence------------------
    buzz_step_pulse(440, 0.15)  #150ms 1er pulso A4 = 440Hz  
    buzz_stop_pulse(0.12)#120ms 1ra pausa
    buzz_step_pulse(349, 0.15) #150ms 2do pulso F4 = 349Hz 
    buzz_stop_pulse(1.6)#390ms 2da pausa (larga)
    #---------------------------Luego de reinicia------------------
    

    
    
