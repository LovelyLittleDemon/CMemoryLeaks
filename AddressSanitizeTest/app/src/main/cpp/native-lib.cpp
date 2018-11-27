#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_yinlib_sanitize_test_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    int a[2] = {1, 0};
    int b=a[2]; // out of bound
    return env->NewStringUTF(hello.c_str());
}
