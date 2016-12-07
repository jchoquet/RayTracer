LINK_TARGET = PAP_rayon

OBJS = ProjetPAP.o

REBUILDABLES = $(OBS) $(LINK_TARGET)

clean :
	rm -f $(REBUILDABLES)
	echo Clean done

all : $(LINK_TARGET)
	echo All done
	
$(LINK_TARGET) : $(OBJS)
	g++ -g -o $@ $^

ProjetPAP.o : Scene.h
Scene.o : Scene.h Camera.h Shape.h Ray3f.h Material.h libpng.h Image.h
Camera.o : Camera.h Vector3f.h
Shape.o : Material.h Ray3f.h Shape.h 
Ray3f.o : Vector3f.h Ray3f.h
Material.o : Material.h
libpng.o : libpng.h Image.h Pixel.h
Image.o : Image.h Pixel.h
Vector3f.o : Pixel.h