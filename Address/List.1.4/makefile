include scripts/Makefile


.PHONY : all mm mc clean

all : $(Target)

mm :
	cd main && $(MAKE)
	cd Tool && $(MAKE)
	cd Interface && $(MAKE)
	cd Function && $(MAKE)
	cd File && $(MAKE)

mc :
	cd main && $(MAKE) clean
	cd Tool && $(MAKE) clean
	cd Interface && $(MAKE) clean
	cd Function && $(MAKE) clean
	cd File && $(MAKE) clean

$(Target) : mm
	@$(CC) -o $(Target) $(Allobjs) 

clean : mc
	@rm -rf $(Targer) client

    
