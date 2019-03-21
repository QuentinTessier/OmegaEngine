/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Struct
*/

#pragma once

#define Struct_GetParent(MemberType, StructType)    \
        (StructType *)((char *)MemberType - offsetof(StructType, MemberType))

