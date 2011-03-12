CC = /usr/bin/g++
CHECK = /usr/bin/cppcheck
DOXYGEN = /usr/bin/doxygen
RM = /usr/bin/rm
CCCC = /usr/local/bin/cccc

all:

check:
	${CHECK} --xml ./ 2>cppcheck-result.xml
	
unit:
	${CC} *.cpp -o test.exe -lcppunit
	./test.exe
	
doc:
	${DOXYGEN}

cccc:
	${CCCC} *
	
clean:
	$(RM) -rf .cccc
	$(RM) -rf html
	$(RM) -rf *.exe*
	$(RM) -rf *.xml
	$(RM) -rf *.o