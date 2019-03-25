/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Log
*/

#pragma once

#include <stdarg.h>
#include <assert.h>

#define LOG_FILE "./engine/log/"

#define LOG_ERROR       "[\e[31mError\e[0m]: "
#define LOG_WARNING     "[\e[33mWarning\e[0m]: "
#define LOG_INFO        "[\e[90mInfo\e[0m]: "
#define LOG_SUCCESS     "[\e[32mSuccess\e[0m]: "

#define LOG_TO_CONSOLE  1
#define LOG_TO_FILE     0

enum Log_Tag {
    LTAG_NONE,
    LTAG_ERROR,
    LTAG_WARNING,
    LTAG_INFO,
    LTAG_SUCCESS
};

void OmLog_Log(int Tag, const char *format, ...);

#define OmLog_(Condition, Tag, Format, ...)                                         \
    if ((LOG_TO_CONSOLE || LOG_TO_FILE) && !(Condition)) {                          \
        OmLog_Log(Tag, Format, __VA_ARGS__);                                        \
        if (Tag == LTAG_ERROR || Tag == LTAG_WARNING)                               \
            assert(Condition);                                                      \
    }                                                                               \
    if (Tag == LTAG_ERROR)                                                          \
        assert(Condition);

#define ASSERT_TEST(x) assert(x)
