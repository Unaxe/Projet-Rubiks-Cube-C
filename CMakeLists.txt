cmake_minimum_required(VERSION 3.17)
project(ProjetC C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetC Services/main.c Services/rubiks.c Headers/rubiks.h Services/conio.c Headers/conio.h Headers/typedefs.h Services/enumTypesServices.c Headers/enumTypesServices.h Services/representationService.c Headers/representationService.h Services/movementsService.c Headers/movementsService.h Services/resolutionService.c Headers/resolutionService.h)