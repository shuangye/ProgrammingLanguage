Commands to generate the JNI headers:
cd java_cpp\src_java
"C:\Program Files\Java\jdk1.8.0_144\bin\javah.exe" -jni -classpath . -d ../src_cpp/jni -v papillon.CppInterface



Generate shared lib:
cd project root
gcc -o libfunc.so -shared -fPIC src_cpp/func.c src_cpp/jni/papillon_CppInterface.c -Iinclude -I/usr/lib/jvm/default-java/include -I/usr/lib/jvm/default-java/include/linux 



Compile java files:
cd project root
javac src_java/papillon/*.java



Run java program:
cd project root
LD_LIBRARY_PATH=./ java -classpath ./src_java papillon.Main
