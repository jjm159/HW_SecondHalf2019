cc = g++

staticSRC= get.cpp put.cpp generateResultFile.cpp
staticOBJ= $(staticSRC:.cpp=.o)

static : test_static.cpp libkvs_static.a
	$(cc) -o test_static test_static.cpp libkvs_static.a

dll : test_dll.cpp libkvs_dll.so
	$(cc) -o test_dll test_dll.cpp -ldl libkvs_dll.so


libkvs_static.a: $(staticOBJ)
	ar rcs libkvs_static.a $(staticOBJ)

$(staticOBJ): $(staticSRC)
	$(cc) -c $(staticSRC)


libkvs_dll.so : $(staticOBJ) getObject.o
	$(cc) -shared -o libkvs_dll.so $(staticOBJ) getObject.cpp

clean :
	rm -f *.o *.so *.a test_dll test_static
