cmake_minimum_required(VERSION 3.17)
project(ProjetC C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetC main.c rubiks.c rubiks.h conio.c conio.h typedefs.h enumTypesServices.c enumTypesServices.h representationService.c representationService.h movementsService.c movementsService.h resolutionService.c resolutionService.h)