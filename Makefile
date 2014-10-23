HashTable:  Hash.o main.o
				g++ Hash.o main.o -o HashTable

Hash.o:		Hash.cpp
				g++ -c Hash.cpp -o Hash.o

main.o:		Hash.h main.cpp
				g++ -c main.cpp -o main.o

clean:		  
				rm -rf *.o HashTable

				
