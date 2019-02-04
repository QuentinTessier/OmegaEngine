/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** main
*/

#include "Application.h"

int main()
{
    OmApp App = OmApp_new();

    App.CreateWindow(&App);
    App.Run(&App);
    App.Destroy(&App);
    return (0);
}