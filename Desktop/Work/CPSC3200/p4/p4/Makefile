#MakeFile
p4: p4.o sequenceEnum.o seqExtract.o spasEnum.o inverter.o inVSeq.o
	g++ -o p4 p4.o sequenceEnum.o seqExtract.o spasEnum.o inverter.o inVSeq.o

p4.o: p4.cpp
	g++ -c -ansi -pedantic -Wall -Werror p4.cpp

sequenceEnum.o: sequenceEnum.cpp
	g++ -c -ansi -pedantic -Wall -Werror sequenceEnum.cpp

seqExtract.o: seqExtract.cpp
	g++ -c -ansi -pedantic -Wall -Werror seqExtract.cpp

spasEnum.o: spasEnum.cpp
	g++ -c -ansi -pedantic -Wall -Werror spasEnum.cpp

inverter.o: inverter.cpp
	g++ -c -ansi -pedantic -Wall -Werror inverter.cpp

inVSeq.o: inVSeq.cpp
	g++ -c -ansi -pedantic -Wall -Werror inVSeq.cpp

clean:
	rm *.o *~ p4


