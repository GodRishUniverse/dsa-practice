for x in *.in; do echo ${x};  ./a.out <${x} | diff -w `basename ${x} .in`.ans -; done
