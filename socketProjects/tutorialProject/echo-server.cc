#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 65432

int run_server(){
  struct sockaddr_in address;
  int opt{1}, server_fd(0), client_socket(0), val_read(0);
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *message = "Hello from server";
  
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed on creation");
    return EXIT_FAILURE;
  }
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                      &opt, sizeof(opt))) {
    perror("setsockopt failed on call");
    return EXIT_FAILURE;
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  
  if (bind(server_fd, (struct sockaddr *) &address, sizeof(address))<0) {
    perror("bind failure");
    return EXIT_FAILURE;
  }
  if (listen(server_fd, 3) < 0){
    perror("listen failure");
    return EXIT_FAILURE;
  }
  if ((client_socket = accept(server_fd, (struct sockaddr *) &address, 
                                          (socklen_t*) &addrlen)) < 0) {
    perror("accept failure");
    return EXIT_FAILURE;
  }
  while ((val_read = read(client_socket, buffer, 1024))>0) {
    printf("%s\n", buffer);
    send(client_socket, message, strlen(message), 0);
    printf("hello message sent\n");
  }
  return EXIT_SUCCESS;
    
}

int main() {
  int success_val = run_server();
  return success_val;
}
