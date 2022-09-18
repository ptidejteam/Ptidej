/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_ogre4j_OverlayManager */

#ifndef _Included_org_ogre4j_OverlayManager
#define _Included_org_ogre4j_OverlayManager
#ifdef __cplusplus
extern "C" {
#endif
/* Inaccessible static: table */
/*
 * Class:     org_ogre4j_OverlayManager
 * Method:    destroy
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_ogre4j_OverlayManager_destroy
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     org_ogre4j_OverlayManager
 * Method:    destroyAll
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_org_ogre4j_OverlayManager_destroyAll
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_ogre4j_OverlayManager
 * Method:    getByName
 * Signature: (ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_OverlayManager_getByName
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     org_ogre4j_OverlayManager
 * Method:    getOverlayElement
 * Signature: (ILjava/lang/String;Z)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_OverlayManager_getOverlayElement
  (JNIEnv *, jclass, jint, jstring, jboolean);

/*
 * Class:     org_ogre4j_OverlayManager
 * Method:    getSingletonImpl
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_OverlayManager_getSingletonImpl
  (JNIEnv *, jclass);

/*
 * Class:     org_ogre4j_OverlayManager
 * Method:    getViewportHeight
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_OverlayManager_getViewportHeight
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_ogre4j_OverlayManager
 * Method:    getViewportWidth
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_OverlayManager_getViewportWidth
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif
#endif