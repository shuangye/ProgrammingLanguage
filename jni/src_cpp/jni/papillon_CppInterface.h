/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class papillon_CppInterface */

#ifndef _Included_papillon_CppInterface
#define _Included_papillon_CppInterface
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     papillon_CppInterface
 * Method:    passStruct
 * Signature: (Lpapillon/Rect;)I
 */
JNIEXPORT jint JNICALL Java_papillon_CppInterface_passStruct
  (JNIEnv *, jclass, jobject);

/*
 * Class:     papillon_CppInterface
 * Method:    passOutputPointer
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_papillon_CppInterface_passOutputPointer
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     papillon_CppInterface
 * Method:    passString
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_papillon_CppInterface_passString
  (JNIEnv *, jclass, jstring);

/*
 * Class:     papillon_CppInterface
 * Method:    passMemory
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_papillon_CppInterface_passMemory
  (JNIEnv *, jclass, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
