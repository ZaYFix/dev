JAVA = java
JAVAC = javac

MPACKAGE = western
MSRCPATH = ./src/$(MPACKAGE)
MBUILDPATH = ./build
MCLASSPATH = $(MBUILDPATH)

SRCFILES := $(wildcard $(MSRCPATH)/*.java)
CLASSFILES := $(patsubst $(MSRCPATH)/%.java, $(MBUILDPATH)/$(MPACKAGE)/%.class, $(SRCFILES))

.PHONY: clean

all: $(CLASSFILES)

$(CLASSFILES): $(SRCFILES)
	$(JAVAC) -d $(MBUILDPATH) -sourcepath $(MSRCPATH) -classpath $(MCLASSPATH) $^
histoire-1: $(CLASSFILES)
	(cd $(MBUILDPATH) && $(JAVA) -classpath . $(MPACKAGE).TestWestern1)
histoire-2: $(CLASSFILES)
	(cd $(MBUILDPATH) && $(JAVA) -classpath . $(MPACKAGE).TestWestern2)
clean:
	rm -f $(CLASSFILES) *~
