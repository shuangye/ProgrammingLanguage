#include "papillon_CppInterface.h"
#include "func.h"


JNIEXPORT jint JNICALL Java_papillon_CppInterface_passStruct
(JNIEnv* env, jclass _jclazz, jobject jRect)
{
    jclass clazz;
    jfieldID fid;
    SV_Rect cRect;     /* C struct */

    // clazz = env->FindClass("papillon/Rect");
    clazz = (*env)->GetObjectClass(env, jRect);
    if (0 == clazz) {
        printf("GetObjectClass returned 0\n");
        return (-1);
    }

    fid = (*env)->GetFieldID(env, clazz, "x", "I");
    cRect.x = (*env)->GetIntField(env, jRect, fid);   /* get */
    printf("Rect from Java: x %d.\n", cRect.x);
    (*env)->SetIntField(env, jRect, fid, 12);         /* modify */

    return __LINE__;
}


JNIEXPORT jint JNICALL Java_papillon_CppInterface_passOutputPointer
  (JNIEnv *env, jclass _jclass, jintArray outValue)
{
    int value = 0;    
    (*env)->GetIntArrayRegion(env, outValue, 0, 1, &value);
    printf("%s: got int value from Java is %d.\n", __func__, value);

    value = 9999999;
    (*env)->SetIntArrayRegion(env, outValue, 0, 1, &value);
    return __LINE__;
}


JNIEXPORT jint JNICALL Java_papillon_CppInterface_passString
  (JNIEnv *env, jclass _jclass, jstring str)
{
    const char *cStr = (*env)->GetStringUTFChars(env, str, 0);
    printf("%s: string from Java = %s\n", __func__, cStr);
    env->ReleaseStringUTFChars(str, cStr); 
    return __LINE__;
}


JNIEXPORT jint JNICALL Java_papillon_CppInterface_passMemory
  (JNIEnv *env, jclass _jclass, jbyteArray memory)
{
    size_t i;
    unsigned char *rawMemory = (*env)->GetByteArrayElements(env, memory, 0);
    size_t length = (*env)->GetArrayLength(env, memory);

    printf("%s: memory value:\n", __func__);
    for (i = 0; i < length; ++i) {
        printf("%c", rawMemory[i]);
    }
    putchar('\n');
    return __LINE__;
}




#ifdef REF


/*

public native static int stringTest(int i, String ts);//测试传递一个字符串 

public native static int otestTest(int i, otest ts); //测试传递一个对象,对应c得结构体 

public native static int bytesTest(int len,byte[] t); //测试传递一个数组 


class otest { 
    public int j; 
    public static String t; 
    public byte[] abyte; 
} 


*/



//otestTest
JNIEXPORT jint JNICALL Java_helli_JniTest_otestTest
(JNIEnv* env, jclass clazc, jint jint, jobject obj)
{
	jclass clazz = env->FindClass("helli/otest");

//取int j

	jfieldID j = env->GetFieldID(clazz, "j", "I");

	if (j == 0)
		return 0;

	int intFieldVal = env->GetIntField(obj, j);

//取string t
	jfieldID t = env->GetStaticFieldID(clazz, "t", "Ljava/lang/String;");
	if (t == 0)
		return 1;

	jstring jstr = (jstring) env->GetStaticObjectField(clazz, t);
	const char* str = (jstr == 0) ? 0 : env->GetStringUTFChars(jstr, 0);

//取byte[] abyte
	jfieldID arrFieldId = env->GetFieldID(clazz, "abyte", "[B");
	if (arrFieldId == 0)
		return 0;

	jbyteArray jarr = (jbyteArray) env->GetObjectField(obj, arrFieldId);
	jbyte* arr = env->GetByteArrayElements(jarr, 0);

	char* c = (char*)arr;
	add_0(c, 4); //给byte数组加'/0'
	printf("receive bytes string is %s/n", c);

// Set new values
	env->SetIntField(obj, j, 888);
	const char* cc = "string ok";
	env->SetStaticObjectField(clazz, t, env->NewStringUTF(cc));

	arr = (jbyte*)cc;
	env->SetByteArrayRegion(jarr, 0, 8, arr);

	return jint + 5;
}


//stringTest
JNIEXPORT jint JNICALL Java_helli_JniTest_stringTest
(JNIEnv* env, jclass, jint j, jstring js)
{

/* 这里解释一点,注意函数名必须对应你javah生产得函数名,helli对应得是java得package,JniTest对应得是使
	用这个函数得java累, jclass默认对应得也就是这个类, JNIEnv传递得是一个java得环境, jclass对应得就是函数
   名后得JNITest, 后面得才是所有本地方法需要传递得数据
*/
	const char* str = (js == 0) ? 0 : env->GetStringUTFChars(js, 0);
	const char* t = "朱磊";
	printf("this in put is int of:%d--%s/n", j, t);
	return j + 2;
}


//bytesTest
JNIEXPORT jint JNICALL Java_helli_JniTest_bytesTest
(JNIEnv* env, jclass clazz, jint len, jbyteArray jarr)
{
	jbyte* arr = env->GetByteArrayElements(jarr, 0);
	char* c = (char*)arr;
	add_0(c, len);
	printf("%s/n", c);
	return j;

}

//给字符串加/0

void add_0(char* c, int len)
{
	for (int i = 0; i < len; i++)
		*c++;
	*c++ = '/0';
}

#endif

