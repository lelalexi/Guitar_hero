##hay que armar un objeto nota que contenga
	#color
	#posicion
	#tamaño

##notasSonando almacena obj notas que aparecen en pantalla
##notas alamacena la cancion, por lo tanto tiene todas las  notas que apareceran en la partida (True) o los silencios (False)

##en el while:
	#por cada tick vemos si debemos agregar una nota nueva a notasSonando.
 	#recorremos el notasSonando y las dibujamos en su correspondiente posicion
 	#chequeamos la 

import pygame, sys
from pygame.locals import *

class disco_nota:
	color= (0,0,0)
	posx = 0
	posy = 0

pygame.init()

BACKGROUND = pygame.display.set_mode((400,600), 0, 32)
pygame.display.set_caption('Guitar Hero')

FPS= 4 #FRAMES PER SECOND
fpsClock = pygame.time.Clock()

#set up the Colors
BLACK 	= (0,0,0)
WHITE 	= (255,255,255)
GREEN	= (0,255,0)
RED 	= (255,0,0)
BLUE 	= (0,0,255)
##YELLOW 	= ()
##ORANGE 	=

#pos ini 	[x,y] 	Discos
POSINIGREEN= 	(20,0)
POSINIRED = 	(80,0)
POSINIBLUE =	(140,0)

#aca se cargan las notas de una cancion
notas = ((True,True,True),(False,False,False),(False,False,False),(True,True,False),(False,False,False),(False,True,False),(False,False,False),(False,False,False),(True,False,True))
ritmo = 0	#indica que notas hay que cargar en el juego
notasSonando = []

while True:

	#GUI
	BACKGROUND.fill(WHITE)
	pygame.draw.line(BACKGROUND,BLACK, (20,0), (20,600), 4)
	pygame.draw.line(BACKGROUND,BLACK, (80,0), (80,600), 4)
	pygame.draw.line(BACKGROUND,BLACK, (140,0), (140,600), 4)
	
	#agregar notas
	if notas[ritmo][0] == True:
		nota = disco_nota()
		nota.color= GREEN
		nota.posx = POSINIGREEN[0]
		nota.posy = POSINIGREEN[1]
		notasSonando.append(nota)
		
	if notas[ritmo][1] == True:
		nota = disco_nota()
		nota.color= RED
		nota.posx = POSINIRED[0]
		nota.posy = POSINIRED[1]
		notasSonando.append(nota)
		
	if notas[ritmo][2] == True:
		nota = disco_nota()
		nota.color= BLUE
		nota.posx = POSINIBLUE[0]
		nota.posy = POSINIBLUE[1]
		notasSonando.append(nota)
	ritmo+=1
	if ritmo == len(notas):
		ritmo = 0


	#LOGICA DE MOVIMIENTO
	for nota in notasSonando:
		nota.posy += 20
		if nota.posy >= 620:
			nota.posy = 0
		pygame.draw.circle(BACKGROUND,nota.color, (nota.posx,nota.posy), 20, 0)

	pygame.draw.circle(BACKGROUND,GREEN, (20,580), 20, 4)
	pygame.draw.circle(BACKGROUND,RED, (80,580), 20, 4)
	pygame.draw.circle(BACKGROUND,BLUE, (140,580), 20, 4)

	for event in pygame.event.get():
		if event.type == KEYUP:
			if event.key ==K_z:

				ritmo= GREEN
			elif event.key==K_x:
				ritmo=RED
			elif event.key == K_c:
				ritmo=BLUE
		elif event.type == QUIT:
			pygame.quit()
			sys.quit()

	pygame.display.update()
	fpsClock.tick(FPS)	##siempre se llama luego del update()
