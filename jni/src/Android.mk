LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
SDL_IMAGE_PATH := ../SDL_image
BULLET_PATH := ../bullet
GLM_PATH := ../glm
IMGUI_PATH := ../imgui

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
	$(LOCAL_PATH)/${SDL_IMAGE_PATH} \
	$(LOCAL_PATH)/${BULLET_PATH} \
	$(LOCAL_PATH)/${GLM_PATH} \
	$(LOCAL_PATH)/${IMGUI_PATH}

LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	${IMGUI_PATH}/imgui.cpp ${IMGUI_PATH}/imgui_draw.cpp ${IMGUI_PATH}/imgui_impl_sdl_gles.cpp \
	camera.cpp mesh.cpp model.cpp shader.cpp \
	models/cube.cpp models/ground.cpp models/skybox.cpp \
	shaders/standard.cpp shaders/skybox.cpp \
	main.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image Bullet

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
