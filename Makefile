hola.txt: album
	./album

album: album.cpp
	c++ album.cpp -o album

