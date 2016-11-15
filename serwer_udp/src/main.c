/************* UDP SERVER CODE *******************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include "moja_biblioteka.h"



int main() {
	float (*wsk_na_fun)(float a, float b);
	int udpSocket, nBytes;
	double buffer[1024];
	float numbers[3];
	char test[3];
	struct sockaddr_in serverAddr, clientAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size, client_addr_size;
	int i;

	/*Create UDP socket*/
	udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

	/*Configure settings in address struct*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("192.168.0.16");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	/*Bind socket with address struct*/
	bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	/*Initialize size variable to be used later on*/
	addr_size = sizeof serverStorage;
	double answer = 0;
	int stop = 0;

	while (1) {
		/* Try to receive any incoming UDP datagram. Address and port of
		 requesting client will be stored on serverStorage variable */
//		nBytes = recvfrom(udpSocket, buffer, 1024, 0,
//				(struct sockaddr *) &serverStorage, &addr_size);

		nBytes = recvfrom(udpSocket, buffer, sizeof(buffer), 0,
				(struct sockaddr *) &serverStorage, &addr_size);
		printf("Dziala\n");
		/*Convert message received to uppercase*/
		if (buffer[2] == 1.0) { //dodawanie
			printf("Dziala w ifie przed wskaznikiem na funkcje\n");
			wsk_na_fun = dodawanie;
			printf("Dziala po przypisaniu adresu funkcji do wskaznika\n");
			answer = wsk_na_fun(buffer[0], buffer[1]);
			printf("Dziala po zwroceniu wyniku do answer\n");
			printf("Dziala, bo wynik to %f\n",answer);
		}

		 else if (buffer[2] == 2.0) { //odejmowanie
			 printf("Gdy odejmowanie if\n");
			wsk_na_fun = odejmowanie;
			answer = wsk_na_fun(buffer[0], buffer[1]);
		} else if (buffer[2] == 3.0) { //mnozenie
			printf("Gdy mnozenie if\n");
			wsk_na_fun = mnozenie;
			answer = wsk_na_fun(buffer[0], buffer[1]);
		} else if (buffer[2] == 4.0) { //dzielenie
			printf("Gdy dzielenie if\n");
			wsk_na_fun = dzielenie;
			answer = wsk_na_fun(buffer[0], buffer[1]);
		} else {
			printf("Gdy else \n");
			answer = 0;
		}
//		for (i = 0; i < nBytes - 1; i++) {
//			buffer[i] = 2 * buffer[i];
//		}
		/*Send uppercase message back to client, using serverStorage as the address*/
//		sendto(udpSocket, buffer, nBytes, 0, (struct sockaddr *) &serverStorage,
//				addr_size);
		sendto(udpSocket, &answer, sizeof(answer), 0,
				(struct sockaddr *) &serverStorage, addr_size);
		stop = 1;
		printf("Dziala\n");

	}

	return 0;
}

//komenda:gcc -L/home/marcin/eclipse/nowy/serwer/src/ -Wall -o test serwer.c -lmoja_biblioteka
//z poziomu gdzie sie znajduje kod i biblioteka oraz ustawic LD_LIBRARY_PATH  i powinno isc
