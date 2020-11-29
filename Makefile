### 
## Makefile
## INFO2050: Projet 2
## RUSSE Cyril
## 
### 

## Variables

# Tools & flags
CC = gcc
CFLAGS = --std=c99 --pedantic -Wall -Wextra -Wmissing-prototypes -DNDEBUG 
LD = gcc

# Files
EXEC = probabilite

OBJECTS = main.c

## Rules

#compilation

make: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) -lm


#rapport
rapport:all_rapport clean_log_aux

all_rapport:
	cd ../rapport && pdflatex tad-RusseCyril.tex

clean_log_aux:
	cd ../rapport && rm -f tad-RusseCyril.aux tad-RusseCyril.log tad-RusseCyril.toc

clean_rapport: clean_log_aux
	cd ../rapport && rm -f tad-RusseCyril.pdf

#création archive
archive:
	cd .. && tar -zcvf demineur_01.tar.gz source rapport doc

#supp fichiers objets + executable
clean:
	rm -f *.o $(EXEC)