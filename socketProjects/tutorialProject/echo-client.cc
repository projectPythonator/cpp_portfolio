#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PORT 65432

int run_client() {
  int client_fd{0}, valread{0};
  struct sockaddr_in server_addr;
  char buffer[1024] = {0};
  char *message = "Hello from client";
  if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket failed on creation");
    return EXIT_FAILURE;
  }
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
    perror("address not supported");
    return EXIT_FAILURE;
  } 
  if (connect(client_fd, (struct sockaddr *) &server_addr, 
                                  sizeof(server_addr)) < 0) {
    perror("failed to connect");
    return EXIT_FAILURE;
  }
  send(client_fd, message, strlen(message), 0);
  printf("Hello message sent\n");
  valread = read(client_fd, buffer, 1024);
  printf("%s\n", buffer);
  return EXIT_SUCCESS;
}

int main() {
  int success_val = run_client();
  return success_val;
}
