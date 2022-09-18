/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_ogre4j_MeshManager */

#ifndef _Included_org_ogre4j_MeshManager
#define _Included_org_ogre4j_MeshManager
#ifdef __cplusplus
extern "C" {
#endif
/* Inaccessible static: table */
/*
 * Class:     org_ogre4j_MeshManager
 * Method:    _createManual
 * Signature: (Ljava/lang/String;Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager__1createManual
  (JNIEnv *, jclass, jstring, jstring, jint);

/*
 * Class:     org_ogre4j_MeshManager
 * Method:    _getByName
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager__1getByName
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_ogre4j_MeshManager
 * Method:    _load
 * Signature: (Ljava/lang/String;Ljava/lang/String;IIZZ)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager__1load
  (JNIEnv *, jclass, jstring, jstring, jint, jint, jboolean, jboolean);

/*
 * Class:     org_ogre4j_MeshManager
 * Method:    createCppInstance
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager_createCppInstance
  (JNIEnv *, jclass);

/*
 * Class:     org_ogre4j_MeshManager
 * Method:    createPlane
 * Signature: (ILjava/lang/String;Ljava/lang/String;FFFFFFIIZIFFFFFIIZZ)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager_createPlane__ILjava_lang_String_2Ljava_lang_String_2FFFFFFIIZIFFFFFIIZZ
  (JNIEnv *, jobject, jint, jstring, jstring, jfloat, jfloat, jfloat, jfloat, jfloat, jfloat, jint, jint, jboolean, jint, jfloat, jfloat, jfloat, jfloat, jfloat, jint, jint, jboolean, jboolean);

/*
 * Class:     org_ogre4j_MeshManager
 * Method:    createPlane
 * Signature: (Ljava/lang/String;Ljava/lang/String;IFFIIZIFFFFF)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager_createPlane__Ljava_lang_String_2Ljava_lang_String_2IFFIIZIFFFFF
  (JNIEnv *, jclass, jstring, jstring, jint, jfloat, jfloat, jint, jint, jboolean, jint, jfloat, jfloat, jfloat, jfloat, jfloat);

/*
 * Class:     org_ogre4j_MeshManager
 * Method:    createPlane
 * Signature: (Ljava/lang/String;Ljava/lang/String;IFFIIZIFFFFFIIZZ)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager_createPlane__Ljava_lang_String_2Ljava_lang_String_2IFFIIZIFFFFFIIZZ
  (JNIEnv *, jclass, jstring, jstring, jint, jfloat, jfloat, jint, jint, jboolean, jint, jfloat, jfloat, jfloat, jfloat, jfloat, jint, jint, jboolean, jboolean);

/*
 * Class:     org_ogre4j_MeshManager
 * Method:    getSingletonImpl
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_MeshManager_getSingletonImpl
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif