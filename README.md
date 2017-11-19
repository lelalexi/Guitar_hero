# Guitar_hero
proyecto final para la materia Embebidos 

Definicion del protocolo:

Descripcion del mensaje:
<tamaño$tipo$payload>

Tipos mensaje:
//desde la guitarra
0 -> Enviar teclas: Envia un byte de los botones presionados en binario. El boton 1 sera el bit menos significativo)
  <tamaño$tipo$teclas>
1 -> Volumen: Envia un byte con el valor del volumen actual (valor entre 0 y 100, con step de 10)
  <tamaño$tipo$tvolumen>
2 -> Efecto_Pedalera: a futuro
//desde la raspberry
3 -> Multiplicador: Envio un byte con el numero de multiplicador ( X2,X3,X4 )
   <tamaño$tipo$multiplicador>
4 -> Victoria/Derrota : envio un numero que indican derrota o victoria (mientras el juego este en curso, no se envia este mensaje)
  <tamaño$tipo$VD>
5 -> Power_UP : envio la cantidad de leds a encender en la guitarra (de 0 a 4)
  <tamaño$tipo$power>



