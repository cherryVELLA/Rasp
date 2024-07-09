song : main.o sonic.o music.o
	gcc -o song main.o sonic.o music.o -lwiringPi
	
main.o : main.c
	gcc -c -o main.o main.c
	
sonic.o : uSonic.c
	gcc -c -o sonic.o uSonic.c
	
music.o : music.c
	gcc -c -o music.o music.c
