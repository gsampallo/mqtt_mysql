#gsampallo.com
import time
import mysql.connector
from mysql.connector import errorcode

class SensorBase(object):

	def __init__(self,topico,valor):
		self.topico = topico;
		self.valor = valor;

	def mostrar(self):
    		print(self.valor)        
    

	def guardar(self):
    
		config = {
	      'user': 'root',
	      'password': '',
	      'host': 'localhost',
	      'database': 'iot',
	      'raise_on_warnings': True,
	    }


		try:
			cnx = mysql.connector.connect(**config)
			cursor = cnx.cursor()
			add_registro = ("INSERT INTO `mqtt` (`fecha`, `topico`, `valor`) VALUES (now(), %s, %s)")
			data_registro = (self.topico,self.valor)
			cursor.execute(add_registro, data_registro)
			cnx.commit()
			cursor.close()
			cnx.close()
		except mysql.connector.Error as err:
  			print(err)
		else:
  			cnx.close()        