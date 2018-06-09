all : 
	gcc server_A.c -o server_A
	gcc client_A.c -o client_A
	gcc server_B.c -o server_B
	gcc client_B.c -o client_B

#.PHONY : clean

clean : 
	rm -rf *.o *~ server_A client_A server_B client_B
