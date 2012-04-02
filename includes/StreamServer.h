#ifndef _STREAM_SERVER_H_
#define _STREAM_SERVER_H_

#define MAX_CLIENTS 5
#define SOCK_ERROR -1

#include "oscar.h"
#include "Hilaris.h"
#include "Camera.h"
#include "RawImage.h"

#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <sys/select.h>

#include <vector>


class StreamServer {
	public:
		StreamServer(Camera* camera);
		bool start();
		static void *sendData(void* arg);
		bool stop();
		bool insertImage(RawImage img);
		RawImage getImage();
		bool readable(int fd);
		bool writeable(int fd);
		
	private:
		pthread_t thread;
		pthread_mutex_t bufferLock;
		
		RawImage* imgBuffer;
		int startBuffer;
		int endBuffer;
		
		//int clients[MAX_CLIENTS];
		
		std::vector<int> clients;
		int connected;
		int srvSocket;
		struct  sockaddr_in addr;
		
		Camera* camera;
};

#endif 
