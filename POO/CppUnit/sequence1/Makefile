MAKE = make
SUBDIRS = src tests # indiquer ici les sous-répertoires
all:
	list='$(SUBDIRS)'; for subdir in $$list; do \
	echo "make all in $$subdir"; \
	(cd $$subdir && $(MAKE) $@) \
	done; 
	@echo ""
	@echo "Pour lancer les tests unitaires, executez : ./tests/testsUnitairesMesure"; 
	@echo ""
	@echo "Pour lancer le programme, executez : ./src/mesure"; 
	@echo ""

clean:
	list='$(SUBDIRS)'; for subdir in $$list; do \
	echo "make clean in $$subdir"; \
	(cd $$subdir && $(MAKE) $@) \
	done; 

cleanall:
	list='$(SUBDIRS)'; for subdir in $$list; do \
	echo "make clean in $$subdir"; \
	(cd $$subdir && $(MAKE) $@) \
	done; 
