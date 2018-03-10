# mqtt_mysql
Demostración de como almacenar datos publicados a un topico en mysql con python

En la carpeta nodemcu, se encuentra el codigo para cargar en el nodemcu. El esquema de conexion es sencillo, dado que es solo un ejemplo; es facilmente adaptable para publicar datos de sensores.

![alt text](https://raw.githubusercontent.com/gsampallo/mqtt_mysql/master/mqtt_mysql.png "Esquematico")

En la carpeta sql, se encuentra la estructura de la tabla.

En la carpeta python hay dos archivos:
SensorBase, establece la conexion con la base de datos y guarda los datos de lo que fue publicados
cliente_mqtt, establece la conexion con el servidor broker y ante la llegada de un mensaje crea una instancia de SensorBase y llama al metodo guardar.

