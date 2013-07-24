CC = g++ -g

CC_FLAG = -Wall

objs=ftp.o

server:$(objs)
	$(CC) $(CC_FLAG) -o ftp_server $(objs)

clean:
	rm ftp_server $(objs)
