#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
//#include "main.h"

#define MAXLINE 4096
#define BUFSIZE 1500



void err_doit (int errnoflag, int level, char *fmt, va_list ap);

void err_sys (char *fmt, ...);

char *icmpcode_v4(int code)
{
  switch (code) {
    case  0: return("network unreachable");
    case  1: return("host unreachable");
    case  2: return("protocol unreachable");
    case  3: return("port unreachable");
    case  4: return("fragmentation required but DF bit set");
    case  5: return("source route failed");
    case  6: return("destination network unknown");
    case  7: return("destination host unknown");
    case  8: return("source host isolated (obsolete)");
    case  9: return("destination network administratively prohibited");
    case 10: return("destination host administratively prohibited");
    case 11: return("network unreachable for TOS");
    case 12: return("host unreachable for TOS");
    case 13: return("communication administratively prohibited by filtering");
    case 14: return("host recedence violation");
    case 15: return("precedence cutoff in effect");
    default: return("[unknown code]");
  }
}
char *Sock_ntop_host(const struct sockaddr *sa, socklen_t salen);
void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);
int sock_cmp_addr(const struct sockaddr *sa1,
		  const struct sockaddr *sa2, socklen_t salen);
void tv_sub (struct timeval *out, struct timeval *in);
char *icmpcode_v4(int code);
//Sigfunc *Signal(int signo, Sigfunc *func);
void *Calloc(size_t n, size_t size);


void Gettimeofday(struct timeval *tv, void *foo);
void Pipe(int *fds);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Setsockopt(int fd, int level, int optname, const void *optval,
		socklen_t optlen);
void Sendto(int fd, const void *ptr, size_t nbytes, int flags,
	    const struct sockaddr *sa, socklen_t salen);
struct addrinfo *Host_serv(const char *host, const char *serv,
			   int family, int socktype);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Write(int fd, void *ptr, size_t nbytes);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
		 struct sockaddr *sa, socklen_t *salenptr);
