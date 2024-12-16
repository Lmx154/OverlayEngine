#include <android_native_app_glue.h>
#include <android/log.h>
#include "openxr_program.h"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "HelloXR", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "HelloXR", __VA_ARGS__))

void android_main(struct android_app* state) {
    app_dummy(); // Prevent stripping of the glue code

    LOGI("Starting OpenXR Android App");

    OpenXRProgram xrProgram;

    if (xrProgram.CreateSession()) {
        LOGI("OpenXR session created successfully.");
    } else {
        LOGE("Failed to create OpenXR session.");
    }

    // Main loop
    int events;
    struct android_poll_source* source;
    while (true) {
        while (ALooper_pollAll(-1, nullptr, &events, (void**)&source) >= 0) {
            if (source) source->process(state, source);
            if (state->destroyRequested) return;
        }
    }

    xrProgram.Shutdown();
    LOGI("Exiting OpenXR App");
}
