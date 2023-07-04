#include <ncurses.h> 
#include <time.h>
#include <stdlib.h> //Hola
#define KEY_ESC 27 
void main(){
	initscr();  
	WINDOW * intro = newwin(30,60,0,20);//VENTANA DE INTRODUCCION 
	WINDOW * gov = newwin(30,60,0,20);//VENTANA DE GAME OVER
	WINDOW * play = newwin(30,60,0,20);//VENTANA DE EL JUEGO
	WINDOW * dates =  newwin(30,60,0,20);//VENTANA DONDE SE LEE EL NOMBRE DE EL JUGADOR
	WINDOW * scores = newwin(30,60,0,20);//VENTANA DE LOS 5 MEJORES PUNTAJES
	WINDOW * selec = newwin(30,60,0,20);//VENTANA DE LA SELECCION
	int l, h, cont, c;
	int WHiLE=0;
	int i,j,densidad;
	int filas,columnas,points[5],puntu,assistant;
	filas=30;
	columnas=60;
	densidad=1;
	int cond1[filas][columnas];
	int cond2[filas][columnas];
	int matriz[filas][columnas];
	int Fparedes=densidad*8;
	densidad = filas*columnas*densidad/4;
	char name[50];
	if(has_colors()){//SI LA CONSOLA ADMITE LOS COLORES QUE INICIE CON LOS COLORES
	start_color();
	}
	init_pair(1,COLOR_YELLOW,COLOR_YELLOW);
	init_pair(2,COLOR_GREEN, COLOR_BLACK);
	init_pair(3,COLOR_BLACK,COLOR_BLACK);
	chtype letter = COLOR_PAIR(2) | A_NORMAL | A_BOLD;//TIPO DE DATOS QUE MANEJA ATTRIBUTOS
	
	box(intro,0,0);//INICIA CON LA VENTANA DE INTRODUCCION
	wrefresh(intro);
	wattron(intro,letter);
	//INICIA LO ESTETICO
	mvwprintw(intro ,30,50,"*" );//IMPRIME SNAKE Y DOS LINEAS 
	mvwprintw(intro ,29,51,"*" );
	mvwprintw(intro ,28,52,"*" );
	mvwprintw( intro,27,53,"*" );
	mvwprintw( intro,26,54,"*" );
	mvwprintw( intro,25,55,"*" );
	mvwprintw( intro,24,56,"*" );
	mvwprintw( intro,23,57,"*" );
	mvwprintw( intro,22,58,"*" );
	mvwprintw( intro,21,59,"*" );
	mvwprintw( intro,0,4,"*");
	mvwprintw(intro ,1,3,"*");
	mvwprintw(intro ,2,2,"*");
	mvwprintw(intro ,3,1,"*");
	mvwprintw(intro ,4,0,"*");
	mvwprintw(intro,2,18,"*");
	mvwprintw(intro,2,19,"*");
	mvwprintw(intro,2,20,"*");
	mvwprintw(intro,3,18,"*");
	mvwprintw(intro,4,18,"*");
	mvwprintw(intro,4,19,"*");
	mvwprintw(intro,4,20,"*");
	mvwprintw(intro,5,20,"*");
	mvwprintw(intro,6,20,"*");
	mvwprintw(intro,7,20,"*");
	mvwprintw(intro,7,19,"*");
	mvwprintw(intro,7,18,"*");
	mvwprintw(intro,2,22,"*");
	mvwprintw(intro,3,22,"*");
	mvwprintw(intro,4,22,"*");
	mvwprintw(intro,5,22,"*");
	mvwprintw(intro,6,22,"*");
	mvwprintw(intro,7,22,"*");
	mvwprintw(intro,3,23,"*");
	mvwprintw(intro,4,24,"*");
	mvwprintw(intro,5,25,"*");
	mvwprintw(intro,6,27,"*");
	mvwprintw(intro,7,27,"*");
	mvwprintw(intro,2,27,"*");
	mvwprintw(intro,3,27,"*");
	mvwprintw(intro,4,27,"*");
	mvwprintw(intro,5,27,"*");
	mvwprintw(intro,6,27,"*");
	mvwprintw(intro,2,29,"*");
	mvwprintw(intro,2,30,"*");
	mvwprintw(intro,2,31,"*");
	mvwprintw(intro,2,32,"*");
	mvwprintw(intro,3,29,"*");
	mvwprintw(intro,4,29,"*");
	mvwprintw(intro,5,29,"*");
	mvwprintw(intro,6,29,"*");
	mvwprintw(intro,7,29,"*");
	mvwprintw(intro,2,32,"*");
	mvwprintw(intro,3,32,"*");
	mvwprintw(intro,4,32,"*");
	mvwprintw(intro,5,32,"*");
	mvwprintw(intro,6,32,"*");
	mvwprintw(intro,7,32,"*");
	mvwprintw(intro,4,29,"*");
	mvwprintw(intro,4,30,"*");
	mvwprintw(intro,4,31,"*");
	mvwprintw(intro,2,34,"*");
	mvwprintw(intro,3,34,"*");
	mvwprintw(intro,4,34,"*");
	mvwprintw(intro,5,34,"*");
	mvwprintw(intro,6,34,"*");
	mvwprintw(intro,7,34,"*");
	mvwprintw(intro,2,37,"*");
	mvwprintw(intro,3,36,"*");
	mvwprintw(intro,4,35,"*");
	mvwprintw(intro,5,35,"*");
	mvwprintw(intro,6,36,"*");
	mvwprintw(intro,7,37,"*");
	mvwprintw(intro,2,39,"*");
	mvwprintw(intro,3,39,"*");
	mvwprintw(intro,4,39,"*");
	mvwprintw(intro,5,39,"*");
	mvwprintw(intro,6,39,"*");
	mvwprintw(intro,7,39,"*");
	mvwprintw(intro,2,40,"*");
	mvwprintw(intro,2,41,"*");
	mvwprintw(intro,2,42,"*");
	mvwprintw(intro,4,40,"*");
	mvwprintw(intro,4,41,"*");
	mvwprintw(intro,4,42,"*");
	mvwprintw(intro,7,40,"*");
	mvwprintw(intro,7,41,"*");
	mvwprintw(intro,7,42,"*");
	wattroff(intro,letter);
	//FIN DE LO ESTETICO
	mvwprintw(intro,12,17,"Hola este es mi programa !");
	mvwprintw(intro,16,18,"Omar Ramirez Hernandez 2B");
	mvwprintw(intro,18,21," RAMHER-GAMES Gg ");//RAMHER RAM-irez HER-nandez Gg GOOD GAME 
	mvwprintw(intro,20,18,"Press enter to start...");
	wattroff(intro,letter);
	wgetch(intro);
	box(play,0,0);
	keypad(play, TRUE);//ACTIVAMOS TECLAS ESPECIALES EN LA VENTANA DE EL JUEGO
	noecho();//lo ingresado no se mostrara en pantalla
	cbreak();//no requiere precionar enter
	//ETIQUETA EN CASO DE OTRO JUGADOR
	NewP:
		for(i=0;i<5;i++){
			points[i]=0;
		}
		assistant=0;
		puntu=0;//EN CEROS
	box(dates,0,0);//DONDE VA A INGRESAR SU NOMBRE
	echo();
	wattron(dates , letter);
	mvwprintw(dates ,0,4,"*");
	mvwprintw(dates ,1,3,"*");
	mvwprintw(dates ,2,2,"*");
	mvwprintw(dates ,3,1,"*");
	mvwprintw(dates ,4,0,"*");
	wattroff(dates , letter);
	mvwprintw(dates,10,10,"Ingresa tu nombre");
	mvwscanw(dates,14,10,"%s",&name);//LEYENDO EL NOMBRE
	wattron(dates , letter);
	mvwprintw(dates ,0,4,"*");
	mvwprintw(dates ,1,3,"*");
	mvwprintw(dates ,2,2,"*");
	mvwprintw(dates ,3,1,"*");
	mvwprintw(dates ,4,0,"*");
	wattroff(dates , letter);
	wclear(dates);
	noecho();
	box(dates,0,0);
	wattron(dates , letter);
	mvwprintw(dates ,0,4,"*");
	mvwprintw(dates ,1,3,"*");
	mvwprintw(dates ,2,2,"*");
	mvwprintw(dates ,3,1,"*");
	mvwprintw(dates ,4,0,"*");
	wattroff(dates , letter);
	mvwprintw(dates,10,10,"Bienvenid@ %s",name);//MENSAJE DE BIENVENIDA
	wgetch(dates);
	GAME://ETIQUETA DE EL JUEGO PRINCIPAL
	wattron(play,COLOR_PAIR(1));//ACTIVAMOS EL COLOR DE EL LABERINTO
	wrefresh(play);
	//laberinto
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){
			matriz[i][j]=0;
		}
	}
	for(i=0;i<filas;i++){
		// VALORES DE EL LABERINTO 1 - 0 
		for(j=0;j<columnas;j++){//PARA EL BORDE 
			  if( i==0 || j==0 || i == filas-1 || j == columnas-1 ) {
			  	matriz[i][j]=1;
			  }
			  else{
			  	matriz[i][j]=0;
			  }
		}
	}
	//VALORES 
	srand(time(NULL));//DEVUELVE UN NUMERO NUEVO
	for(i=0;i<densidad;i++){
		int x = rand() % (columnas-2);
		x=(x/2)*2;
		int y = rand() % (filas-2);//VALORES RANDOM
		y=(y/2)*2;
		matriz[y][x]=1;
		for(j=0;j<Fparedes; j++){
			int mx[4]={x ,x ,x+2 ,x-2};
			int my[4]={y+2 ,y-2 ,y ,y};
			int r= rand() % 4;
			if(matriz[my[r]][mx[r]]==0){
				matriz[my[r]][mx[r]]=1;
				matriz[my[r]+(y-my[r])/2][mx[r]+(x-mx[r])/2]=1;
			}
		}
}
	for(i=0;i<filas;i++){//IMRPIMIENDO EL LABERINTO EN BASE A SI SU VALOR ES 1 - 0 
		for(j=0;j<columnas;j++){
			if(matriz[i][j]==1){
				mvwprintw(play,i,j,"h");//AL ESTAR ACTIVADO TANTO EL FONDO COMO LAS LETRAS DE COLOR AMARILLO, SE PINTA UNA ESPECIE DE PARED
			}
			else if(matriz[i][j]==0){
				mvwprintw(play,i,j,"\0");//IMRPIME UN ESPACIO
			}
		}
	}   
	for(i=0;i<filas;i++){//RELLENAMOS VALORES DE LOS CONDICIONALES
		for(j=0;j<columnas;j++){
			cond1[i][j]=-1;
			cond2[i][j]=-1;		
			}
	}   
	wattroff(play,COLOR_PAIR(1));//DESACTIVAMOS COLOR DE EL LABERITNO
	for(i=0;i<filas;i++){
		for(j=0;j<columnas;j++){//CONDICIONAL 
			if(matriz[i][j]==1){
				cond1[i][j]=i;//ARREGLO QUE GUARDA LAS POSICIONES DE FILAS
				cond2[i][j]=j;//ARREGLO QUE GUARDA LAS POSICIONES DE COLUMNAS
			}
			else{
				cond1[i][j]=-1;
				cond2[i][j]=-1;
			}
		}
	}
	keypad(play, TRUE);//ACTIVAMOS LAS TECLAS ESPECIALES 
	l = 1;
	h = 1;//VALORES INICIALES 
	cont=0;
	//EMPIEZA EL JUEGO
	wattron(play,letter);
	mvwprintw(play,l,h,"@");
	do{//REPETIR 
		c = wgetch(play);
		if(c==KEY_UP){//FLECHA ARRIBA
			l--;
			
			mvwprintw(play,(l+1),h,"*");
			mvwprintw(play,l,h,"@");
		}
		else if(c==KEY_DOWN){//FLECHA ABAJO
			l++;
		
			mvwprintw(play,(l-1),h,"*");
			mvwprintw(play,l,h,"@");
	
		}
		else if(c==KEY_LEFT){//IZQUIERDA
			h--;
			
			mvwprintw(play,l,(h+1),"*");
			mvwprintw(play,l,h,"@");
		}
		else if(c==KEY_RIGHT){//DERECHA
			h++;
			
			mvwprintw(play,l,(h-1),"*");
			
			mvwprintw(play,l,h,"@");
		}
		
		for(i=0;i<filas;i++){
			for(j=0;j<columnas;j++){//EVALUAMOS SI LA POSICION ES VALIDA O NO, SI NO ES VALIDA WHiLE ES IGUAL A 1 POR LO QUE EL BUCLE SE DEJA DE REPETIR
				if(cond1[i][j]==l && cond2[i][j]==h){
					wattroff(play,letter);
					WHiLE=1;
				}
			}
		}
		cond1[l][h]=l;
		cond2[l][h]=h;//EN CASO DE QUE LA POSICION SEA VALIDA AGREGA LA POSICION ACTUAL DE EL GUSANO COMO INVALIDA
		int x = rand()% filas-2;
		int y = rand()% columnas-2;
		int x2 = rand()% filas-2;
		int y2 = rand()% columnas-2;//2 FILAS Y 2 COLUMNAS AL AZAR
		for(i=0;i<filas;i++){
			for(j=0;j<columnas;j++){
				if(cond1[i][j]!=x && cond2[i][j]!=y){
					wattroff(play,letter);					
					wattron(play,COLOR_PAIR(1));
					mvwprintw(play,x,y,"W");
					wattroff(play,COLOR_PAIR(1));
					cond1[x][y]=x;
					cond2[x][y]=y;
					wattron(play,letter);
					break;
				}
				else{
					continue;
					x++;
					y++;
				}
			}
		}
		for(i=0;i<filas;i++){
			for(j=0;j<columnas;j++){
				if(cond1[i][j]!=x2 && cond2[i][j]!=y2){
					wattroff(play,letter);					
					wattron(play,COLOR_PAIR(1));
					mvwprintw(play,x2,y2,"W");
					wattroff(play,COLOR_PAIR(1));
					cond1[x2][y2]=x2;
					cond2[x2][y2]=y2;
					wattron(play,letter);
					break;
				}
				else{
					continue;
					x2++;
					y2++;
				}
			}
		}//PINTAMOS 2 CASILLAS NUEVAS POR CADA MOVIMIENTO EN BASE A VALORES AL AZAR
		cont++;//CONTADOR QUE NOS DARA LOS PUNTOS
    }while(WHiLE!=1);//MIENTRAS WHiLE SEA DIFERENTE A 1 SE REPETIRA EL BUCLE
    puntu=cont;//PUNTUACION ES IGUAL A EL NUMERO DE PUNTOS DE LA ANTERIOR PARTIDA 
    for(i=4;i>-1;i--){
		if(puntu>points[i]){//EVALUA QUE SI EL NUMERO DE PUNTOS ES MAYOR A EL PUESTO 5 DE LOS MEJORES PUNTAJES
			points[i]=puntu;
			break;
		}
	}
	for(i=0;i<5;i++){
		for(j=0; j<4;j++){//METOBO BURBUJA ORDENAMOS DE MAYOR A MENOR
			if(points[j+1]>points[j]){
				assistant=points[j];
				points[j]=points[j+1];
				points[j+1]=assistant;
			}
		}
	}
    wattroff(play,letter);
    	box(gov,0,0);//VENTANA DE GAME OVER
	wrefresh(gov);
	wattron(gov , letter);
	mvwprintw(gov ,0,4,"*");
	mvwprintw(gov ,1,3,"*");
	mvwprintw(gov ,2,2,"*");
	mvwprintw(gov ,3,1,"*");
	mvwprintw(gov ,4,0,"*");
	wattroff(gov , letter);
	mvwprintw(gov,4,20," Game over");
	mvwprintw(gov,8,22,"%s",name);
	mvwprintw(gov,10,20,"Gg Score: %d",cont);
	mvwprintw(gov,14,28,"...");//NOMBRE DEL JUGADOR Y SU PUNTAJE
	wgetch(gov);
	wclear(gov);
	keypad(selec, TRUE);
	noecho();
	cbreak();
	cuestion:
	box(selec,0,0);
	wattron(selec , letter);
	mvwprintw(selec ,0,4,"*");
	mvwprintw(selec ,1,3,"*");
	mvwprintw(selec ,2,2,"*");
	mvwprintw(selec ,3,1,"*");
	mvwprintw(selec ,4,0,"*");
	wattroff(selec , letter);
	mvwprintw(selec,4,20,"Que quieres hacer?");
	mvwprintw(selec,8,20,"Volver a jugar ");//8
	mvwprintw(selec,10,19,"Salir de el juego ");//10
	mvwprintw(selec,12,15,"Ver top 5 mejores puntajes");//12
	mvwprintw(selec,14,20,"Otro jugador");//14
	l=8;//DAMOS LAS OPCIONES DE SELECCION
	h=50;
	char k;
	do{
		 c =mvwgetch(selec,l,h);
		if(c==KEY_DOWN){
			l=l+2;
		if(l==16){//SI SE PASA DE 14 SE REGRESA A 8
			wattron(selec,COLOR_PAIR(3));
		 	mvwprintw(selec,14,h,"<<");
		 	wattroff(selec,COLOR_PAIR(3));
			l=8;
		}
		 	wattron(selec,COLOR_PAIR(3));
		 	mvwprintw(selec,l-2,h,"<<");
		 	wattroff(selec,COLOR_PAIR(3));
			wattron(selec,letter);
			mvwprintw(selec,l,h,"<<");
			wattroff(selec,letter);//IMPRIMIMOS Y REMPLAZAMOS 
		}
		if(c==KEY_UP){
			l=l-2;
			if(l==6){//SI BAJA MAS DE OCHO SE VA HASTA 14
			wattron(selec,COLOR_PAIR(3));
		 	mvwprintw(selec,8,h,"<<");
		 	wattroff(selec,COLOR_PAIR(3));
			l=14;
		}
		 	wattron(selec,COLOR_PAIR(3));
		 	mvwprintw(selec,l+2,h,"<<");
		 	wattroff(selec,COLOR_PAIR(3));
		 	wattron(selec,letter);
			mvwprintw(selec,l,h,"<<");
			wattroff(selec,letter);
		}
	}while(c == KEY_DOWN || c == KEY_UP || c==KEY_LEFT || c == KEY_RIGHT);//MIENTRAS EL USUARIO OPRIMA FLECHAS
	wclear(selec);
	if(l==8){//SI ELIJE VOLVER A JUGAR
		WHiLE=0;
		wclear(play);
		wclear(dates);
		wclear(selec);
		box(selec,0,0);
		wattron(selec , letter);
	mvwprintw(selec ,0,4,"*");
	mvwprintw(selec ,1,3,"*");
	mvwprintw(selec ,2,2,"*");
	mvwprintw(selec ,3,1,"*");
	mvwprintw(selec ,4,0,"*");
	wattroff(selec , letter);
 		mvwprintw(selec,2,20,"%s",name);		   
		mvwprintw(selec,4,20,"Estas listo?");
		mvwprintw(selec,6,20,"Press enter to continue");
		wgetch(selec);
		wclear(selec);
		goto GAME;
	}
	else if(l==12){//SI ELIJE VER LOS 5 MEJORES PUNTAJES
		box(scores,0,0);
		wmove(scores,2,10);
		mvwprintw(scores,2,22,"%s",name);
		for(i=0;i<20;i++){
			wprintw(scores,"-");
		}
		h=4;
		for(i=0;i<5;i++){
		mvwprintw(scores,h,10,"%d :%d",i+1,points[i]);
		h=h+2;
	}
	mvwprintw(scores,18,10,"Press enter to continue");
	wgetch(scores);
	goto cuestion;//REGRESAMOS A LA PREGUNTA
	}
	else if(l==14){//SI QUIERE JUGAR OTRA PERSONA
		wclear(play);
		wclear(selec);
		WHiLE=0;//REINICIAMOS EL VALOR PARA QUE EL BUCLE SE PUEDA VOLVER A REPETIR
		goto NewP;
	}
	else if(l==10){//SI ELIJE SALIR DEL JUEGO 
		printw("Gg!  Bye");
	}
	getch();
	endwin();//FIN DE NCURSES
	return;
}
