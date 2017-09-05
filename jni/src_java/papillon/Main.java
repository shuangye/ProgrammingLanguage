package papillon;

public class Main {
	 public static void main(String args[]) {
	 	int ret;

		/* pass rect */
        Rect rect = new Rect();		
		rect.x = 9;
        ret = CppInterface.passStruct(rect);
        System.out.println("CppInterface.passStruct returned " + ret + ". Rect.x = " + rect.x);

		/* pass pointer */
		int possibility[] = new int[1];
		possibility[0] = 255;
		ret = CppInterface.passOutputPointer(possibility);
		System.out.println("CppInterface.passOutputPointer returned " + ret + ". possibility = " + possibility[0]);

		/* pass string */
		String str = new String("Hello?");
		ret = CppInterface.passString(str);
		System.out.println("CppInterface.passString returned " + ret);

		/* pass memory block */
		byte memory[] = new byte[1024];
		for (int i = 0; i < memory.length; ++i) {
			memory[i] = (byte)('a' + (i % 26));
		}		
		ret = CppInterface.passMemory(memory);
		System.out.println("CppInterface.passMemory returned " + ret);
    }
}

