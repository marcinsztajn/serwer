/************* UDP SERVER CODE *******************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main() {
	float (*wsk_na_fun)(float a,float b);
	int udpSocket, nBytes;
	char buffer[1024];
	float numbers[3];
	struct sockaddr_in serverAddr, clientAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size, client_addr_size;
	int i;

	/*Create UDP socket*/
	udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

	/*Configure settings in address struct*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("192.168.119.46");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	/*Bind socket with address struct*/
	bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	/*Initialize size variable to be used later on*/
	addr_size = sizeof serverStorage;
	float answer;

	while (1) {
		/* Try to receive any incoming UDP datagram. Address and port of
		 requesting client will be stored on serverStorage variable */
//		nBytes = recvfrom(udpSocket, buffer, 1024, 0,
//				(struct sockaddr *) &serverStorage, &addr_size);
		nBytes = recvfrom(udpSocket, numbers, 12, 0,
					(struct sockaddr *) &serverStorage, &addr_size);
		/*Convert message received to uppercase*/
		if(numbers[2]==1.0){//dodawanie
			wsk_na_fun = dodawanie;
			return wsk_na_fun(numbers[0],numbers[1]);

		}
		else if(numbers[2]==2.0){//odejmowanie
			wsk_na_fun = odejmowanie;
			answer = wsk_na_fun(numbers[0],numbers[1]);
		}
		else if(numbers[2]==3.0){//mnozenie
			wsk_na_fun = mnozenie;
			answer = wsk_na_fun(numbers[0],numbers[1]);
		}
		else if(numbers[3]==4.0){ //dzielenie
			wsk_na_fun = dzielenie;
			answer= wsk_na_fun(numbers[0],numbers[1]);
		}
		else{
			answer = 0;
		}

		//for (i = 0; i < nBytes - 1; i++)
			//buffer[i] = toupper(buffer[i]);
		/*Send uppercase message back to client, using serverStorage as the address*/
//		sendto(udpSocket, buffer, nBytes, 0, (struct sockaddr *) &serverStorage,
//				addr_size);
		sendto(udpSocket, &answer, sizeof(answer), 0, (struct sockaddr *) &serverStorage,
						addr_size);
	}

	return 0;
}
