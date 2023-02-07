compile:
	g++ -Wall Queue.cpp -c
	g++ -Wall  Cipher.cpp -c
	g++ -Wall Queue.cpp Cipher.cpp  Project3.cpp -g -o project3.out

clean:
	rm *.o

run:
	./Project3.out
