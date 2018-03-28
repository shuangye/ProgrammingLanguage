LOCAL_PATH                      := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE                    := osa
# LOCAL_MODULE_FILENAME         := osa                        # optional

LOCAL_CFLAGS                    := -DDEBUG -DOSA_MODULE_NAME='"$(LOCAL_MODULE)"'
LOCAL_CXXFLAGS                  := -DDEBUG -DOSA_MODULE_NAME='"$(LOCAL_MODULE)"'
LOCAL_CPPFLAGS                  := -DDEBUG -DOSA_MODULE_NAME='"$(LOCAL_MODULE)"'

LOCAL_C_INCLUDES                := ../../include
LOCAL_SRC_FILES                 := ../../src/osa.c ../../src/osa_datetime.c ../../src/osa_string.c
LOCAL_SRC_FILES                 += ../../src/log/osa_log.c
# LOCAL_SRC_FILES                 += ../../tests/main.c

# LOCAL_SHARED_LIBRARIES        := libxtract
LOCAL_LDLIBS                    += -lc -lm
LOCAL_LDLIBS                    += -llog    # enable Android local log system


# cmd-strip                     :=          # do NOT strip


# for shared lib:
include $(BUILD_SHARED_LIBRARY)

# for static lib:
# include $(BUILD_STATIC_LIBRARY)

# for executable:
# include $(BUILD_EXECUTABLE)
