#include <iostream>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main(int argc, char** argv) 
{
	int i=0,e=0,l,ster,player,temp,end,wygrana,first,dir,gps,tryb,w,randm=0,otwarcia,v=0,koniec=13,intro;
	setlocale(LC_ALL,"");
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream mapa1,mapa2,mapa3;
	string plansza;
	string view[9];
	/*l0_m0_r0*/view[0]="================================SSSS========================SSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS|SSSSSSSSSSSSSSSSSS|SSSSSSSSSSSS====================SSSSSSSSSS========================SSSSSS============================SS================================";
	/*l0_m0_r1*/view[1]="================================SSSS========================HHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS|SSSSSSSSSSSSSSSSSS|HHHHHHSSSSSS====================HHHHHHSSSS========================HHHHSS============================HH================================";
	/*l1_m0_r0*/view[2]="================================HHHH========================SSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH|SSSSSSSSSSSSSSSSSS|SSSSSSHHHHHH====================SSSSSSHHHH========================SSSSHH============================SS================================";
	/*l1_m0_r1*/view[3]="================================HHHH========================HHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH|SSSSSSSSSSSSSSSSSS|HHHHHHHHHHHH====================HHHHHHHHHH========================HHHHHH============================HH================================";
	/*l0_m1_r1*/view[4]="================================SSSS========================HHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS|HHHHHHHHHHHHHHHHHH|HHHHHHSSSSSS====================HHHHHHSSSS========================HHHHSS============================HH================================";
	/*l1_m1_r0*/view[5]="================================HHHH========================SSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH|HHHHHHHHHHHHHHHHHH|SSSSSSHHHHHH====================SSSSSSHHHH========================SSSSHH============================SS================================";
	/*l1_m1_r1*/view[6]="================================HHHH========================HHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH====================HHHHHHHHHH========================HHHHHH============================HH================================";
    /*l0_m1_r0*/view[7]="================================SSSS========================SSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS|HHHHHHHHHHHHHHHHHH|SSSSSSSSSSSS====================SSSSSSSSSS========================SSSSSS============================SS================================";
	/*win*/view[8]="================================HHHH========================HHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH|HHHHHHLRLRLRHHHHHH|HHHHHHHHHHHH|HHHHHLRLRLRLRHHHHH|HHHHHHHHHHHH|HHHHLRLRLRLRLRHHHH|HHHHHHHHHHHH|HHHLRLRLRLRLRLRHHH|HHHHHHHHHHHH|HHHRLRLRLRLRLRLHHH|HHHHHHHHHHHH|HHHHRLRLRLRLRLHHHH|HHHHHHHHHHHH|HHHHHRLRLRLRLHHHHH|HHHHHHHHHHHH|HHHHHHRLRLRLHHHHHH|HHHHHHHHHHHH|HHHHHHHHHHHHHHHHHH|HHHHHHHHHHHH====================HHHHHHHHHH========================HHHHHH============================HH================================";

	string widok[9][512];
	while(v!=9)
	{
		i=0;
		while(i<512)
		{
			widok[v][i]=view[v].substr(i,1);
			i++;
		}
		v++;
	}
	do
	{
	intro=1;
	v=0;
	wygrana=0;
	ster=109;
	temp=0;
	first=1;
	dir=0;
	gps=1;
	tryb=0;
	otwarcia=0;
	w=1;
		system("cls");
		SetConsoleTextAttribute(hOut,3);
    	Sleep(100);
		cout<<"   _        _____    _____      _    _____   _       _   _______     _________ "<<endl;
		Sleep(100);
		cout<<"  | |      | ___ |  |  _  |    | |  |  _  |  \\\\     //  |  ____ \\   |___   ___|"<<endl;
		Sleep(100);
		cout<<"  | |      | | | |  | | | |    | |  | | | |   \\\\___//   | |    | |      | |    "<<endl;
		Sleep(100);
		cout<<"  | |      | |_| |  | |_| |_   | |  | |_| |    \\   /    | |    | |      | |    "<<endl;
		Sleep(100);
		cout<<"  | |      |  _  |  |  ___  |  | |  |  __ \\     | |     | |    | |      | |    "<<endl;
		Sleep(100);
		cout<<"  | |___   | | | |  | |___| |  | |  | |  \\ \\    | |     | |    | |      | |    "<<endl;
		Sleep(100);
		cout<<"  |_____|  |_| |_|  |_______|  |_|  |_|   \\_\\   |_|     |_|    |_|      |_|    "<<endl<<endl;
		Beep(200,400);
	do
	{	
		system("cls");
		SetConsoleTextAttribute(hOut,3);
		Sleep(100);
		SetConsoleTextAttribute(hOut,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		cout<<"\n                                    Emki's                                      \n";
		SetConsoleTextAttribute(hOut,11);
		cout<<"   _        _____    _____      _    _____   _       _   _______     _________ "<<endl;
		cout<<"  | |      | ___ |  |  _  |    | |  |  _  |  \\\\     //  |  ____ \\   |___   ___|"<<endl;
		cout<<"  | |      | | | |  | | | |    | |  | | | |   \\\\___//   | |    | |      | |    "<<endl;
		cout<<"  | |      | |_| |  | |_| |_   | |  | |_| |    \\   /    | |    | |      | |    "<<endl;
		cout<<"  | |      |  _  |  |  ___  |  | |  |  __ \\     | |     | |    | |      | |    "<<endl;
		cout<<"  | |___   | | | |  | |___| |  | |  | |  \\ \\    | |     | |    | |      | |    "<<endl;
		cout<<"  |_____|  |_| |_|  |_______|  |_|  |_|   \\_\\   |_|     |_|    |_|      |_|    "<<endl<<endl;
		SetConsoleTextAttribute(hOut,BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		cout<<"                                     2018                                       \n\n\n\n\n";
		SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if(intro==1)
		{
		Beep(500,200);
		Beep(600,200);
		Beep(700,200);
		Beep(700,600);
		intro=0;
		}
		if(tryb==-1)
		{
			tryb=2;
		}
		if(tryb==3)
		{
			tryb=0;
		}
	
		if(tryb==0)
		{
			cout<<"                                   > EASY <"<<endl;
		}
		else
		{
			cout<<"                                     EASY"<<endl;
		}

		if(tryb==1)
		{
			cout<<"                                  > NORMAL <"<<endl;
		}
		else
		{
			cout<<"                                    NORMAL"<<endl;
		}
		
		if(tryb==2)
		{
			cout<<"                                   > HARD <"<<endl;
		}
		else
		{
			cout<<"                                     HARD"<<endl;
		}
	
		ster=getch();
		if(ster==119)
		{
			tryb--;
			Beep(400,100);
		}
		if(ster==115)
		{
			tryb++;
			Beep(400,100);
		}
	}
	while(ster!=13);

	ster=0;
	l=0;
	
	srand(time(NULL));
	randm=rand()%3;

	switch(tryb)
	{
		case 0:
			otwarcia=1;
		break;
		case 1:
			otwarcia=5;
		break;
		case 2:
			otwarcia=1;
		break;
	}
	
	switch(randm)
	{
		case 0:
			mapa1.open("mapa1.txt");
			mapa1>>plansza;
			mapa1.close();
		break;
		case 1:
			mapa2.open("mapa2.txt");
			mapa2>>plansza;
			mapa2.close();
		break;
		case 2:
			mapa3.open("mapa3.txt");
			mapa3>>plansza;
			mapa3.close();
		break;
	}
	
	l=plansza.length();
	string tab[l];
	
	while(wygrana!=1)
	{
		if(v==8)
		{
			wygrana=1;
			break;
		}
		system("cls");
		i=0;
		if(gps==1)
		{
			if(otwarcia>0)
			{
				while(i!=l)
				{
					SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
					if(first==1)
					{
						tab[i]=plansza.substr(i,1);
						if(tab[i]=="^" || tab[i]=="<" || tab[i]=="V" || tab[i]==">")
						{
							player=i;
						}
						if(tab[i]=="X")
						{
							end=i;
						}
						if(tab[i]=="?")
						{
							tab[i]=" ";
						}
						//plansza.erase(0,0);
					}
						while(e==l/16)
						{
							cout<<endl;
							e=0;
						}
						if(e==0)
						{
							SetConsoleTextAttribute(hOut,0);
							cout<<"                       ";
						}
						if(tab[i]=="^" || tab[i]=="<" || tab[i]=="V" || tab[i]==">")
						{
							SetConsoleTextAttribute(hOut,2);
							player=i;
						}
						if(tab[i]=="X")
						{
							SetConsoleTextAttribute(hOut,FOREGROUND_RED);
							end=i;
						}
						if(tab[i]=="?")
						{
							SetConsoleTextAttribute(hOut,0);
							tab[i]=" ";
						}
						if(tab[i]=="+")
						{
							SetConsoleTextAttribute(hOut,6);
						}
						if(tab[i]=="=")
						{
							SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_RED);
						}
						cout<<tab[i];
						SetConsoleTextAttribute(hOut,0);
						e++;
						i++;
				}
				switch(tryb)
				{
					case 1:
						if(otwarcia>0)
						{
							otwarcia-=1;
						}
					break;
					case 2:
						otwarcia=0;
					break;
				}
			}
			else
			{
				SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"\n\n\n\n\n\n\n\n";
				cout<<"                                 * NO SIGNAL*";
				cout<<"\n\n\n\n\n\n\n\n";
			}
			if(tryb==1)
			{
				SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"\n\n                           Remaining map openings: "<<otwarcia;
			}
			SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"\n\n                        M - Close map / Esc - End game";
			SetConsoleTextAttribute(hOut,0);
			Beep(500,200);
		}
		else
		{
			Beep(100,200);
			switch(dir)
			{
				case 0: //gora
					if(tab[player-1]==" " && tab[player+1]==" " && tab[player-32]==" ") //l0_m0_r0
					{
						v=0;
					}
					if((tab[player-1]=="+" || tab[player-1]=="=") && tab[player+1]==" " && tab[player-32]==" ") //l1_m0_r0
					{
						v=2;
					}
					if((tab[player-1]=="+" || tab[player-1]=="=") && (tab[player+1]=="+" || tab[player+1]=="=") && tab[player-32]==" ") //l1_m0_r1
					{
						v=3;
					}
					if((tab[player-1]=="+" || tab[player-1]=="=") && (tab[player+1]=="+" || tab[player+1]=="=") && (tab[player-32]=="+" || tab[player-1]=="=")) //l1_m1_r1
					{
						v=6;
					}
					if(tab[player-1]==" " && (tab[player+1]=="+" || tab[player+1]=="=") && (tab[player-32]=="+" || tab[player-1]=="=")) //l0_m1_r1
					{
						v=4;
					}
					if(tab[player-1]==" " && (tab[player+1]=="+" || tab[player+1]=="=") && tab[player-32]==" ") //l0_m0_r1
					{
						v=1;
					}
					if((tab[player-1]=="+" || tab[player-1]=="=") && tab[player+1]==" " && (tab[player-32]=="+" || tab[player-32]=="=")) //l1_m1_r0
					{
						v=5;
					}
					if(tab[player-1]==" " && tab[player+1]==" " && (tab[player-32]=="+" || tab[player-32]=="=")) //l0_m1_r0
					{
						v=7;
					}
					if(tab[player-32]=="X")
					{
						v=8;
					}
				break;
				case 1: //prawo
					if(tab[player-32]==" " && tab[player+32]==" " && tab[player+1]==" ") //l0_m0_r0
					{
						v=0;
					}
					if((tab[player-32]=="+" || tab[player-32]=="=") && tab[player+32]==" " && tab[player+1]==" ") //l1_m0_r0
					{
						v=2;
					}
					if((tab[player-32]=="+" || tab[player-32]=="=") && (tab[player+32]=="+" || tab[player+32]=="=") && tab[player+1]==" ") //l1_m0_r1
					{
						v=3;
					}
					if((tab[player-32]=="+" || tab[player-32]=="=") && (tab[player+32]=="+" || tab[player+32]=="=") && (tab[player+1]=="+" || tab[player+1]=="=")) //l1_m1_r1
					{
						v=6;
					}
					if(tab[player-32]==" " && (tab[player+32]=="+" || tab[player+32]=="=") && (tab[player+1]=="+" || tab[player+1]=="=")) //l0_m1_r1
					{
						v=4;
					}
					if(tab[player-32]==" " && (tab[player+32]=="+" || tab[player+32]=="=") && tab[player+1]==" ") //l0_m0_r1
					{
						v=1;
					}
					if((tab[player-32]=="+" || tab[player-32]=="=") && tab[player+32]==" " && (tab[player+1]=="+" || tab[player+1]=="=")) //l1_m1_r0
					{
						v=5;
					}
					if(tab[player-32]==" " && tab[player+32]==" " && (tab[player+1]=="+" || tab[player+1]=="=")) //l0_m1_r0
					{
						v=7;
					}
					if(tab[player+1]=="X")
					{
						v=8;
					}
				break;
				case 2: //dol
					if(tab[player+1]==" " && tab[player-1]==" " && tab[player+32]==" ") //l0_m0_r0
					{
						v=0;
					}
					if((tab[player+1]=="+" || tab[player+1]=="=") && tab[player-1]==" " && tab[player+32]==" ") //l1_m0_r0
					{
						v=2;
					}
					if((tab[player+1]=="+" || tab[player+1]=="=") && (tab[player-1]=="+" || tab[player-1]=="=") && tab[player+32]==" ") //l1_m0_r1
					{
						v=3;
					}
					if((tab[player+1]=="+" || tab[player+1]=="=") && (tab[player-1]=="+" || tab[player-1]=="=") && (tab[player+32]=="+" || tab[player+32]=="=")) //l1_m1_r1
					{
						v=6;
					}
					if(tab[player+1]==" " && (tab[player-1]=="+" || tab[player-1]=="=") && (tab[player+32]=="+" || tab[player+32]=="=")) //l0_m1_r1
					{
						v=4;
					}
					if(tab[player+1]==" " && (tab[player-1]=="+" || tab[player-1]=="=") && tab[player+32]==" ") //l0_m0_r1
					{
						v=1;
					}
					if((tab[player+1]=="+" || tab[player+1]=="=") && tab[player-1]==" " && (tab[player+32]=="+" || tab[player+32]=="=")) //l1_m1_r0
					{
						v=5;
					}
					if(tab[player+1]==" " && tab[player-1]==" " && (tab[player+32]=="+" || tab[player+32]=="=")) //l0_m1_r0
					{
						v=7;
					}
					if(tab[player+32]=="X")
					{
						v=8;
					}
				break;
				case 3: //lewo
					if(tab[player+32]==" " && tab[player-32]==" " && tab[player-1]==" ") //l0_m0_r0
					{
						v=0;
					}
					if((tab[player+32]=="+" || tab[player+32]=="=") && tab[player-32]==" " && tab[player-1]==" ") //l1_m0_r0
					{
						v=2;
					}
					if((tab[player+32]=="+" || tab[player+32]=="=") && (tab[player-32]=="+" || tab[player-32]=="=") && tab[player-1]==" ") //l1_m0_r1
					{
						v=3;
					}
					if((tab[player+32]=="+" || tab[player+32]=="=") && (tab[player-32]=="+" || tab[player-32]=="=") && (tab[player-1]=="+" || tab[player-1]=="=")) //l1_m1_r1
					{
						v=6;
					}
					if(tab[player+32]==" " && (tab[player-32]=="+" || tab[player-32]=="=") && (tab[player-1]=="+" || tab[player-1]=="=")) //l0_m1_r1
					{
						v=4;
					}
					if(tab[player+32]==" " && (tab[player-32]=="+" || tab[player-32]=="=") && tab[player-1]==" ") //l0_m0_r1
					{
						v=1;
					}
					if((tab[player+32]=="+" || tab[player+32]=="=") && tab[player-32]==" " && (tab[player-1]=="+" || tab[player-1]=="=")) //l1_m1_r0
					{
						v=5;
					}
					if(tab[player+32]==" " && tab[player-32]==" " && (tab[player-1]=="+" || tab[player-1]=="=")) //l0_m1_r0
					{
						v=7;
					}
					if(tab[player-1]=="X")
					{
						v=8;
					}
				break;
			}
			i=0;
			while(i<l)
			{
				while(e==l/16)
				{
					cout<<endl;
					e=0;
				}
				if(e==0)
				{
					SetConsoleTextAttribute(hOut,0);
					cout<<"                       ";
				}
				if(widok[v][i]=="H")
				{
					SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
				}
				if(widok[v][i]=="S")
				{
					SetConsoleTextAttribute(hOut,0);
					widok[v][i]=" ";
				}
				if(widok[v][i]=="L" || widok[v][i]=="/")
				{
					SetConsoleTextAttribute(hOut,FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
					widok[v][i]="/";
				}
				if(widok[v][i]=="R" || widok[v][i]=="\\")
				{
					SetConsoleTextAttribute(hOut,FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
					widok[v][i]="\\";
				}
				if(widok[v][i]=="=")
				{
					SetConsoleTextAttribute(hOut,0x240);
				}
				if(widok[v][i]=="|")
				{
					SetConsoleTextAttribute(hOut,0x240);
				}
				cout<<widok[v][i];
				SetConsoleTextAttribute(hOut,0);
				e++;
				i++;
			}
			if(tryb==1)
			{
				SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout<<"\n\n                           Remaining map openings: "<<otwarcia;
			}
			SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"\n\n                        M - Close map / Esc - End game";
		}
		first=0;
		//sterowanie
		ster=getch();
		if(ster==109)
		{
			if(gps==1)
			{
				gps=0;
			}
			else
			{
				gps=1;
			}
		}
		if(ster==27)
		{
			wygrana=1;
		}
		if(gps==0)
		{
			switch(dir) //kierunek
			{
				case 0: //gora
				switch(ster)
				{
					case 119: //gora -32
						if(tab[player-32]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player-32;
							tab[player]="^";	
						}
					break;
					case 115: //dol +32
						if(tab[player+32]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player+32;
							tab[player]="^";	
						}	
					break;
					case 97: //lewo -1
						dir-=1;
					break;
					case 100: //prawo +1
						dir+=1;
					break;
				}
				break;
				case 1: //prawo
				switch(ster)
				{
					case 119: //gora +1
						if(tab[player+1]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player+1;
							tab[player]=">";	
						}
					break;
					case 115: //dol -1
						if(tab[player-1]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player-1;
							tab[player]=">";	
						}	
					break;
					case 97: //lewo -1
						dir-=1;
					break;
					case 100: //prawo +1
						dir+=1;	
					break;
				}	
				break;
				case 2: //dol
				switch(ster)
				{
					case 119: //gora +32
						if(tab[player+32]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player+32;
							tab[player]="V";	
						}
					break;
					case 115: //dol -32
						if(tab[player-32]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player-32;
							tab[player]="V";	
						}	
					break;
					case 97: //lewo -1
						dir-=1;
					break;
					case 100: //prawo +1
						dir+=1;	
					break;
				}	
				break;
				case 3: //lewo
				switch(ster)
				{
					case 119: //gora -1
						if(tab[player-1]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player-1;
							tab[player]="<";	
						}
					break;
					case 115: //dol +1
						if(tab[player+1]==" ")
						{
							temp=player;
							tab[player]=" ";
							player=player+1;
							tab[player]="<";	
						}	
					break;
					case 97: //lewo -1
						dir-=1;
					break;
					case 100: //prawo +1
						dir+=1;
					break;
				}
				break;
			}
			if(dir<0)
			{
				dir=3;
			}
			if(dir>3)
			{
				dir=0;
			}
			switch(dir)
			{
				case 0:
					tab[player]="^";
				break;
				case 1:
					tab[player]=">";
				break;
				case 2:
					tab[player]="V";
				break;
				case 3:
					tab[player]="<";
				break;
			}
		}
	}
	if(wygrana==1 && ster!=27)
	{
		Beep(700,200);
		Beep(500,200);
		Beep(800,200);
		Beep(800,200);
		SetConsoleTextAttribute(hOut,0x2);
		cout<<endl<<endl;
		i=0;
		while(i<17)
		{
			cout<<"=/";
			Sleep(60);
			i++;
		}
		cout<<" YOU WON! ";
		i=0;
		while(i<17)
		{
			cout<<"\\=";
			Sleep(60);
			i++;
		}
	}
	SetConsoleTextAttribute(hOut,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout<<"\n\n                          Do you want to try again?";
	cout<<"\n\n                              ENTER - Play again";
	cout<<"\n                                ESC - Quit";
	koniec=getch();
	}
	while(koniec==13);
	return 0;
}


