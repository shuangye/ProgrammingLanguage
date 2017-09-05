/*

Commands to generate the JNI headers:
cd java_cpp\src_java
"C:\Program Files\Java\jdk1.8.0_144\bin\javah.exe" -jn i -classpath . -d ../src_cpp/jni -v papillon.CppInterface

 */

package papillon;

public class CppInterface {
    static {
        System.loadLibrary("func");
    }	

	public static native int passStruct(Rect rect);

	public static native int passOutputPointer(int[] outValue);

	public static native int passString(String str);
		
	public static native int passMemory(byte[] memory);
}





