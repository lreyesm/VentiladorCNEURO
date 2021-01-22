'''
Created on jul 7, 2017

@author: chamizo
'''
import os,sys
import commands

comando = "ps -ef | grep ventilador"
estado = str(commands.getoutput(comando)).split('\n')
est = 0
for i in range(0,len(estado)):
        if not "grep" in estado[i]:
                est = 1
#print est
if est == 0:
        comando1 = "sudo nice -n-20 ./Ventilador"
        commands.getoutput(comando1)
