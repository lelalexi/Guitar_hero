import pygame, sys
from pygame.locals import *

pygame.init()

WHITE = (255,255,255)

pygame.mixer.init()
pygame.mixer.music.load('pepe2.mp3')
pygame.mixer.music.play(-1,0.0)

BACKGROUND = pygame.display.set_mode((400,600), 0, 32)

redApretado = False
greenApretado = False
blueApretado = False

FPS= 15 #FRAMES PER SECOND
fpsClock = pygame.time.Clock()
cancion = []
tempo = 0
grabar = True
while grabar:
	tempo+=1
#	BACKGROUND.fill(WHITE)
	acorde = [False,False,False]
	greenApretado=False
	redApretado=False
	blueApretado=False
	for event in pygame.event.get():
		if event.type == KEYDOWN:
			if event.key ==K_z:
				greenApretado= True
			if event.key==K_x:
				redApretado=True
			if event.key == K_c:
				blueApretado=True
			if event.key == K_q:
				pygame.mixer.music.stop()
				grabar=False
		if event.type == KEYUP:
			if event.key ==K_z:
				greenApretado= False
			if event.key==K_x:
				redApretado=False
			if event.key == K_c:
				blueApretado=False
	if greenApretado==True:
		acorde[0]=True
	if redApretado==True:
		acorde[1]=True
	if blueApretado==True:
		acorde[2]=True
	
	cancion.append(acorde)
	fpsClock.tick(FPS)
print(cancion)
#pygame.mixer.music.stop()